// Includes for program
#include <Arduino.h>
#include <mcp2515.h>
#include "constants.h"

byte iso_checksum(byte *data, byte len)//len is the number of bytes (not the # of last byte)
{
  byte crc=0;
  for(byte i=0; i<len; i++)
  {    
    crc=crc^data[i];
  }
  return crc;
}

void sendKbus(HardwareSerial &refSer, byte *data) {
  int end_i = data[1]+2 ;
  data[end_i-1] = iso_checksum(data, end_i-1);
  refSer.write(data, end_i + 1);
}

// Function used to send all CAN messages
void CAN_Send(MCP2515 &can_bus, uint16_t address, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h){
  struct can_frame canMsg1;

  canMsg1.can_id  = address;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = a;
  canMsg1.data[1] = b;
  canMsg1.data[2] = c;
  canMsg1.data[3] = d;
  canMsg1.data[4] = e;
  canMsg1.data[5] = f;
  canMsg1.data[6] = g;
  canMsg1.data[7] = h;
  
  can_bus.sendMessage(&canMsg1);
}


// This function sets the tone frequency on the desired pin the correct value for the 
// user's desired speed value (in miles-per-hour)
void setSpeedometer(uint8_t speed_signal_pin, int speed_val) {
  /* 
   The minimum value 'tone()' can be sent is 31, which corresponds to a speed of 3.188 MPH
   To be conservative, we set the minimum settable speed at 4 MPH. In addition, the max
   displayable speed (where the arm on the speedometer ceases to move further) is about
   163 MPH, so this is what the cap is set to.
  */
  if(speed_val <= MIN_SPEED) {
    speed_val = MIN_SPEED;
  }
  else if(speed_val > MAX_SPEED) {
    speed_val = MAX_SPEED;
  }

  // Two linear functions to define the two ranges of relative linearity, and limiting the minimum value sent to 35
  float tone_freq;
  if (speed_val < 10) {
    tone_freq = 35;
  }
  else if(speed_val < 25) {
    // Refer to the generated lookup table
    tone_freq = 10.121 * speed_val - 4.823;
  }
  else {
    tone_freq = 10.787 * speed_val - 26.03;
  }

  //float tone_freq = 10.718 * speed_val - 3.1716;
  tone(speed_signal_pin, int(tone_freq));

}

void setRPM(MCP2515 &can_bus, int rpm_val) {
  // Threshold the RPM value
  if(rpm_val > MAX_RPM) {
    rpm_val = MAX_RPM;
  }
  else if(rpm_val < MIN_RPM) {
    rpm_val = MIN_RPM;
  }

  // Scale and offset the RPM value to convert to the value we send to the cluster
  int rpm_val_int = int(RPM_GAIN*rpm_val) + RPM_OFFSET;
  
  // Convert the rpm value to two 8-bit integers
  int rpm_lsb = rpm_val_int & 0x00FF;
  int rpm_msb = (rpm_val_int & 0xFF00) >> 8;

  // Setup the can message
  CAN_Send(can_bus, 0x316, 0, 0, rpm_lsb, rpm_msb, 0, 0, 0, 0);

}

void setTemp(MCP2515 &can_bus, int temp_val) {
  // Setting thersholds
  if(temp_val < MIN_TEMP) {
    temp_val = MIN_TEMP;
  }
  else if(temp_val > MAX_TEMP) {
    temp_val = MAX_TEMP;
  }

  // Convert the temperature from float to an int
  uint8_t temp_byte = temp_val + 48.373;
  
  // Setup the can message
  CAN_Send(can_bus, 0x329, 0x00, temp_byte, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
  
}

void setMPG(int mpg_val) {

  // Setup the can message
  //CAN_Send(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
  
}

// This may not be extremely accurate for now, but will work ok
void setFuel(uint8_t chip_select_pin, uint8_t fuel_percent) {
  // Threshold the fuel value
  if(fuel_percent > 100) {
    fuel_percent = 100;
  }
  else if(fuel_percent < 0) {
    fuel_percent = 0;
  }

  // Equation to convert from percentage to digi-pot value
  float digipot_val_f = -1.88 * fuel_percent + 205;
  uint8_t digipot_val_int = digipot_val_f;

  // Iterate through resistance values
  digitalWrite(chip_select_pin, LOW);
  SPI.transfer(0x00);
  SPI.transfer(digipot_val_int);
  digitalWrite(chip_select_pin, HIGH);
  //delay(100);

  digitalWrite(chip_select_pin, LOW);
  SPI.transfer(0x10);
  SPI.transfer(digipot_val_int);
  digitalWrite(chip_select_pin, HIGH);
}

// This functions handles illuminating all of the lights that are controlled over
// the KBUS (which inclues the 
void set_kbus_lights(HardwareSerial &refSer, byte *light_array1, byte *light_array2) {
  // Take the light arrays, and process them into the actual byte we will send
  byte LightByte1 = 0x00;
  byte LightByte2 = 0x00;
  
  for(int i = 0; i < 5; i++) {
    bool light1_val = light_array1[i];
    if(light1_val) {
      LightByte1 |= light1_val << (i+2);
    }
    else {
      LightByte1 &= ~(light1_val << (i+2));
    }

    bool light2_val = light_array2[i];
    if(light2_val) {
      LightByte2 |= light2_val << (i+2);
    }
    else {
      LightByte2 &= ~(light2_val << (i+2));
    }
  }

  // Handler the lit up car separately
  int car_light = light_array2[4];
  if(car_light) {
    LightByte2 |= 1 << 7;
  }
  else {
    LightByte2 &= ~(1 << 7);
  }
  
  // Define the arrays that actually get sent over the kbus
  byte light_array[] = {0xD0, 0x08, 0xBF, 0x5B, LightByte1, 0x00, 0x00, LightByte2, 0x00, 0x58, 0x00};
  sendKbus(refSer, light_array);
}

void set_status_lights1(MCP2515 &can_bus, int engine_light_state, int cruise_light_state, int EML_state, int gas_cap_light_state, int heat_light_state, int oil_light_state, int charge_light_state) {
  // Initialize status_byte
  uint8_t status1_byte = 0x00;
  
  // Reject false engine light inputs
  if(engine_light_state){
     status1_byte |= (1 << 1);
  }
  if(cruise_light_state) {
     status1_byte |= (1 << 3);
  }
  if(EML_state) {
     status1_byte |= (1 << 4);
  }
  if(gas_cap_light_state) {
     status1_byte |= (1 << 6);
  }
  
  int status_byte2 = (heat_light_state<<3)|(oil_light_state<<1);
  CAN_Send(can_bus, 0x545, status1_byte, 0x00, 0x00, status_byte2, 0x00, charge_light_state, 0x00, 0x00);
  
}

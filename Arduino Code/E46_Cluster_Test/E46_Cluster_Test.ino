// Includes for program
#include <SPI.h>
#include <mcp2515.h>
#include "constants.h"
#include "pin_definitions.h"

// C File Includes
#include "cluster_control_functions.h"

// Defines for program
#define DEBUG_VALUES false

// MCP2515 Instantiation
MCP2515 CAN(MCP2515_CS);

// Global variables that are changed in the main loop, and initializing certian states
uint8_t fuel_val;
uint8_t engine_start_feedback_state;
uint8_t signal_gong_state;
uint8_t bc_button_state;
uint8_t seat_belt_state;
uint8_t coolant_level_sensor_state;
uint8_t brake_wear_sensor_state;
uint8_t parking_brake_state;
uint8_t abs_warning_state;
uint8_t airbag_warning_state;
uint8_t brake_fluid_state;
int speed_val;
uint8_t oil_level_sensor_state;
uint8_t ignition_state;
uint8_t accessory_state;
uint8_t oil_pressure_switch_state;
uint8_t cluster_backlight_state;
uint8_t washer_fluid_level_state;
uint8_t rollover_sensor_state;
uint8_t reverse_state;

float rpm_val;
int temp_val;
int mpg_val;
int engine_light_state;
int cruise_light_state;
int EML_state;
int gas_cap_light_state;
int heat_light_state;
int charge_light_state;
int oil_light_state;
bool high_beam_state;
bool fog_rear_state;
bool fog_front_state;
bool left_blinker_state;
bool right_blinker_state;
bool back_right_light_state;
bool back_left_light_state;
bool front_right_light_state;
bool front_left_light_state;
bool car_light_state;
int battery_charge_val;
//byte light_array1[5];
//byte light_array2[5];

int fuel_consumption_val;
int rate_var;

void setup() {

  // Sensor Initialization
  accessory_state = 1;
  fuel_val = 50;
  coolant_level_sensor_state = 1;
  brake_wear_sensor_state = 1;
  parking_brake_state = 1;
  abs_warning_state = 1;
  brake_fluid_state = 1;
  temp_val = 275;
  

  // E46 Cluster Control Pin Setup
  pinMode(ENGINE_START_FEEDBACK_PIN, OUTPUT);
  pinMode(SIGNAL_GONG_PIN, OUTPUT);
  pinMode(BC_BUTTON_PIN, OUTPUT);
  pinMode(SEAT_BELT_PIN, OUTPUT);
  pinMode(COOLANT_LEVEL_SENSOR_PIN, OUTPUT);
  pinMode(BRAKE_WEAR_SENSOR_PIN, OUTPUT);
  pinMode(PARKING_BRAKE_PIN, OUTPUT);
  pinMode(ABS_WARNING_PIN, OUTPUT);
  pinMode(AIRBAG_WARNING_PIN, OUTPUT);
  pinMode(BRAKE_FLUID_PIN, OUTPUT);
  pinMode(SPEED_SIGNAL_PIN, OUTPUT);
  pinMode(OIL_LEVEL_SENSOR_PIN, OUTPUT);
  pinMode(IGNITION_ON_PIN, OUTPUT);
  pinMode(ACCESSORY_MODE_PIN, OUTPUT);
  pinMode(OIL_PRESSURE_SWITCH_PIN, OUTPUT);
  pinMode(BATTERY_CHARGE_INDICATOR_PIN, INPUT);
  pinMode(CLUSTER_BACKLIGHT_PIN, OUTPUT);
  pinMode(WASHER_FLUID_LEVEL_PIN, OUTPUT);
  pinMode(CRUISE_CONTROL_LIGHT_PIN, OUTPUT);
  pinMode(ROLLOVER_SENSOR_PIN, OUTPUT);
  pinMode(REVERSE_PIN, OUTPUT);

  // DIP Switches
  pinMode(DIP_SWITCH_1, INPUT);
  pinMode(DIP_SWITCH_2, INPUT);
  pinMode(DIP_SWITCH_3, INPUT);
  pinMode(DIP_SWITCH_4, INPUT);

  // SPI Pin Declarations
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, INPUT);
  pinMode(SCK_PIN, OUTPUT);
  pinMode(MCP2515_CS, OUTPUT);
  pinMode(DIGI_POT_CS, OUTPUT);

  // Set SPI Select pins low to start
  digitalWrite(MCP2515_CS, HIGH);
  digitalWrite(DIGI_POT_CS, HIGH);

  // Setup SPI for communication
  SPI.begin();
  
  // Configuring kbus communication
  KBUS.begin(9600, SERIAL_8E1);

  // Serial Debug Communication
  Serial.begin(9600);
  
  // MCP2515 Initialization
  CAN.reset();
  CAN.setBitrate(CAN_500KBPS, MCP_16MHZ);
  CAN.setNormalMode();
}

// Loop counter to make the kbus transactions happen much less frequently than everything else updates
int loopCounter = 0;

void loop() {
  // Setup the serial monitor to inject values into the program
  if(Serial.available()) {
    String data_type = Serial.readStringUntil(':');

    if(data_type == "speed") {
      String arg_str = Serial.readStringUntil('\n');
      speed_val = arg_str.toInt();
    }
    else if(data_type == "rpm") {
      String arg_str = Serial.readStringUntil('\n');
      rpm_val = arg_str.toInt();
    }
    else if(data_type == "temp") {
      String arg_str = Serial.readStringUntil('\n');
      temp_val = arg_str.toInt();
    }
    else if (data_type == "ignition") {
      String arg_str = Serial.readStringUntil('\n');
      ignition_state = arg_str.toInt();
    }
    else if (data_type == "accessory") {
      String arg_str = Serial.readStringUntil('\n');
      accessory_state = arg_str.toInt();
    }
    else if(data_type == "fuel") {
      String arg_str = Serial.readStringUntil('\n');
      fuel_val = arg_str.toInt();
    }
    else if (data_type == "engineStateFeedback") {
      String arg_str = Serial.readStringUntil('\n');
      engine_start_feedback_state = arg_str.toInt();
    }
    else if (data_type == "signalGong") {
      String arg_str = Serial.readStringUntil('\n');
      signal_gong_state = arg_str.toInt();
    }
    else if (data_type == "bc_button") {
      String arg_str = Serial.readStringUntil('\n');
      bc_button_state = arg_str.toInt();
    }
    else if (data_type == "seatBelt") {
      String arg_str = Serial.readStringUntil('\n');
      seat_belt_state = arg_str.toInt();
    }
    else if (data_type == "coolantLevelSensor") {
      String arg_str = Serial.readStringUntil('\n');
      coolant_level_sensor_state = arg_str.toInt();
    }
    else if (data_type == "brakeWearSensor") {
      String arg_str = Serial.readStringUntil('\n');
      brake_wear_sensor_state = arg_str.toInt();
    }
    else if (data_type == "parkingBrakeState") {
      String arg_str = Serial.readStringUntil('\n');
      parking_brake_state = arg_str.toInt();
    }
    else if (data_type == "ABS_Warning") {
      String arg_str = Serial.readStringUntil('\n');
      abs_warning_state = arg_str.toInt();
    }
    else if (data_type == "airbagLight") {
      String arg_str = Serial.readStringUntil('\n');
      airbag_warning_state = arg_str.toInt();
    }
    else if (data_type == "brakeFluidSensor") {
      String arg_str = Serial.readStringUntil('\n');
      brake_fluid_state = arg_str.toInt();
    }
    else if (data_type == "oilSensor") {
      String arg_str = Serial.readStringUntil('\n');
      oil_level_sensor_state = arg_str.toInt();
    }
    else if (data_type == "oilPressureSwitch") {
      String arg_str = Serial.readStringUntil('\n');
      oil_pressure_switch_state = arg_str.toInt();
    }
    else if (data_type == "clusterBacklight") {
      String arg_str = Serial.readStringUntil('\n');
      cluster_backlight_state = arg_str.toInt();
    }
    else if (data_type == "washerFluidLight") {
      String arg_str = Serial.readStringUntil('\n');
      washer_fluid_level_state = arg_str.toInt();
    }
    else if(data_type == "cruiseLight") {
      String arg_str = Serial.readStringUntil('\n');
      cruise_light_state = arg_str.toInt();
    }
    else if (data_type == "rolloverSensor") {
      String arg_str = Serial.readStringUntil('\n');
      rollover_sensor_state = arg_str.toInt();
    }
    else if (data_type == "reverse") {
      String arg_str = Serial.readStringUntil('\n');
      reverse_state = arg_str.toInt();
    }
    else if(data_type == "eLight") {
      String arg_str = Serial.readStringUntil('\n');
      engine_light_state = arg_str.toInt();
    }
    else if(data_type == "emlLight") {
      String arg_str = Serial.readStringUntil('\n');
      EML_state = arg_str.toInt();
    }
    else if(data_type == "gasCapLight") {
      String arg_str = Serial.readStringUntil('\n');
      gas_cap_light_state = arg_str.toInt();
    }
    else if(data_type == "heatLight") {
      String arg_str = Serial.readStringUntil('\n');
      heat_light_state = arg_str.toInt();
    }
    else if(data_type == "oilLight") {
      String arg_str = Serial.readStringUntil('\n');
      oil_light_state = arg_str.toInt();
    }
    else if(data_type == "chgLight") {
      String arg_str = Serial.readStringUntil('\n');
      charge_light_state = arg_str.toInt();
    }
    else if(data_type == "highBeam") {
      String arg_str = Serial.readStringUntil('\n');
      high_beam_state = arg_str.toInt();
    }
    else if(data_type == "fogRear") {
      String arg_str = Serial.readStringUntil('\n');
      fog_rear_state = arg_str.toInt();
    }
    else if(data_type == "fogFront") {
      String arg_str = Serial.readStringUntil('\n');
      fog_front_state = arg_str.toInt();
    }
    else if(data_type == "leftBlink") {
      String arg_str = Serial.readStringUntil('\n');
      left_blinker_state = arg_str.toInt();
    }
    else if(data_type == "rightBlink") {
      String arg_str = Serial.readStringUntil('\n');
      right_blinker_state = arg_str.toInt();
    }
    else if(data_type == "backRightLight") {
      String arg_str = Serial.readStringUntil('\n');
      back_right_light_state = arg_str.toInt();
    }
    else if(data_type == "backLeftLight") {
      String arg_str = Serial.readStringUntil('\n');
      back_left_light_state = arg_str.toInt();
    }
    else if(data_type == "frontRightLight") {
      String arg_str = Serial.readStringUntil('\n');
      front_right_light_state = arg_str.toInt();
    }
    else if(data_type == "frontLeftLight") {
      String arg_str = Serial.readStringUntil('\n');
      front_left_light_state = arg_str.toInt();
    }
    else if(data_type == "carLight") {
      String arg_str = Serial.readStringUntil('\n');
      car_light_state = arg_str.toInt();
    }
    else {
      // Flush the rest of the data
      Serial.readStringUntil('\n');
    }

      // Debugger Print out
#if DEBUG_VALUES
    Serial.print("fuel: ");
    Serial.println(fuel_val);

    Serial.print("Battery charge value: ");
    Serial.println(battery_charge_val);

    Serial.print("engineStateFeedback: ");
    Serial.println(engine_start_feedback_state);

    Serial.print("signalGong: ");
    Serial.println(signal_gong_state);

    Serial.print("bc_button: ");
    Serial.println(bc_button_state);

    Serial.print("seatBelt: ");
    Serial.println(seat_belt_state);

    Serial.print("coolantLevelSensor: ");
    Serial.println(coolant_level_sensor_state);

    Serial.print("brakeWearSensor: ");
    Serial.println(brake_wear_sensor_state);

    Serial.print("parkingBrakeState: ");
    Serial.println(parking_brake_state);

    Serial.print("ABS_Warning: ");
    Serial.println(abs_warning_state);

    Serial.print("airbagLight: ");
    Serial.println(airbag_warning_state);

    Serial.print("brakeFluidSensor: ");
    Serial.println(brake_fluid_state);

    Serial.print("oilSensor: ");
    Serial.println(oil_level_sensor_state);

    Serial.print("ignition: ");
    Serial.println(ignition_state);

    Serial.print("accessory: ");
    Serial.println(accessory_state);

    Serial.print("oilPressureSwitch: ");
    Serial.println(oil_pressure_switch_state);

    Serial.print("clusterBacklight: ");
    Serial.println(cluster_backlight_state);

    Serial.print("washerFluidLight: ");
    Serial.println(washer_fluid_level_state);

    Serial.print("cruiseLight: ");
    Serial.println(cruise_light_state);

    Serial.print("rolloverSensor: ");
    Serial.println(rollover_sensor_state);

    Serial.print("reverse: ");
    Serial.println(reverse_state);
    
    Serial.print("rpm: ");
    Serial.println(rpm_val);
    
    Serial.print("speed: ");
    Serial.println(speed_val);
    
    Serial.print("temp: ");
    Serial.println(temp_val);
    
    Serial.print("mpg: ");
    Serial.println(mpg_val);

    Serial.print("Temperature Val: ");
    Serial.println(temp_val);

    Serial.print("eLight: ");
    Serial.println(engine_light_state);

    Serial.print("emlLight: ");
    Serial.println(EML_state);

    Serial.print("gasCapLight: ");
    Serial.println(gas_cap_light_state);

    Serial.print("heatLight: ");
    Serial.println(heat_light_state);

    Serial.print("oilLight: ");
    Serial.println(oil_light_state);

    Serial.print("chgLight: ");
    Serial.println(charge_light_state);

    Serial.print("highBeam: ");
    Serial.println(high_beam_state);

    Serial.print("fogRear: ");
    Serial.println(fog_rear_state);

    Serial.print("fogFront: ");
    Serial.println(fog_front_state);

    Serial.print("leftBlink: ");
    Serial.println(left_blinker_state);

    Serial.print("rightBlink: ");
    Serial.println(right_blinker_state);

    Serial.print("backRightLight: ");
    Serial.println(back_right_light_state);

    Serial.print("backLeftLight: ");
    Serial.println(back_left_light_state);

    Serial.print("frontRightLight: ");
    Serial.println(front_right_light_state);

    Serial.print("frontLeftLight: ");
    Serial.println(front_left_light_state);

    Serial.print("carLight: ");
    Serial.println(car_light_state);
    
    Serial.println();
    
#endif
  }

  // Configure all of the digital outputs
  digitalWrite(ENGINE_START_FEEDBACK_PIN, engine_start_feedback_state);
  digitalWrite(SIGNAL_GONG_PIN, signal_gong_state);
  digitalWrite(BC_BUTTON_PIN, bc_button_state);
  digitalWrite(SEAT_BELT_PIN, seat_belt_state);
  digitalWrite(COOLANT_LEVEL_SENSOR_PIN, coolant_level_sensor_state);
  digitalWrite(BRAKE_WEAR_SENSOR_PIN, brake_wear_sensor_state);
  digitalWrite(PARKING_BRAKE_PIN, parking_brake_state);
  digitalWrite(ABS_WARNING_PIN, abs_warning_state);
  digitalWrite(AIRBAG_WARNING_PIN, airbag_warning_state);
  digitalWrite(BRAKE_FLUID_PIN, brake_fluid_state);
  digitalWrite(OIL_LEVEL_SENSOR_PIN, oil_level_sensor_state);
  digitalWrite(IGNITION_ON_PIN, ignition_state);
  digitalWrite(ACCESSORY_MODE_PIN, accessory_state); 
  digitalWrite(OIL_PRESSURE_SWITCH_PIN, oil_pressure_switch_state);
  digitalWrite(CLUSTER_BACKLIGHT_PIN, cluster_backlight_state);
  digitalWrite(WASHER_FLUID_LEVEL_PIN, washer_fluid_level_state);
  digitalWrite(CRUISE_CONTROL_LIGHT_PIN, cruise_light_state);
  digitalWrite(ROLLOVER_SENSOR_PIN, rollover_sensor_state);
  digitalWrite(REVERSE_PIN, reverse_state);

  // Readback the battery charge indicator
  battery_charge_val = analogRead(BATTERY_CHARGE_INDICATOR_PIN);

  setFuel(DIGI_POT_CS, fuel_val);
  delay(5);
  setRPM(CAN, rpm_val);
  delay(5);
  setSpeedometer(CAN, SPEED_SIGNAL_PIN, speed_val);
  delay(5);
  setTemp(CAN, temp_val);
  delay(5);
  set_status_lights1(CAN, engine_light_state, cruise_light_state, EML_state, gas_cap_light_state, heat_light_state, oil_light_state, charge_light_state);
  delay(5);
  
  /*
  // Set all the wheel speeds
  unsigned int wheel1_speed = 10;
  byte wheel1_lsb = wheel1_speed & 0xFF;
  byte wheel1_msb = (wheel1_speed >> 8) & 0x0F;
  unsigned int wheel2_speed = 10;
  byte wheel2_lsb = wheel2_speed & 0xFF;
  byte wheel2_msb = (wheel2_speed >> 8) & 0x0F;
  unsigned int wheel3_speed = 10;
  byte wheel3_lsb = wheel3_speed & 0xFF;
  byte wheel3_msb = (wheel3_speed >> 8) & 0x0F;
  unsigned int wheel4_speed = 10;
  byte wheel4_lsb = wheel4_speed & 0xFF;
  byte wheel4_msb = (wheel4_speed >> 8) & 0x0F;
  CAN_Send(0x1F0, wheel1_lsb, wheel1_msb, wheel2_lsb, wheel2_msb, wheel3_lsb, wheel3_msb, wheel4_lsb, wheel4_msb);
  
  //CAN_Send(0x153, 0, 0, 0, 0, 0, 0, 0, 0);
  //CAN_Send(0x1F5, 0, 0, 0, 0, 0, 0, 0, 0); // Set the steering angle to 0
  //CAN_Send(0x1F8, 0, 0, 0, 0, 0, 0, 0, 0); // Set the brake pressure to 0
  */

  // Run the kbus interaction once every 255 loop cycles
  if(loopCounter >=50) {
    // Packing up data to send to kbus function
    bool light_array1[] = {high_beam_state, fog_rear_state, fog_front_state, left_blinker_state, right_blinker_state};
    bool light_array2[] = {back_right_light_state, back_left_light_state, front_right_light_state, front_left_light_state, car_light_state};
    set_kbus_lights(KBUS, light_array1, light_array2);

    // Reset counter
    loopCounter = 0;
  }
  
  delay(1);
  loopCounter += 1;
}

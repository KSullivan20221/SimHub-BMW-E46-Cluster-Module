#ifndef __SHCUSTOMPROTOCOL_H__
#define __SHCUSTOMPROTOCOL_H__

// Library includes
#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>

// Local file includes
#include "constants.h"
#include "pin_definitions.h"
#include "cluster_control_functions.h"

MCP2515 CAN(MCP2515_CS);

  // Global variables that are changed in the main loop, and initializing certian states
  uint8_t fuel_val;
  uint8_t engine_start_feedback_state = 0;
  uint8_t signal_gong_state = 0;;
  uint8_t bc_button_state = 0;
  uint8_t seat_belt_state = 0;
  uint8_t coolant_level_sensor_state = 1;
  uint8_t brake_wear_sensor_state = 1;
  uint8_t parking_brake_state = 1;
  uint8_t abs_warning_state = 1;
  uint8_t airbag_warning_state = 0;
  uint8_t brake_fluid_state = 1;
  int speed_val;
  uint8_t oil_level_sensor_state = 0;
  uint8_t ignition_state = 0;
  uint8_t accessory_state = 0;
  uint8_t oil_pressure_switch_state = 0;
  uint8_t cluster_backlight_state = 0;
  uint8_t washer_fluid_level_state;
  uint8_t rollover_sensor_state;
  uint8_t reverse_state;
  
  int rpm_val;
  int temp_val;
  int mpg_val;
  uint8_t engine_light_state;
  uint8_t cruise_light_state;
  uint8_t EML_state;
  uint8_t gas_cap_light_state = 0;
  uint8_t heat_light_state = 0;
  uint8_t charge_light_state = 0;
  uint8_t oil_light_state = 0;
  uint8_t high_beam_state;
  uint8_t fog_rear_state = 0;
  uint8_t fog_front_state = 0;
  uint8_t left_blinker_state = 0;
  uint8_t right_blinker_state = 0;
  uint8_t back_right_light_state = 0;
  uint8_t back_left_light_state = 0;
  uint8_t front_right_light_state = 0;
  uint8_t front_left_light_state = 0;
  uint8_t car_light_state = 0;
  int battery_charge_val;

class SHCustomProtocol {
private:

public:

  /*
  CUSTOM PROTOCOL CLASS
  SEE https://github.com/zegreatclan/SimHub/wiki/Custom-Arduino-hardware-support

  GENERAL RULES :
    - ALWAYS BACKUP THIS FILE, reinstalling/updating SimHub would overwrite it with the default version.
    - Read data AS FAST AS POSSIBLE in the read function
    - NEVER block the arduino (using delay for instance)
    - Make sure the data read in "read()" function READS ALL THE DATA from the serial port matching the custom protocol definition
    - Idle function is called hundreds of times per second, never use it for slow code, arduino performances would fall
    - If you use library suspending interrupts make sure to use it only in the "read" function when ALL data has been read from the serial port.
      It is the only interrupt safe place

  COMMON FUNCTIONS :
    - FlowSerialReadStringUntil('\n')
      Read the incoming data up to the end (\n) won't be included
    - FlowSerialReadStringUntil(';')
      Read the incoming data up to the separator (;) separator won't be included
    - FlowSerialDebugPrintLn(string)
      Send a debug message to simhub which will display in the log panel and log file (only use it when debugging, it would slow down arduino in run conditions)

  */

  // Called when starting the arduino (setup method in main sketch)
  void setup() {
    
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

    #if DEBUG_ENABLE
      // Serial Debug Communication
      DEBUG_PORT.begin(9600);
    #endif
    
    // MCP2515 Initialization
    CAN.reset();
    CAN.setBitrate(CAN_500KBPS, MCP_16MHZ);
    CAN.setNormalMode();
    
  }

  // Called when new data is coming from computer  
  void read() {
    // If there is no data in the buffer, keep looping
    String data_type = FlowSerialReadStringUntil(':');
    while(data_type != "end") {

      if(data_type == "speed") {
        String arg_str = FlowSerialReadStringUntil('\n');
        speed_val = arg_str.toInt();
      }
      else if(data_type == "rpm") {
        String arg_str = FlowSerialReadStringUntil('\n');
        rpm_val = arg_str.toInt();
      }
      else if(data_type == "temp") {
        String arg_str = FlowSerialReadStringUntil('\n');
        temp_val = arg_str.toInt();
      }
      else if (data_type == "ignition") {
        String arg_str = FlowSerialReadStringUntil('\n');
        ignition_state = arg_str.toInt();
      }
      else if (data_type == "accessory") {
        String arg_str = FlowSerialReadStringUntil('\n');
        accessory_state = arg_str.toInt();
      }
      else if(data_type == "fuel") {
        String arg_str = FlowSerialReadStringUntil('\n');
        fuel_val = arg_str.toInt();
      }
      else if (data_type == "engineStateFeedback") {
        String arg_str = FlowSerialReadStringUntil('\n');
        engine_start_feedback_state = arg_str.toInt();
      }
      else if (data_type == "signalGong") {
        String arg_str = FlowSerialReadStringUntil('\n');
        signal_gong_state = arg_str.toInt();
      }
      else if (data_type == "bc_button") {
        String arg_str = FlowSerialReadStringUntil('\n');
        bc_button_state = arg_str.toInt();
      }
      else if (data_type == "seatBelt") {
        String arg_str = FlowSerialReadStringUntil('\n');
        seat_belt_state = arg_str.toInt();
      }
      else if (data_type == "coolantLevelSensor") {
        String arg_str = FlowSerialReadStringUntil('\n');
        coolant_level_sensor_state = arg_str.toInt();
      }
      else if (data_type == "brakeWearSensor") {
        String arg_str = FlowSerialReadStringUntil('\n');
        brake_wear_sensor_state = arg_str.toInt();
      }
      else if (data_type == "parkingBrakeState") {
        String arg_str = FlowSerialReadStringUntil('\n');
        parking_brake_state = arg_str.toInt();
      }
      else if (data_type == "ABS_Warning") {
        String arg_str = FlowSerialReadStringUntil('\n');
        abs_warning_state = arg_str.toInt();
      }
      else if (data_type == "airbagLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        airbag_warning_state = arg_str.toInt();
      }
      else if (data_type == "brakeFluidSensor") {
        String arg_str = FlowSerialReadStringUntil('\n');
        brake_fluid_state = arg_str.toInt();
      }
      else if (data_type == "oilSensor") {
        String arg_str = FlowSerialReadStringUntil('\n');
        oil_level_sensor_state = arg_str.toInt();
      }
      else if (data_type == "oilPressureSwitch") {
        String arg_str = FlowSerialReadStringUntil('\n');
        oil_pressure_switch_state = arg_str.toInt();
      }
      else if (data_type == "clusterBacklight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        cluster_backlight_state = arg_str.toInt();
      }
      else if (data_type == "washerFluidLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        washer_fluid_level_state = arg_str.toInt();
      }
      else if(data_type == "cruiseLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        cruise_light_state = arg_str.toInt();
      }
      else if (data_type == "rolloverSensor") {
        String arg_str = FlowSerialReadStringUntil('\n');
        rollover_sensor_state = arg_str.toInt();
      }
      else if (data_type == "reverse") {
        String arg_str = FlowSerialReadStringUntil('\n');
        reverse_state = arg_str.toInt();
      }
      else if(data_type == "eLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        engine_light_state = arg_str.toInt();
      }
      else if(data_type == "emlLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        EML_state = arg_str.toInt();
      }
      else if(data_type == "gasCapLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        gas_cap_light_state = arg_str.toInt();
      }
      else if(data_type == "heatLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        heat_light_state = arg_str.toInt();
      }
      else if(data_type == "oilLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        oil_light_state = arg_str.toInt();
      }
      else if(data_type == "chgLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        charge_light_state = arg_str.toInt();
      }
      else if(data_type == "highBeam") {
        String arg_str = FlowSerialReadStringUntil('\n');
        high_beam_state = arg_str.toInt();
      }
      else if(data_type == "fogRear") {
        String arg_str = FlowSerialReadStringUntil('\n');
        fog_rear_state = arg_str.toInt();
      }
      else if(data_type == "fogFront") {
        String arg_str = FlowSerialReadStringUntil('\n');
        fog_front_state = arg_str.toInt();
      }
      else if(data_type == "leftBlink") {
        String arg_str = FlowSerialReadStringUntil('\n');
        left_blinker_state = arg_str.toInt();
      }
      else if(data_type == "rightBlink") {
        String arg_str = FlowSerialReadStringUntil('\n');
        right_blinker_state = arg_str.toInt();
      }
      else if(data_type == "backRightLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        back_right_light_state = arg_str.toInt();
      }
      else if(data_type == "backLeftLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        back_left_light_state = arg_str.toInt();
      }
      else if(data_type == "frontRightLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        front_right_light_state = arg_str.toInt();
      }
      else if(data_type == "frontLeftLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        front_left_light_state = arg_str.toInt();
      }
      else if(data_type == "carLight") {
        String arg_str = FlowSerialReadStringUntil('\n');
        car_light_state = arg_str.toInt();
      }
      else {
        // Flush the rest of the data
        FlowSerialReadStringUntil('\n');
      }

      // Read next piece of data
      data_type = FlowSerialReadStringUntil(':');
    }           
  }

  // Called once per arduino loop, timing can't be predicted, 
  // but it's called between each command sent to the arduino
  int loopCounter = 0;
  void loop() {
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
    
    // Send values to the cluster when idling
    setFuel(DIGI_POT_CS, fuel_val);
    setSpeedometer(SPEED_SIGNAL_PIN, speed_val);
    //setMPG(mpg_val);

    // Run the kbus interaction once every 50 loop cycles
    if(loopCounter >= 50) {
      // Packing up data to send to kbus function
      byte light_array1[] = {high_beam_state, fog_rear_state, fog_front_state, left_blinker_state, right_blinker_state};
      byte light_array2[] = {back_right_light_state, back_left_light_state, front_right_light_state, front_left_light_state, car_light_state};
      set_kbus_lights(KBUS, light_array1, light_array2);
      
      // Reset counter
      loopCounter = 0;
    }
    
    // Iterate the counter once per loop 
    loopCounter += 1;

    // Tune the delay to make sure everything works / isn't overflowing
    //delay(10);
  }

  // Called once between each byte read on arduino,
  // THIS IS A CRITICAL PATH :
  // AVOID ANY TIME CONSUMING ROUTINES !!!
  // PREFER READ OR LOOP METHOS AS MUCH AS POSSIBLE
  // AVOID ANY INTERRUPTS DISABLE (serial data would be lost!!!)

  void idle() {
    
    // Put CAN operations in the faster loop
    setRPM(CAN, rpm_val);
    setTemp(CAN, temp_val);
    set_status_lights1(CAN, engine_light_state, cruise_light_state, EML_state, gas_cap_light_state, heat_light_state, oil_light_state, charge_light_state);
    
  }
};

#endif

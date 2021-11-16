// Extern references to get these functions to the main program
extern void CAN_Send(MCP2515 &can_bus, uint16_t address, byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte h);
extern void setSpeedometer(MCP2515 &can_bus, uint8_t speed_signal_pin, int speed_val);
extern void setRPM(MCP2515 &can_bus, float rpm_val);
extern void setTemp(MCP2515 &can_bus, int temp_val);
extern void setFuel(uint8_t chip_select_pin, uint8_t fuel_percent);
extern void setMPG(int mpg_val);
extern void set_kbus_lights(HardwareSerial &refSer, byte *light_array1, byte *light_array2);
extern void set_status_lights1(MCP2515 &can_bus, int engine_light_state, int cruise_light_state, int EML_state, int gas_cap_light_state, int heat_light_state, int oil_light_state, int charge_light_state, int fuel_consumption_val);

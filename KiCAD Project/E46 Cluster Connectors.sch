EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x13_Top_Bottom J8
U 1 1 615640A5
P 5550 2400
F 0 "J8" H 5600 1575 50  0000 C CNN
F 1 "Conn_02x13_Top_Bottom" H 5600 1666 50  0000 C CNN
F 2 "# Custom Connectors (2.54 mm):3020-26-0300-00" H 5550 2400 50  0001 C CNN
F 3 "~" H 5550 2400 50  0001 C CNN
	1    5550 2400
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 6156E6D2
P 6750 3150
F 0 "#PWR0123" H 6750 2900 50  0001 C CNN
F 1 "GND" H 6755 2977 50  0000 C CNN
F 2 "" H 6750 3150 50  0001 C CNN
F 3 "" H 6750 3150 50  0001 C CNN
	1    6750 3150
	1    0    0    -1  
$EndComp
Text GLabel 5750 2900 2    39   Input ~ 0
Battery-Charge-Indicator
Wire Wire Line
	5750 3000 6750 3000
Text GLabel 5750 2800 2    39   Input ~ 0
Engine-Start-Signal-Feedback
$Comp
L power:+12V #PWR0124
U 1 1 61571765
P 6850 1700
F 0 "#PWR0124" H 6850 1550 50  0001 C CNN
F 1 "+12V" H 6865 1873 50  0000 C CNN
F 2 "" H 6850 1700 50  0001 C CNN
F 3 "" H 6850 1700 50  0001 C CNN
	1    6850 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2700 6850 2700
Wire Wire Line
	6850 2700 6850 1700
Text GLabel 5750 2600 2    39   Input ~ 0
12V-On
Text GLabel 5750 2500 2    39   Input ~ 0
12V-Accessory
Text GLabel 5750 2200 2    39   Input ~ 0
CAN_H
Text GLabel 5750 2100 2    39   Input ~ 0
CAN_L
Wire Wire Line
	5750 1900 6750 1900
Wire Wire Line
	6750 1900 6750 3000
$Comp
L power:GND #PWR0125
U 1 1 61578AC9
P 4700 3150
F 0 "#PWR0125" H 4700 2900 50  0001 C CNN
F 1 "GND" H 4705 2977 50  0000 C CNN
F 2 "" H 4700 3150 50  0001 C CNN
F 3 "" H 4700 3150 50  0001 C CNN
	1    4700 3150
	1    0    0    -1  
$EndComp
Text GLabel 5250 3000 0    39   Input ~ 0
K_BUS
Text GLabel 5250 2900 0    39   Input ~ 0
FUEL-LEFT
Text GLabel 5750 2000 2    39   Input ~ 0
FUEL-RIGHT
Text GLabel 5250 2500 0    39   Input ~ 0
Speed-Signal
Text GLabel 5250 2400 0    39   Input ~ 0
Brake-Fluid-Sensor
Text GLabel 5250 2300 0    39   Input ~ 0
Airbag-Warning
Text GLabel 5250 2200 0    39   Input ~ 0
ABS-Warning-Light
Text GLabel 5250 2000 0    39   Input ~ 0
Brake-Wear-Sensor
Text GLabel 5250 1800 0    39   Input ~ 0
Coolant-Level-Sensor
$Comp
L power:GND #PWR0126
U 1 1 6157EE95
P 6350 5650
F 0 "#PWR0126" H 6350 5400 50  0001 C CNN
F 1 "GND" H 6355 5477 50  0000 C CNN
F 2 "" H 6350 5650 50  0001 C CNN
F 3 "" H 6350 5650 50  0001 C CNN
	1    6350 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5300 6350 5650
Text GLabel 5750 5100 2    39   Input ~ 0
Washer-Fluid-Level
$Comp
L Connector_Generic:Conn_01x13 J13
U 1 1 61596393
P 7250 2400
F 0 "J13" H 7168 1575 50  0000 C CNN
F 1 "Conn_01x13" H 7168 1666 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x13_P2.54mm_Vertical" H 7250 2400 50  0001 C CNN
F 3 "~" H 7250 2400 50  0001 C CNN
	1    7250 2400
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x13 J10
U 1 1 6159DB8B
P 4200 2400
F 0 "J10" H 4118 1575 50  0000 C CNN
F 1 "Conn_01x13" H 4118 1666 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x13_P2.54mm_Vertical" H 4200 2400 50  0001 C CNN
F 3 "~" H 4200 2400 50  0001 C CNN
	1    4200 2400
	1    0    0    1   
$EndComp
Wire Wire Line
	4700 3150 4700 2800
Wire Wire Line
	4700 2800 5250 2800
$Comp
L power:GND #PWR0127
U 1 1 615A2637
P 3550 3150
F 0 "#PWR0127" H 3550 2900 50  0001 C CNN
F 1 "GND" H 3555 2977 50  0000 C CNN
F 2 "" H 3550 3150 50  0001 C CNN
F 3 "" H 3550 3150 50  0001 C CNN
	1    3550 3150
	1    0    0    -1  
$EndComp
Text GLabel 4000 3000 0    39   Input ~ 0
K_BUS
Text GLabel 4000 2900 0    39   Input ~ 0
FUEL-LEFT
Wire Wire Line
	3550 3150 3550 2800
Wire Wire Line
	3550 2800 4000 2800
Text GLabel 4000 2500 0    39   Input ~ 0
Speed-Signal
Text GLabel 4000 2400 0    39   Input ~ 0
Brake-Fluid-Sensor
Text GLabel 4000 2300 0    39   Input ~ 0
Airbag-Warning
Text GLabel 4000 2200 0    39   Input ~ 0
ABS-Warning-Light
Text GLabel 4000 2000 0    39   Input ~ 0
Brake-Wear-Sensor
Text GLabel 4000 1800 0    39   Input ~ 0
Coolant-Level-Sensor
$Comp
L power:GND #PWR0128
U 1 1 615A3F38
P 8550 3150
F 0 "#PWR0128" H 8550 2900 50  0001 C CNN
F 1 "GND" H 8555 2977 50  0000 C CNN
F 2 "" H 8550 3150 50  0001 C CNN
F 3 "" H 8550 3150 50  0001 C CNN
	1    8550 3150
	1    0    0    -1  
$EndComp
Text GLabel 7450 2800 2    39   Input ~ 0
Engine-Start-Signal-Feedback
Text GLabel 7450 2900 2    39   Input ~ 0
Battery-Charge-Indicator
Text GLabel 7450 2600 2    39   Input ~ 0
12V-On
Text GLabel 7450 2500 2    39   Input ~ 0
12V-Accessory
Text GLabel 7450 2200 2    39   Input ~ 0
CAN_H
Text GLabel 7450 2100 2    39   Input ~ 0
CAN_L
Text GLabel 7450 2000 2    39   Input ~ 0
FUEL-RIGHT
Wire Wire Line
	7450 1900 8550 1900
Wire Wire Line
	8550 1900 8550 3000
Wire Wire Line
	7450 3000 8550 3000
Connection ~ 8550 3000
Wire Wire Line
	8550 3000 8550 3150
$Comp
L power:+12V #PWR0129
U 1 1 615A5E96
P 8650 1700
F 0 "#PWR0129" H 8650 1550 50  0001 C CNN
F 1 "+12V" H 8665 1873 50  0000 C CNN
F 2 "" H 8650 1700 50  0001 C CNN
F 3 "" H 8650 1700 50  0001 C CNN
	1    8650 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 2700 7450 2700
Wire Wire Line
	8650 1700 8650 2700
Wire Wire Line
	6750 3150 6750 3000
Connection ~ 6750 3000
$Comp
L power:GND #PWR0130
U 1 1 615D1A30
P 7450 5650
F 0 "#PWR0130" H 7450 5400 50  0001 C CNN
F 1 "GND" H 7455 5477 50  0000 C CNN
F 2 "" H 7450 5650 50  0001 C CNN
F 3 "" H 7450 5650 50  0001 C CNN
	1    7450 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 5300 7450 5650
Text GLabel 6800 5100 2    39   Input ~ 0
Washer-Fluid-Level
Text GLabel 5750 2400 2    39   Input ~ 0
Cluster-Backlight
Text GLabel 5750 2300 2    39   Input ~ 0
Speedometer-Signal-Output
Text GLabel 5750 1800 2    39   Input ~ 0
Oil-Pressure-Switch
Text GLabel 5250 2100 0    39   Input ~ 0
Parking-Brake-Switch
Text GLabel 5250 2600 0    39   Input ~ 0
Service-Interval-Reset
Text GLabel 5250 2700 0    39   Input ~ 0
Oil-Level-Sensor
Text GLabel 4000 2700 0    39   Input ~ 0
Oil-Level-Sensor
Text GLabel 4000 2600 0    39   Input ~ 0
Service-Interval-Reset
Text GLabel 4000 2100 0    39   Input ~ 0
Parking-Brake-Switch
Text GLabel 4000 1900 0    39   Input ~ 0
OBDII-DIAG
Text GLabel 7450 1800 2    39   Input ~ 0
Oil-Pressure-Switch
Text GLabel 7450 2300 2    39   Input ~ 0
Speedometer-Signal-Output
Text GLabel 7450 2400 2    39   Input ~ 0
Cluster-Backlight
Text GLabel 5750 5000 2    39   Input ~ 0
Cruise-Control-Light
Text GLabel 5750 4900 2    39   Input ~ 0
Rollover-Sensor
Text GLabel 5750 4800 2    39   Input ~ 0
Reverse
Text GLabel 5250 5200 0    39   Input ~ 0
Seat-Belt
Text GLabel 5250 5100 0    39   Input ~ 0
BC-Button
Text GLabel 5250 5000 0    39   Input ~ 0
Signal-Gong
Text GLabel 4450 5000 0    39   Input ~ 0
Signal-Gong
Text GLabel 4450 5100 0    39   Input ~ 0
BC-Button
Text GLabel 4450 5200 0    39   Input ~ 0
Seat-Belt
Text GLabel 6800 5000 2    39   Input ~ 0
Cruise-Control-Light
Text GLabel 6800 4900 2    39   Input ~ 0
Rollover-Sensor
Text GLabel 6800 4800 2    39   Input ~ 0
Reverse
Wire Wire Line
	5750 5300 6350 5300
Text GLabel 5750 5400 2    39   Input ~ 0
Outside-Temp
Text GLabel 6800 5400 2    39   Input ~ 0
Outside-Temp
Wire Wire Line
	6800 5300 7450 5300
Text Notes 3800 4100 0    118  ~ 0
X11176: 18-Pin Dual Row White Connector
Text Notes 3800 1200 0    118  ~ 0
X11175: 26-Pin Dual Row Black Connector
Text GLabel 5250 1900 0    39   Input ~ 0
OBDII-DIAG
$Comp
L Connector_Generic:Conn_01x09 J11
U 1 1 615CF7A4
P 4650 5000
F 0 "J11" H 4568 4375 50  0000 C CNN
F 1 "Conn_01x09" H 4568 4466 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 4650 5000 50  0001 C CNN
F 3 "~" H 4650 5000 50  0001 C CNN
	1    4650 5000
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_02x09_Top_Bottom J9
U 1 1 61569901
P 5550 5000
F 0 "J9" H 5600 4375 50  0000 C CNN
F 1 "Conn_02x09_Top_Bottom" H 5600 4466 50  0000 C CNN
F 2 "# Custom Connectors (2.00 mm):PinHeader_2x09_P2.00mm_Vertical_SMD_Top_Bottom;98424-G52-18ALF" H 5550 5000 50  0001 C CNN
F 3 "~" H 5550 5000 50  0001 C CNN
	1    5550 5000
	-1   0    0    1   
$EndComp
Text GLabel 5250 4600 0    39   Input ~ 0
NC1
Text GLabel 4450 4600 0    39   Input ~ 0
NC1
Text GLabel 4450 4700 0    39   Input ~ 0
NC2
Text GLabel 5250 4700 0    39   Input ~ 0
NC2
Text GLabel 5250 4800 0    39   Input ~ 0
NC3
Text GLabel 5250 4900 0    39   Input ~ 0
NC4
Text GLabel 5250 5300 0    39   Input ~ 0
NC5
Text GLabel 5250 5400 0    39   Input ~ 0
NC6
Text GLabel 5750 4600 2    39   Input ~ 0
NC7
Text GLabel 5750 4700 2    39   Input ~ 0
NC8
Text GLabel 5750 5200 2    39   Input ~ 0
NC9
Text GLabel 4450 4800 0    39   Input ~ 0
NC3
Text GLabel 4450 4900 0    39   Input ~ 0
NC4
Text GLabel 4450 5300 0    39   Input ~ 0
NC5
Text GLabel 4450 5400 0    39   Input ~ 0
NC6
$Comp
L Connector_Generic:Conn_01x09 J12
U 1 1 615CD6DA
P 6600 5000
F 0 "J12" H 6518 4375 50  0000 C CNN
F 1 "Conn_01x09" H 6518 4466 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 6600 5000 50  0001 C CNN
F 3 "~" H 6600 5000 50  0001 C CNN
	1    6600 5000
	-1   0    0    1   
$EndComp
Text GLabel 6800 4600 2    39   Input ~ 0
NC7
Text GLabel 6800 4700 2    39   Input ~ 0
NC8
Text GLabel 6800 5200 2    39   Input ~ 0
NC9
$EndSCHEMATC

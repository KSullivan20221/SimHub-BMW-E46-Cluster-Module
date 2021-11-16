EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
P 5500 2200
F 0 "J8" H 5550 1375 50  0000 C CNN
F 1 "Conn_02x13_Top_Bottom" H 5550 1466 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x13_P2.54mm_Vertical" H 5500 2200 50  0001 C CNN
F 3 "~" H 5500 2200 50  0001 C CNN
	1    5500 2200
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_02x09_Top_Bottom J9
U 1 1 61569901
P 5500 5150
F 0 "J9" H 5550 4525 50  0000 C CNN
F 1 "Conn_02x09_Top_Bottom" H 5550 4616 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x09_P2.54mm_Vertical" H 5500 5150 50  0001 C CNN
F 3 "~" H 5500 5150 50  0001 C CNN
	1    5500 5150
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 6156E6D2
P 6700 2950
F 0 "#PWR0123" H 6700 2700 50  0001 C CNN
F 1 "GND" H 6705 2777 50  0000 C CNN
F 2 "" H 6700 2950 50  0001 C CNN
F 3 "" H 6700 2950 50  0001 C CNN
	1    6700 2950
	1    0    0    -1  
$EndComp
Text GLabel 5700 2700 2    39   Input ~ 0
Battery-Charge-Indicator
Wire Wire Line
	5700 2800 6700 2800
Text GLabel 5700 2600 2    39   Input ~ 0
Engine-Start-Signal-Feedback
$Comp
L power:+12V #PWR0124
U 1 1 61571765
P 6800 1500
F 0 "#PWR0124" H 6800 1350 50  0001 C CNN
F 1 "+12V" H 6815 1673 50  0000 C CNN
F 2 "" H 6800 1500 50  0001 C CNN
F 3 "" H 6800 1500 50  0001 C CNN
	1    6800 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 2500 6800 2500
Wire Wire Line
	6800 2500 6800 1500
Text GLabel 5700 2400 2    39   Input ~ 0
12V-On
Text GLabel 5700 2300 2    39   Input ~ 0
12V-Accessory
Text GLabel 5700 2000 2    39   Input ~ 0
CAN_H
Text GLabel 5700 1900 2    39   Input ~ 0
CAN_L
Wire Wire Line
	5700 1700 6700 1700
Wire Wire Line
	6700 1700 6700 2800
$Comp
L power:GND #PWR0125
U 1 1 61578AC9
P 4650 2950
F 0 "#PWR0125" H 4650 2700 50  0001 C CNN
F 1 "GND" H 4655 2777 50  0000 C CNN
F 2 "" H 4650 2950 50  0001 C CNN
F 3 "" H 4650 2950 50  0001 C CNN
	1    4650 2950
	1    0    0    -1  
$EndComp
Text GLabel 5200 2800 0    39   Input ~ 0
K_BUS
Text GLabel 5200 2700 0    39   Input ~ 0
FUEL-LEFT
Text GLabel 5700 1800 2    39   Input ~ 0
FUEL-RIGHT
Text GLabel 5200 2300 0    39   Input ~ 0
Speed-Signal
Text GLabel 5200 2200 0    39   Input ~ 0
Brake-Fluid-Sensor
Text GLabel 5200 2100 0    39   Input ~ 0
Airbag-Warning
Text GLabel 5200 2000 0    39   Input ~ 0
ABS-Warning-Light
Text GLabel 5200 1800 0    39   Input ~ 0
Brake-Wear-Sensor
Text GLabel 5200 1600 0    39   Input ~ 0
Coolant-Level-Sensor
$Comp
L power:GND #PWR0126
U 1 1 6157EE95
P 5950 5800
F 0 "#PWR0126" H 5950 5550 50  0001 C CNN
F 1 "GND" H 5955 5627 50  0000 C CNN
F 2 "" H 5950 5800 50  0001 C CNN
F 3 "" H 5950 5800 50  0001 C CNN
	1    5950 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 5450 5950 5450
Wire Wire Line
	5950 5450 5950 5800
Text GLabel 5700 5250 2    39   Input ~ 0
Washer-Fluid-Level
$Comp
L Connector_Generic:Conn_01x13 J?
U 1 1 61596393
P 7200 2200
F 0 "J?" H 7118 1375 50  0000 C CNN
F 1 "Conn_01x13" H 7118 1466 50  0000 C CNN
F 2 "" H 7200 2200 50  0001 C CNN
F 3 "~" H 7200 2200 50  0001 C CNN
	1    7200 2200
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x13 J?
U 1 1 6159DB8B
P 4150 2200
F 0 "J?" H 4068 1375 50  0000 C CNN
F 1 "Conn_01x13" H 4068 1466 50  0000 C CNN
F 2 "" H 4150 2200 50  0001 C CNN
F 3 "~" H 4150 2200 50  0001 C CNN
	1    4150 2200
	1    0    0    1   
$EndComp
Wire Wire Line
	4650 2950 4650 2600
Wire Wire Line
	4650 2600 5200 2600
$Comp
L power:GND #PWR?
U 1 1 615A2637
P 3500 2950
F 0 "#PWR?" H 3500 2700 50  0001 C CNN
F 1 "GND" H 3505 2777 50  0000 C CNN
F 2 "" H 3500 2950 50  0001 C CNN
F 3 "" H 3500 2950 50  0001 C CNN
	1    3500 2950
	1    0    0    -1  
$EndComp
Text GLabel 3950 2800 0    39   Input ~ 0
K_BUS
Text GLabel 3950 2700 0    39   Input ~ 0
FUEL-LEFT
Wire Wire Line
	3500 2950 3500 2600
Wire Wire Line
	3500 2600 3950 2600
Text GLabel 3950 2300 0    39   Input ~ 0
Speed-Signal
Text GLabel 3950 2200 0    39   Input ~ 0
Brake-Fluid-Sensor
Text GLabel 3950 2100 0    39   Input ~ 0
Airbag-Warning
Text GLabel 3950 2000 0    39   Input ~ 0
ABS-Warning-Light
Text GLabel 3950 1800 0    39   Input ~ 0
Brake-Wear-Sensor
Text GLabel 3950 1600 0    39   Input ~ 0
Coolant-Level-Sensor
$Comp
L power:GND #PWR?
U 1 1 615A3F38
P 8500 2950
F 0 "#PWR?" H 8500 2700 50  0001 C CNN
F 1 "GND" H 8505 2777 50  0000 C CNN
F 2 "" H 8500 2950 50  0001 C CNN
F 3 "" H 8500 2950 50  0001 C CNN
	1    8500 2950
	1    0    0    -1  
$EndComp
Text GLabel 7400 2600 2    39   Input ~ 0
Engine-Start-Signal-Feedback
Text GLabel 7400 2700 2    39   Input ~ 0
Battery-Charge-Indicator
Text GLabel 7400 2400 2    39   Input ~ 0
12V-On
Text GLabel 7400 2300 2    39   Input ~ 0
12V-Accessory
Text GLabel 7400 2000 2    39   Input ~ 0
CAN_H
Text GLabel 7400 1900 2    39   Input ~ 0
CAN_L
Text GLabel 7400 1800 2    39   Input ~ 0
FUEL-RIGHT
Wire Wire Line
	7400 1700 8500 1700
Wire Wire Line
	8500 1700 8500 2800
Wire Wire Line
	7400 2800 8500 2800
Connection ~ 8500 2800
Wire Wire Line
	8500 2800 8500 2950
$Comp
L power:+12V #PWR?
U 1 1 615A5E96
P 8600 1500
F 0 "#PWR?" H 8600 1350 50  0001 C CNN
F 1 "+12V" H 8615 1673 50  0000 C CNN
F 2 "" H 8600 1500 50  0001 C CNN
F 3 "" H 8600 1500 50  0001 C CNN
	1    8600 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 2500 7400 2500
Wire Wire Line
	8600 1500 8600 2500
Wire Wire Line
	6700 2950 6700 2800
Connection ~ 6700 2800
$Comp
L Connector_Generic:Conn_01x09 J?
U 1 1 615CD6DA
P 6550 5150
F 0 "J?" H 6468 4525 50  0000 C CNN
F 1 "Conn_01x09" H 6468 4616 50  0000 C CNN
F 2 "" H 6550 5150 50  0001 C CNN
F 3 "~" H 6550 5150 50  0001 C CNN
	1    6550 5150
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x09 J?
U 1 1 615CF7A4
P 4600 5150
F 0 "J?" H 4518 4525 50  0000 C CNN
F 1 "Conn_01x09" H 4518 4616 50  0000 C CNN
F 2 "" H 4600 5150 50  0001 C CNN
F 3 "~" H 4600 5150 50  0001 C CNN
	1    4600 5150
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 615D1A30
P 7150 5800
F 0 "#PWR?" H 7150 5550 50  0001 C CNN
F 1 "GND" H 7155 5627 50  0000 C CNN
F 2 "" H 7150 5800 50  0001 C CNN
F 3 "" H 7150 5800 50  0001 C CNN
	1    7150 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 5450 7150 5450
Wire Wire Line
	7150 5450 7150 5800
Text GLabel 6750 5250 2    39   Input ~ 0
Washer-Fluid-Level
$EndSCHEMATC

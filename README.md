# SimHub-BMW-E46-Cluster-Module
This repo contains all of the circuitry, code, and resources used to create a shield board for an Arduino Mega that could be used to communicate with a BWM E46 instrument cluster from a PC. The main application of this project was in using the cluster in conjunction with SimHub in order to show the values from the supported video games on the cluster's gauges. 

All of the testing I performed was on an E46 cluster with the following ID number and firmware:  
* Cluster Serial Number: 1031098105  
* Cluster Hardware Number: 30  (Can retrieve this by running the on-board 'Test 1' on the cluster, in test 1.5)  
* Cluster Software Number: 360 (Can retrieve this by running the on-board 'Test 1' on the cluster, in test 1.5)  

## Circuit
The circuit designed for this project was designed as a shield for an Arduino Mega microcontroller board. The purpose of this circuit was to take the signals from the Arduino Mega and use them to control the lights, gauges, and serial busses in the cluster. With this design, a user can supply 12V to the DC barrel jack input of the Arduino Mega in order to power the cluster, and then connect a USB-B cable from the computer running the video games to the Arduino to pass data between the computer and the Arduino. 

### Signals required to operate the cluster
In order to determine what signals I needed to drive the cluster, I searched for "E46 cluster pinout" and soon arrived at the following website which provided the pinout for the two connectors on the cluster:
https://www.bmwgm5.com/E46_IKE_Connections.htm

With this, and the help of the people on the following forum, I was able to come up with the following table outlining what signals were required at each pin of the cluster:

BMW CAN Bus Forum: https://www.bimmerforums.com/forum/showthread.php?1887229-E46-Can-bus-project

#### X11175 Connector Pin Function / Signal Levels

| Pin Number | Pin Function                     | Detailed Description                                                                     | Notes |
| ---        | ---                              | ---                                                                                      | ---   |
| 1          | Ground                           |                                                                                          |       |
| 2          | Battery Charge Indicator         | Provides a voltage up to 12 V indicating the batteries voltage level                     |       |
| 3          | Engine Start Signal Feedback     | Not certain, but seems like 12V into this pin indicates the engine has started           |       |
| 4          | 12V Power input                  | Always gets 12V from the battery                                                         |       |
| 5          | 12V On / Start                   | Receives 12V when car is fully on (key turned to second position)                        |       |
| 6          | 12V Accessory / On / Start       | Receives 12V when car is in accessory mode or when fully on                              |       |
| 7          | Cluster backlight                | On certain cluster models (not this one), setting to 12V turns backight on               |       |
| 8          | Speedometer Signal Output        | Unknown what this does, the cluster I used did not have anything wired here              |       |
| 9          | CAN-H Signal                     | The CAN High side of the differential pair                                               |       |
| 10         | CAN-L Signal                     | The CAN Low side of the differential pair                                                |       |
| 11         | Fuel Tank 1 +                    | Pin that fuel tank 1 level sensor positive signal is connected to                        | 70 Ohms to ground = empty, 395 Ohms to ground = full |
| 12         | Fuel Tank 1 -                    | Return connection for fuel tank 1 level sensor (sits at ground potential)                | Connecting this to ground does not cause issues for this circuit      |
| 13         | Oil Pressure Switch              | Connects to oil pressure sensor                                                          | Pulling down to ground = oil pressure issue, leaving unconnected = no issue      |
| 14         | K-Bus Signal                     | K-Bus Communication signal                                                               | The K-Bus can be controlled by one of the Arduino's serial peripherals after being level-shifted so that it ranges from 0-12V instead of the Arduino's 0-5V      |
| 15         | Fuel Tank 2 +                    | Pin that fuel tank 2 level sensor positive signal is connected to                        | 70 Ohms to ground = empty, 310 Ohms to ground = full |
| 16         | Fuel Tank 2 -                    | Return connection for fuel tank 2 level senor (sits at ground potential)                 | Connecting this to ground does not cause issues for this circuit      |
| 17         | Oil Level Sensor                 | Signal that measures how full the engine oil is                                          | Connecting this pin to ground indicates an issue with the oil level, leaving unconnected = no issue       |
| 18         | Service Interval Indicator Reset | Not certain what purpose this serves                                                     |       |
| 19         | Rear-Left Wheel Speed Sensor     | Signal that connects to wheel speed sensor that drives the speedometer                   | This is driven by a 12V fixed 50% duty cycle variable frequency square-wave (about 31 Hz = 10 MPH, 1646 Hz = 155 MPH)      |
| 20         | Brake Fluid Level Sensor         | Signal that connects to brake fluid sensor                                               | Connecting this to ground indicates there is no issue with the brake fluid, leaving this unconnected indicates there is an issue      |
| 21         | Airbag Warning LED               | Indicates the passenger airbag is ready to engage                                        | Connecting this to ground indicates the airbag is ready to engage, and will illuminate the light on the dashboard  |
| 22         | ABS Warning Light                | Inicates that ABS is disabled                                                            | Connecting to ground indicates that ABS is active, and the thus the LED on the cluster will turn off, and vice versa |
| 23         | Parking brake switch             | Indicates that the E-Brake is engaged                                                    | Connecting to ground indicates that the parking brake is not engaged, and will cause the 'BRAKE' light to turn off |
| 24         | Brake wear sensor                | Indicates when the brakes are worn                                                       | Connecting to ground indicates that the brakes are not worn, and the cluster light will turn off, and vice versa |
| 25         | Diag Signal TX                   | Unsure the function of this signal                                                       |       |
| 26         | Coolant Level Sensor             | Indicates if the coolant level is too low                                                | Connecting this to ground indicates that the coolant level is sufficient, and will turn the cluster light off, and vice versa |

#### X11176 Connector Pin Function / Signal Levels


# SimHub-BMW-E46-Cluster-Module
This repo contains all of the circuitry, code, and resources used to create a shield board for an Arduino Mega that could be used to communicate with a BWM E46 instrument cluster from a PC. The main application of this project was in using the cluster in conjunction with SimHub in order to show the values from the supported video games on the cluster's gauges. 

All of the testing I performed was on an E46 cluster with the following ID number and firmware:
Cluster Serial Number: 1031098105
Cluster Hardware Number: 30  (Can retrieve this by running the on-board 'Test 1' on the cluster, in test 1.5)
Cluster Software Number: 360 (Can retrieve this by running the on-board 'Test 1' on the cluster, in test 1.5)

## Circuit
The circuit designed for this project was designed as a shield for an Arduino Mega microcontroller board. The purpose of this circuit was to take the signals from the Arduino Mega and use them to control the lights, gauges, and serial busses in the cluster. With this design, a user can supply 12V to the DC barrel jack input of the Arduino Mega in order to power the cluster, and then connect a USB-B cable from the computer running the video games to the Arduino to pass data between the computer and the Arduino. 

### Signals required to operate the cluster
In order to determine what signals I needed to drive the cluster, I searched for "E46 cluster pinout" and soon arrived at the following website which provided the pinout for the two connectors on the cluster:
![image](https://user-images.githubusercontent.com/80495580/141702443-ce00808a-a659-4f29-86ae-15959ad65931.png)




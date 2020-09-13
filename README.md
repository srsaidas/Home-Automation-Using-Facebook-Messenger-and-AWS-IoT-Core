# Home Automation Using Facebook Messenger and AWS IoT Core
Capstone course  An Introduction to Programming the Internet of Things (IOT),  University of California, Irvine

# Overview
Home automation is a very old concept but by the introduction of IoT the home automation gain a wide range of usability. In this project, I am planning to create a temperature-controlled fan in addition to that control the fan using Facebook messenger  
# Requirements
* The fan should turn on when the room temperature is above 27 °C 
* Should turn off when room temperature below 27°C 
* Able to turn off/on the fan using Facebook messenger 
* Temperature sensor and fan control circuit should be two separate module

# Block Diagram
![Block Diagram Image 4](https://github.com/srsaidas/Programming-for-the-Internet-of-Things-Project/blob/master/block_dia.png)

# Working 
## Facebook to Relay
To communicate with nodeMCU I have created a facebook page and is linked with Amazon lex. lex will identify the messge and send a command to AWS lambda to publish a MQTT topic 'home/room/light'. The node MCU is subcribe to this topic and run the command to tourn on or off the relay.

![Facebook Message](https://github.com/srsaidas/Programming-for-the-Internet-of-Things-Project/blob/master/image/fb_message.png)
 When I typed on/off fan, fan on/off, switch on/off fan ( I have added these commands we can add more)

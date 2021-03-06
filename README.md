# Facebook Messenger and AWS IoT Core for Home Automation
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
To communicate with nodeMCU I have created a facebook page and is linked with Amazon lex. lex will identify the message and send a command to AWS lambda to publish a MQTT topic 'home/room/light' with payload corresponding to facebook message. 

if node MCU is subscribe to this topic it will trigger the nodeMCU and run the command to turn on or off the relay.

![Facebook Message](https://github.com/srsaidas/Programming-for-the-Internet-of-Things-Project/blob/master/image/fb_message.png)
 When I typed on/off fan, fan on/off, switch on/off fan ( I have added these commands we can add more) it will trigger MQTT broker to publish the topic  'home/room/light' 

`    response = client.publish(topic='home/room/light',qos=1,payload=json.dumps({"message":"LED "+led_status}))
`
 
 ## DHT 11 to Relay 
 In this project, I have connected DHT11 Sensor (Temperature Humidity Sensor ) is connected to Arduino UNO.  and UNO is connected to Raspberry Pi. I have used I2C communication between UNO and Raspberry pi where Raspberry Pi is the master and UNO is slave. every 5 sec Master(Raspberry pi) will send a Write request to slave (UNO). Up receiving it will read the temperature using DHT11. and send that information to Raspberry pi

Raspberry pi will process that temperature data and check whether it is greater than threshold. if yes it will set a flag. when ever there is a change in flag vakue t will publish 'home/room/light' whith data to NodeMCU 

## MQTT Payload 
I have used json data as MQTT payload since it is very easy to serialize and deserialize data and have  built-in data type which can be used very easily with json like dictionary in python  associative arrays in PHP etc

# Technology Used
I2C, MQTT, AWS IoT Core, AWS lambda, AWS lex, json 

# Working 
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg)](https://www.youtube.com/watch?v=YOUTUBE_VIDEO_ID_HERE)

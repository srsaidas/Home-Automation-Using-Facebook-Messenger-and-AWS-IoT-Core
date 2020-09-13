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
To communicate with nodeMCU I have created a facebook page and is linked with Amazon lex. lex will identify the message and send a command to AWS lambda to publish a MQTT topic 'home/room/light'. The node MCU is subscribe to this topic and run the command to turn on or off the relay.

![Facebook Message](https://github.com/srsaidas/Programming-for-the-Internet-of-Things-Project/blob/master/image/fb_message.png)
 When I typed on/off fan, fan on/off, switch on/off fan ( I have added these commands we can add more) it will trigger MQTT broker to publish the topic  'home/room/light' 

`import json
import boto3

def lambda_handler(event, context):
    
    client = boto3.client('iot-data')
    led_status =event['currentIntent']['slots']['slotOne']
    led_status = led_status.upper()
    response = client.publish(topic='home/room/light',qos=1,payload=json.dumps({"message":"LED "+led_status}))

    # TODO implement
    response = {
        "dialogAction": 
            {"type": "Close",
            "fulfillmentState": "Fulfilled",
            "message": {
                "contentType": "PlainText",
                "content": "Your fan  is " + led_status
            }
        }
};
`
 
 ## DHT 11 to Relay 
 In this project, I have connected DHT11 Sensor (Temperature Humidity Sensor ) is connected to Arduino UNO.  and UNO is connected to Raspberry Pi. I have used I2C communication between UNO and RPi where RPi is the master and UNO is slave. every 5 sec Master(RPI) will send a Write request to slave (UNO). Up receiving it will read the temperature using DHT11. and send that information to RPI

Rpi will process that temperature data and check whether it is greater than threshold. if yes it will set command 

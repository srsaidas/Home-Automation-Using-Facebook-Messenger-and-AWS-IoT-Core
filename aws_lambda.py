 import json
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
    return response
  
 

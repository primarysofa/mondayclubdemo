# Monday Club
## Connecting temperature and humidity sensor to the cloud via a micro-controller
This a demonstration of connecting a temperature and humidity sensor to the cloud using a micro-controller.
When it works, the data can be viewed [here on Thinkspeak](https://thingspeak.mathworks.com/channels/1656908)

## Parts list
- (from £1) DHT11 temperature and humidity sensor
- (from £4) NodeMCU microcontroller
- (pence) female connecting wires
- micro usb cable
- Wifi hotspot

## Connect sensor to micro-controller
Connect the DHT11 to the NodeMCU as follows, this is the [pinout diagram](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/ESP8266-NodeMCU-kit-12-E-pinout-gpio-pin.png?quality=100&strip=all&ssl=1) for the NodeMCU:
- DHT11 +ve to NodeMCU 3.3v
- DHT11 -ve to NodeMCU GND
- DHT11 data to NodeMCU GPIO2 (D4)

# Code setup and upload

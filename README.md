# Monday Club
## Connecting temperature and humidity sensor to the cloud via a micro-controller
This a demonstration of connecting a temperature and humidity sensor to the cloud using a micro-controller.
When it works, the data can be viewed [here on Thinkspeak](https://thingspeak.mathworks.com/channels/1656908)

## Parts list
- (from £1) [DHT11](https://thepihut.com/products/dht11-temperature-humidity-sensor) temperature and humidity sensor
- (from £4) [NodeMCU](https://en.wikipedia.org/wiki/NodeMCU) microcontroller
- (pence) female connecting wires
- micro usb cable
- Wifi hotspot

## Connect sensor to micro-controller
Connect the DHT11 to the NodeMCU as follows, this is the [pinout diagram](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/ESP8266-NodeMCU-kit-12-E-pinout-gpio-pin.png?quality=100&strip=all&ssl=1) for the NodeMCU:
- DHT11 +ve to NodeMCU 3.3v
- DHT11 -ve to NodeMCU GND
- DHT11 data to NodeMCU GPIO2 (D4)

# Code setup and upload
- Install [Arduino IDE](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE)
- Clone this repo
- Open Arduino IDE and then File > Open > tempMoisture.ino
- Add a new file called arduino_secrets.h to root to contain secrets (do not put into version control).  It should contain the following:
```
#define SECRET_SSID "Wifi SSID"
#define SECRET_PASSWORD "Wifi password"
#define SECRET_CHANNEL_NUMBER Thinspeak channel number (integer, so not enclosed in quotes)
#define SECRET_API_WRITE_KEY "Thingspeak channel api write key"
```
- Install this DHT11 library: Sketch > Include Library > Manage Libraries... > Search for 'DHT11 saha' - there should only be one result, select it to install (really worth seeing the [README](https://github.com/dhrubasaha08/DHT11) for this library)
- Select the NodeMCU board: Tools > Board > esp2866 > NodeMCU 1.0 (ESP-12E Module)
- Connect USB cable to NodeMCU and laptop and then Tools > Port > select your USB connection
- Upload and run your code: Sketch > Upload

# Thingspeak setup
[Thingspeak](https://thingspeak.mathworks.com/pages/learn_more) is a IoT platform with a free tier that I've been using to upload sensor data to.  For free, it allows you to setup 4 channels to upload to, with 8 fields per channel, so in our example we need 1 channel that will receive data for the two fields temperature and moisture.  The free tier allows you to upload data every 15s, with a maximum of 3 million uploads per year.

Hopefully, if you're interested it won't take you long to create an account, create a new channel and add the channel number and api key to the arduino_secrets.h file created above.

[Here is the temperature and moisture channel](https://thingspeak.mathworks.com/channels/1656908) for the Monday Club demo just for showing the data.

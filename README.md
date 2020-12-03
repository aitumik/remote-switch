# remoteswitch
Swtching on and off leds remotely(over the internet) Just like a smart home

## Setup
### Requirements
* Arduino IDE
* esp8266 board

### Setup the arduino ide to support esp8266 mcu
* Install Arduino IDE
* Setup Arduino to allow ESP8266 code to be compiled


### Turning on the Led
First of all make sure you are on the same network with the arduino/esp8266
Connect to the esp8266 by using esptool:
```bash
esptool --port <the port of your board> --baud=<baudrate> writ_flash
--flash-size=detect 0 <location to your firmware>
```
Read the Local IP of the Arduino board/esp8266 from either the serial monitor
or still using picocom
```bash
picocom /dev/ttyUSB0 --baud=115200
```
You should then copy the IP address on the ouptut after it has finished
connecting to the  internet

Send a request to the endpoint with a specific parameter like ON/OFF
```bash
curl http://<ip address of the boar>/LED=OFF
```

```bash
curl http://<ip address of the boar>/LED=OFF
```

If you setup the board correctly the led should turn on and off with commands
you send


# Contributionint
I don't actively support this project so you might want to reduce your pull
requests 
# License
MIT

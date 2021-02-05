CLI  = arduino-cli
FQBN = arduino:mbed:nano33ble
PORT = /dev/ttyACM98 # for arduino nano BLE
INO  = uart.ino

build: 
	$(CLI) compile --fqbn $(FQBN) $(INO)

upload:
	$(CLI) upload -p $(PORT) --fqbn $(FQBN) $(INO) 

all: build	upload

CLI  = arduino-cli
FQBN = arduino:samd:mkr1000
PORT = /dev/ttyACM0
INO  = button_class.ino
WARN = --warnings all

build: 
	$(CLI) compile --fqbn $(FQBN) $(INO) $(WARN)

upload:
	$(CLI) upload -p $(PORT) --fqbn $(FQBN) $(INO) 

all: build	upload

CLI  = arduino-cli
FQBN = arduino:samd:mkr1000
PORT = /dev/ttyACM0
INO  = empty.ino

build: 
	$(CLI) compile --fqbn $(FQBN) $(INO)

upload:
	$(CLI) upload -p $(PORT) --fqbn $(FQBN) $(INO) 

all: build	upload

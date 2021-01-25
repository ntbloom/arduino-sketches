CLI  = arduino-cli
FQBN = arduino:samd:mkr1000
PORT = /dev/ttyACM99
INO  = basic_lcd.ino

build: 
	$(CLI) compile --fqbn $(FQBN) $(INO)

upload:
	$(CLI) upload -p $(PORT) --fqbn $(FQBN) -v $(INO)

all: build upload

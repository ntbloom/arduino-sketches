//TODO: set up LCD Screen

//TODO: set up rain gauge counter

//TODO: set up temperature monitor

//TODO: set up TLV encoding

//TODO: set up serial comms for receiving data

void setup() {
  // write me!
}

void loop() {

  // check for rain event
  // if rain event
    // increment rain counter
    // tell serial port 
    // flip LCD flag 

  // check clock to determine whether to measure temp (1 per minute?)
  // if time
    // measure temp
    // flip LCD flag
    // if regular interval (1 hr?), send to serial

  // check for reset button press
  // if press
    // set rain counter to zero
    // ask serial for timestamp

  // check serial port for input
  // switch on input
  // case timestamp
    // parse timestamp
    // update LCD flag
  // case status update
    // respond to status update 

  // check LCD flag
  // if LCD flag
    // update data structure (struct? object?)
    // clear screen
    // write to screen
   
}

#include <Arduino.h>
#include "Dial.h"

// Be careful about printing debug messages over serial! They appear to
// sometimes interfere with the scroll events, somehow (at least on ubuntu
// 18.04).

const uint8_t dial_a_pin = 11; // pin must have full interrupt support
const uint8_t dial_b_pin = 12; // pin must have full interrupt support
const uint8_t button_pin = 14;

const uint16_t loop_millisecs = 5;

Dial dial(dial_a_pin, dial_b_pin, button_pin);

// What to do when the dial's button is pressed
void pressEvent(){
  // Type a single space character
  Keyboard.print(" ");
}

// What to do when the dial has rotated the given distance since we last checked
void rotateEvent(int32_t distance){
  keysOnRotate(distance);
}

// Send scroll wheel events
void mouseOnRotate(int32_t distance){
  Mouse.scroll(distance);
}

// Type up arrows for one direction and down arrows for the other
void keysOnRotate(int32_t distance){
  uint32_t key_code = 0;
  if(distance == 0) {
    return;
  } else if(distance > 0) {
    key_code = KEY_UP;
  }  else {
    key_code = KEY_DOWN;
  }

  uint32_t num_presses = abs(distance);
  for(uint32_t i = 0; i < num_presses; i++) {
    Keyboard.press(key_code);
    Keyboard.release(key_code);
  }
}



void setup() {
}

void loop() {
  if (dial.button.update()) {
    if (dial.button.fallingEdge()) {
      pressEvent();
      dial.reset();
    }
  }

  int32_t distance = dial.distance();
  if (distance != 0) {
    rotateEvent(distance);
  }

  delay(loop_millisecs);
}

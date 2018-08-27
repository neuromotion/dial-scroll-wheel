#include "Dial.h"

#define DEBOUNCE_MILLISECS 10

Dial::Dial(uint8_t dial_a_pin, uint8_t dial_b_pin, uint8_t button_pin)
  : button(button_pin, DEBOUNCE_MILLISECS), encoder(dial_a_pin, dial_b_pin)
{
  pinMode(button_pin, INPUT_PULLUP);
}

int32_t Dial::distance() {
  int32_t new_position = position();
  int32_t difference = previous_position - new_position;
  previous_position = new_position;
  return difference;
}


int32_t Dial::position() {
  return scale(encoder.read());
}

void Dial::reset() {
  encoder.write(0);
  previous_position = 0;
}

int32_t Dial::scale(int32_t unscaled_steps) {
  return unscaled_steps * desired_steps_per_click / original_steps_per_click ;
}


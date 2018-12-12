#include "Dial.h"

// How long to debounce button presses for, to be sure they're not just noise
#define DEBOUNCE_MILLISECS 10

Dial::Dial(uint8_t dial_a_pin, uint8_t dial_b_pin, uint8_t button_pin)
  : button(button_pin, DEBOUNCE_MILLISECS), encoder(dial_a_pin, dial_b_pin)
{
  pinMode(button_pin, INPUT_PULLUP);
}

// Return how far the dial has turned (in scaled steps) since the last time this
// function was called or the dial was reset.
int32_t Dial::distance() {
  int32_t new_position = position();
  int32_t difference = previous_position - new_position;
  previous_position = new_position;
  return difference;
}

// Return the current relative dial position in scaled steps.
int32_t Dial::position() {
  return scale(encoder.read());
}

// Reset the relative dial position to zero.
void Dial::reset() {
  encoder.write(0);
  previous_position = 0;
}

// Convert the raw encoder step count to a nice scaled count for the user to see.
int32_t Dial::scale(int32_t unscaled_steps) {
  return unscaled_steps * desired_steps_per_click / original_steps_per_click;
}


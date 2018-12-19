#ifndef DIAL_H_
#define DIAL_H_

#include <Arduino.h>
#include <Encoder.h>
#include <Bounce.h>

// TODO use typedefs for raw_pos_t and user_pos_t, like in the provocation-arduino repository's dial code, to prevent confusion.

/// Represents a dial with a mechanical rotary encoder and a pushbutton.
class Dial {
 public:
  Dial(uint8_t dial_a_pin, uint8_t dial_b_pin, uint8_t button_pin);
  int32_t position();
  void reset();
  int32_t distance();

  // Be lazy and use the Bounce library to handle button debouncing
  Bounce button;

 private:
  int32_t scale(int32_t unscaled_steps);

  Encoder encoder;
  int32_t previous_position = 0;

  // Many mechanical encoders have tactile clicks/bumps as you rotate them. It's
  // nice if this class's public interface gives position in terms of number of
  // clicks, instead of the raw output from the Encoder library. These constants
  // control the scaling between the two.
  const uint8_t original_steps_per_click = 4;
  const uint8_t desired_steps_per_click = 1;
};

#endif

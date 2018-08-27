#ifndef DIAL_H_
#define DIAL_H_

#include <Arduino.h>
#include <Encoder.h>
#include <Bounce.h>

// TODO use typedefs for raw_pos_t and user_pos_t, like in provocation code, to prevent confusion

class Dial {
 public:
  Dial(uint8_t dial_a_pin, uint8_t dial_b_pin, uint8_t button_pin);
  int32_t position();
  void reset();
  int32_t distance();

  Bounce button;

 private:
  int32_t scale(int32_t unscaled_steps);

  Encoder encoder;
  const uint8_t original_steps_per_click = 4;
  const uint8_t desired_steps_per_click = 1;
  int32_t previous_position = 0;
};

#endif

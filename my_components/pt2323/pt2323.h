#pragma once

#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace pt2323 {

class PT2323Component : public PollingComponent, public i2c::I2CDevice {

 public:
  PT2323Component() {}     // Constructor for the PT2323 component

  void setup() override;
  void update() override;
  void dump_config() override;

  
  float get_setup_priority() const override;    // Determines the order in which setup() methods are called on startup



  // Public methods to control the PT2323 device
  void setInput(int in);
  void setMute(int fl, int fr, int ct, int sub, int sl, int sr, int mute);
  void setFeature(int surr, int mix);



protected:
void write_byte(uint8_t data);    // Protected method to send a single byte to the PT2323 via I2C

private:
// Internal methods or variables can be added here if necessary
};

} // namespace pt2323
} // namespace esphome
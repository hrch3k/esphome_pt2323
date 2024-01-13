#pragma once

#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace pt2323_i2c_component {

class Pt2323I2CComponent : public i2c::I2CDevice, public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
};


}  // namespace pt2323_i2c_component
}  // namespace esphome
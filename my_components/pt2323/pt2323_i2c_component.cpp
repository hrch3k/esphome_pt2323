#include "esphome/core/log.h"
#include "pt2323_i2c_component.h"

namespace esphome
{
    namespace pt2323_i2c_component
    {

        static const char *TAG = "pt2323_i2c_component.component";

        void Pt2323I2CComponent::setup() { ESP_LOGD(TAG, "Setup called"); }

        void Pt2323I2CComponent::loop() {}

        void Pt2323I2CComponent::dump_config() { ESP_LOGCONFIG(TAG, "Pt2323 I2C component"); }

    } // namespace pt2323_i2c_component
} // namespace esphome
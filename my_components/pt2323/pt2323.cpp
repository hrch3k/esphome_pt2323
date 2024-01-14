#include "pt2323.h"
#include "esphome/core/log.h"

namespace esphome
{
    namespace pt2323
    {

        // TAG used for logging
        static const char *const TAG = "pt2323";

        // Setup function called when the component is initialized
        void PT2323Component::setup()
        {
            ESP_LOGCONFIG(TAG, "Setting up PT2323");
            // Any initial setup can be performed here
        }

        // Update function called at a regular interval defined in the configuration
        void PT2323Component::update()
        {
            // Update logic goes here, if necessary
        }

        // Returns the setup priority of the component
        float PT2323Component::get_setup_priority() const
        {
            return setup_priority::DATA;
        }

        // Dumps the configuration of the component for debugging purposes
        void PT2323Component::dump_config()
        {
            ESP_LOGCONFIG(TAG, "PT2323:");
            LOG_I2C_DEVICE(this);
        }

        // Sets the input of the PT2323 device
        void PT2323Component::setInput(int in)
        {
            uint8_t command;
            switch (in)
            {
            case 0:
                command = 0b11001011;
                break;
            case 1:
                command = 0b11001010;
                break;
            case 2:
                command = 0b11001001;
                break;
            case 3:
                command = 0b11001000;
                break;
            case 4:
                command = 0b11000111;
                break;
            }
            this->write_byte(command);
        }

        /*
         Sets the mute state of different channels on the PT2323 device
         fl, fr, ct, sub, sl, sr, mute all
         MUTE OFF for outputs (0,0,0,0,0,0,0);
         MUTE ON for outputs (1,1,1,1,1,1,1);
        */

        void PT2323Component::setMute(int fl, int fr, int ct, int sub, int sl, int sr, int mute)
        {
            this->write_byte(fl == 1 ? 0b11110001 : 0b11110000);
            this->write_byte(fr == 1 ? 0b11110011 : 0b11110010);
            this->write_byte(ct == 1 ? 0b11110101 : 0b11110100);
            this->write_byte(sub == 1 ? 0b11110111 : 0b11110110);
            this->write_byte(sl == 1 ? 0b11111001 : 0b11111000);
            this->write_byte(sr == 1 ? 0b11111011 : 0b11111010);
            this->write_byte(mute == 1 ? 0b11111111 : 0b11111110);
        }

        /*
        Sets additional features of the PT2323 device
        0 - Enhanced Surround Function Active
        1 - Enhanced Surround Function Disabled
        0 - Mixed Channel (0dB) Setup
        1 - Mixed Channel (+6dB) Setup
        */
        void PT2323Component::setFeature(int surr, int mix)
        {
            this->write_byte(surr == 0 ? 0b11010000 : 0b11010001);
            this->write_byte(mix == 0 ? 0b10010000 : 0b10010001);
        }

        // Sends a byte of data to the PT2323 device over I2C
        void PT2323Component::write_byte(uint8_t data)
        {
            const uint8_t data_array[] = {data};
            if (this->write(data_array, 1) != i2c::ERROR_OK)
            {
                ESP_LOGE(TAG, "Failed to write to PT2323");
            }
        }

    } // namespace pt2323
} // namespace esphome
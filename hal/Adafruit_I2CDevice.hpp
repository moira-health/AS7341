#ifndef ADAFRUIT_I2C_DEVICE_HPP
#define ADAFRUIT_I2C_DEVICE_HPP

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <cstdint>
#include <iostream>

class Adafruit_I2CDevice
{
   public:
    Adafruit_I2CDevice(uint8_t address, const char *i2c_device);
    ~Adafruit_I2CDevice();

    bool begin();
    bool write(uint8_t reg, uint8_t *data, size_t length);
    bool read(uint8_t reg, uint8_t *buffer, size_t length);
    uint8_t read(uint8_t reg);

   private:
    int file;
    uint8_t i2c_address;
};

#endif  // ADAFRUIT_I2C_DEVICE_HPP
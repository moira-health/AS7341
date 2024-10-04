#include "Adafruit_I2CDevice.hpp"

#include <cstring>

Adafruit_I2CDevice::Adafruit_I2CDevice(uint8_t address, const char *i2c_device)
{
    i2c_address = address;
    file = open(i2c_device, O_RDWR);
    if (file < 0)
    {
        std::cerr << "Failed to open I2C device: " << i2c_device << std::endl;
    }

    if (ioctl(file, I2C_SLAVE, i2c_address) < 0)
    {
        std::cerr << "Failed to communicate with I2C address: "
                  << static_cast<int>(i2c_address) << std::endl;
    }
}

Adafruit_I2CDevice::~Adafruit_I2CDevice() { close(file); }

bool Adafruit_I2CDevice::begin() { return file >= 0; }

bool Adafruit_I2CDevice::write(uint8_t reg, uint8_t *data, size_t length)
{
    uint8_t buffer[length + 1];
    buffer[0] = reg;
    memcpy(&buffer[1], data, length);
    if (::write(file, buffer, length + 1) != length + 1)
    {
        std::cerr << "Failed to write to I2C device" << std::endl;
        return false;
    }
    return true;
}

uint8_t Adafruit_I2CDevice::read(uint8_t reg)
{
    if (::write(file, &reg, 1) != 1)
    {
        std::cerr << "I2C: Failed to select register" << std::endl;
        return 0;
    }
    uint8_t data;
    if (::read(file, &data, 1) != 1)
    {
        std::cerr << "Failed to read from I2C device" << std::endl;
    }
    return data;
}

bool Adafruit_I2CDevice::read(uint8_t reg, uint8_t *buffer, size_t length)
{
    if (::write(file, &reg, 1) != 1)
    {
        std::cerr << "I2C: Failed to select register" << std::endl;
        return false;
    }
    if (::read(file, buffer, length) != length)
    {
        std::cerr << "Failed to read from I2C device" << std::endl;
        return false;
    }
    return true;
}
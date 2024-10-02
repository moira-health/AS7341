#ifndef ADAFRUIT_BUS_IO_REGISTER_HPP
#define ADAFRUIT_BUS_IO_REGISTER_HPP

#include "Adafruit_I2CDevice.hpp"

class Adafruit_BusIO_Register
{
   public:
    Adafruit_BusIO_Register(Adafruit_I2CDevice *i2c_dev, uint8_t reg,
                            size_t len = 1, uint8_t order = 1);

    uint8_t read();
    bool read(uint8_t *buffer, size_t length);
    bool write(uint8_t value);
    bool write(uint8_t *data, size_t length);

   private:
    Adafruit_I2CDevice *i2c_dev;
    uint8_t reg_address;
    size_t len;
    uint8_t bit_order;
};

class Adafruit_BusIO_RegisterBits
{
   public:
    Adafruit_BusIO_RegisterBits(Adafruit_BusIO_Register *reg, uint8_t bits,
                                uint8_t shift);

    bool write(uint32_t value);
    uint32_t read(void);

   private:
    Adafruit_BusIO_Register *_register;
    uint8_t _bits, _shift;
};

#endif  // ADAFRUIT_BUS_IO_REGISTER_HPP
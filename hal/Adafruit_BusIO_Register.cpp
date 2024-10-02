#include "Adafruit_BusIO_Register.hpp"

Adafruit_BusIO_Register::Adafruit_BusIO_Register(Adafruit_I2CDevice *i2c_dev,
                                                 uint8_t reg, size_t len,
                                                 uint8_t order)
    : i2c_dev(i2c_dev), reg_address(reg), len(len), bit_order(order)
{
}

uint8_t Adafruit_BusIO_Register::read() { return i2c_dev->read(reg_address); }

bool Adafruit_BusIO_Register::read(uint8_t *buffer, size_t length)
{
    return i2c_dev->read(reg_address, buffer, length);
}

bool Adafruit_BusIO_Register::write(uint8_t value)
{
    return i2c_dev->write(reg_address, &value, 1);
}

bool Adafruit_BusIO_Register::write(uint8_t *data, size_t length)
{
    return i2c_dev->write(reg_address, data, length);
}

Adafruit_BusIO_RegisterBits::Adafruit_BusIO_RegisterBits(
    Adafruit_BusIO_Register *reg, uint8_t bits, uint8_t shift)
    : _register(reg), _bits(bits), _shift(shift)
{
}

bool Adafruit_BusIO_RegisterBits::write(uint32_t value)
{
    uint32_t reg_value = _register->read();
    uint32_t mask = ((1 << _bits) - 1) << _shift;
    reg_value &= ~mask;
    reg_value |= (value << _shift) & mask;
    return _register->write(reg_value);
}

uint32_t Adafruit_BusIO_RegisterBits::read(void)
{
    uint32_t reg_value = _register->read();
    uint32_t mask = ((1 << _bits) - 1) << _shift;
    return (reg_value & mask) >> _shift;
}
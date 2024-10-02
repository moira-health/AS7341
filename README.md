# Adafruit AS7341 (RPi5-Port)

This is a version of the Adafruit AS7341 11-Channel Spectral Sensor for Arduino, adapted to work on the Raspberry Pi 5.

The HAL files have been added to correctly control i2c hardware on the Pi. Some changes in main have been made to remove Arduino dependencies.

This library can be added to a projects as a component, and imported into that project by adding as a library using the project CMakeLists.txt.

Uses the `/dev/i2c-1` interface which uses the following pins:
- SDA1 : Pin 03 : GPIO02
- SCL1 : Pin 05 : GPIO03
# ESP8266-Accelerometer-Data-Transfer
Learning how to get the ESP8266 to transfer data from an accelerometer on Wifi connection to a data server hosted on a Raspberry Pi 3.

## Information on Hardware Used

### ESP-8266

The NodeMCU ESP8266 from Espressif Systems is a self-contained SOC w/ TCP/IP protocol stacks that can enable you to use Wifi on any microcontroller through SPI, I2C, or UART interfaces. This microcontroller uses a 32-bit RISC Tensilica L106 core processor meaning that it can handle the same processes as a regular microcontroller. This is what I have used to read the data from an IMU using I2C communication (a half-duplex communication protocol w/ multi-master/slave).

For more information on the ESP8266 you can click [here](https://www.taydaelectronics.com/datasheets/files/A-2194.pdf)

### Adafruit MPU-6050

The MPU 6050 is a 6-axis accelerometer and gyroscope that uses 16-bit measurements. This means that our ESP8266 module can work with the MPU 6050. You typically connect both VCC and GND to the microcontroller to allow current for proper communication, and SDA and SCL to the appropriate pins for serial data and serial Clock on the microcontroller. The SDA is the line for transmitting data and the SCL is the timing of the transmission of the data. The I2C address on the IMU is 0x68. The library that I used for the MPU 6050 was the Electronic Cats MPU-6050 library. https://github.com/ElectronicCats/mpu6050

For more information on the MPU-6050 you can click [here](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)

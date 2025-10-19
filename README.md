# Real-Time Data Visualization using MING IoT Stack
Data-visualization project at 0.2hz using MING IoT stack and Helix on Raspberry Pi single-board computer flashed with Ubuntu Server operating system.

## Information on Hardware Used

### Adafruit MPU-6050

The MPU 6050 is a 6-axis accelerometer and gyroscope that uses 16-bit measurements. This means that our ESP8266 module can work with the MPU 6050. You typically connect both VCC and GND to the microcontroller to allow current for proper communication, and SDA and SCL to the appropriate pins for serial data and serial Clock on the microcontroller. The SDA is the line for transmitting data and the SCL is the timing of the transmission of the data. The I2C address on the IMU is 0x68. The library that I used for the MPU 6050 was the Electronic Cats MPU-6050 library. https://github.com/ElectronicCats/mpu6050

For more information on the MPU-6050 you can click <a href="https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf" target="_blank">here.</a>

### Raspberry Pi 3 Model B

The Raspberry Pi 3 Model B is a single board computer that adds wireless LAN and Bluetooth 4.1 connectivity. It comes with a Broadcom BCM2387, quad-core ARM Cortex-A53 processor that runs at 1.2 Ghz. It also comes with an HDMI connecter for video and local memory storage in the form of microSD. This board is perfect for hosting a data/IoT server since it can hold up to 32GB with the microSD card that we received.

For more information on the Raspberry Pi 3 Model B you can click <a href="https://us.rs-online.com/m/d/4252b1ecd92888dbb9d8a39b536e7bf2.pdf?srsltid=AfmBOooFU4ZGljZ3GYlqCJjr7USwgSgOPvigFI2DjveNFrXGUp18ZZSt" target="_blank">here.</a>

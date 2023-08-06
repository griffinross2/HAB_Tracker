# HAB_Tracker
A high-altitude balloon tracker based on STM32WLE5. Built in STM32CubeIDE.

## Credit
Credit to dragonlock2 for APRS code.

Credit to cnnblike for OneWire implementation.

Credit to rromano001 for UART full duplex hack.

Credit to my friends at Purdue Space Program for various drivers and sensor libraries written for our flight computer.

## Hardware
The hardware consists of an original tracker design on a custom board. 

  ### Tracking
  The GPS is a Ublox MAX-M10S module supporting an active antenna.
  
  The primary radio is a Radiometrix HX1 FM transmitter, intended to transmit APRS packets on 144.39 MHz.

  The secondary radio is the STM32WL's built-in LoRa transmitter. It is configured to operate in the 70cm band.
  
  Both radios share a single SMA connector.

  ### Sensors
  The board has an MS5637 barometer/temp sensor, a DS18B20 temperature probe, an LSM6DSOX accelerometer/gyro, an IIS2MDC magnetometer, and a microSD card slot for logging.
  
  ### Other Features
  The board also features a USB type A port for powering devices like action cameras, as well as an adjustable voltage source for a heating element.
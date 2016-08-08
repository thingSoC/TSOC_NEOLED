# TSOC_NEOLED

**TSOC_NEOLED** is a Eight-Channel WS2812 LED driver expansion board, and can drive
eight (8) to sixteen(16) strips of individually addressable Light Emitting Diodes (LEDs). 

**TSOC_NEOLED** uses a programmable system on chip (PSoC4) with an eight (8) channel driver
to drive hundreds of WS2812 Color LED's, with a default arrangement of 8 (eight strings) of sixty-four(64) LEDs each.

The **TSOC_NEOLED** can provide several different intefaces in order to make
interfacing large numbers of LEDs easy. The default protocol is an I2C interface :

1) I2C Serial DMX-512, Memory Mapped (**TSOC_NEOLED** looks like a 2048 byte I2C SRAM)

Other Interface protocols are possible (Firmware update using FTDI/USB-UART or JTAG) :

- UART Serial DMX-512 (200K Baud, N, 8, 1) with four DMX universes.

- SPI Serial DMX-512, Memory Mapped (**TSOC_NEOLED** looks like a 2048 byte SPI SRAM)


[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/product/TSOC_NEOLED.png?raw=true)TSOC_NEOLED](https://github.com/thingSoC/TSOC_NEOLED)

**thingSoC Reference Designs** are example thingSoC implementations that implement
various reference and testing circuits for demonstrating the use of the thingSoC libraries.
These reference designs can serve as starting templates for user designs.

---------------------------------------

## TSOC_NEOLED Application Pictures

Using the TSOC_NEOLED to drive eight(8) strings of color LEDs for lighting our tandem bike for Portland PedalPolooza 2016

[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/light_the_ride2.png?raw=true)*TSOC_NEOLED*](https://github.com/thingSoC/TSOC_NEOLED)

---------------------------------------

## TSOC_NEOLED Arduino Sketch Examples

Under the "examples" directory are several Arduino IDE examples for using the TSOC_NEOLED board with Arduino IDE.
Using the Arduino "Wire" library for I2C communications, it is simple to control the TSOC_NEOLED

```c
  // Start the Arduino I2C Interface
  wire.begin();
 

  // Turn the first LED On (i.e. green LED #1) 
  // the LED's are (GRBY) color order in memory
  byte row, column = 0;
  Wire.beginTransmission(TSOC_NEOLED_I2CADDRESS);  // Start the I2C transaction
  Wire.write(row);                                 // Send the high byte of 16 bit memory address
  Wire.write(column);                              // Send the low byte of 16 bit memory address
  Wire.write(TSOC_NEOLED_LED_ON);                  // Send a single data byte  (we could send more...)
  Wire.endTransmission();                          // End the I2C transaction
 
  // Turn the first LED Off (i.e. green LED #1) 
  // the LED's are (GRBY) color order in memory
  Wire.beginTransmission(TSOC_NEOLED_I2CADDRESS);  // Start the I2C transaction
  Wire.write(row);                                 // Send the high byte of 16 bit memory address
  Wire.write(column);                              // Send the low byte of 16 bit memory address
  Wire.write(TSOC_NEOLED_LED_OFF);                  // Send a single data byte  (we could send more...)
  Wire.endTransmission();                          // End the I2C transaction
 
 
```

---------------------------------------
## TSOC_NEOLED Programming

You can reprogram the board using any FTDI compatible USB to UART adapter :

[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/product/TSOC_NEOLED_with_FTDI.png?raw=true)TSOC_NEOLED with FTDI basic](https://github.com/thingSoC/TSOC_NEOLED)


[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/product/TSOC_NEOLED_with_usbuart2.png?raw=true)TSOC_NEOLED with TSOC_USBUART2](https://github.com/thingSoC/TSOC_NEOLED)


[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/product/TSOC_NEOLED_with_usbuart2_1.png?raw=true)TSOC_NEOLED with TSOC_USBUART2](https://github.com/thingSoC/TSOC_NEOLED)


In order to reprogram the Cypress PSoC4 device, you will need to download and install the PSoC Creator tool, which includes a serial bootloader host application.

Select Tools -> Bootloader Host 

Then select the hex (cyacd) file that you wish to program, and the COM: port of your device. Proess the "Upload" button to reflash teh device.

[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/product/TSOC_NEOLED_bootloader.png?raw=true)PSoC Creator Bootloader Host](https://github.com/thingSoC/TSOC_NEOLED)


---------------------------------------
## Other Applications

The TSOC_NEOLED can also drive other devices, such as Servos, Motors, Realys and more.
This requires custom firmware at the current time.

[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/product/TSOC_NEOLED_servo.png?raw=true)TSOC_NEOLED with Servo](https://github.com/thingSoC/TSOC_NEOLED)


---------------------------------------

## TSOC_NEOLED Status <a name="TSOC_NEOLED_status"/>

**04/28/2016:** 
Revision 1.1 - Initial Layout with Eight(8) channel driver.

**06/27/2016:**
Revision 1.2 - Added extra power connections for higher current support.


**07/26/2016:**
Revision 2.0 -

               Moved extra jumpers to the Digital Programming Connector (i.e. boot-mode control).

               Added SAR Bypass capactitors in their place.  
               
               Misc Silkscreen clean up.  
               
               Add Fiducials and DFM cleanup.

---------------------------------------
## TSOC_NEOLED Model Images


[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/TSOC_NEOLED_top.png?raw=true)TSOC_NEOLED](https://github.com/thingSoC/TSOC_NEOLED)


[![thingSoC TSOC_NEOLED](https://raw.githubusercontent.com/thingSoC/TSOC_NEOLED/master/TSOC_NEOLED/images/TSOC_NEOLED_bot.png?raw=true)TSOC_NEOLED](https://github.com/thingSoC/TSOC_NEOLED)


---------------------------------------

## TSOC_NEOLED Documentation Index <a name="TSOC_NEOLED_documentation_index"/>

[TSOC_NEOLED Project](http://thingsoc.github.io/projects/TSOC_NEOLED.html)

[TSOC_NEOLED Hardware](https://github.com/thingSoC/TSOC_NEOLED/tree/master/TSOC_NEOLED/hardware)


---------------------------------------

## thingSoC Documentation Index <a name="thingSoC_documentation_index"/>

[thingSoC Organization Website](http://thingSoC.github.io)

[thingSoC FAQ - Frequently Asked Questions](http://thingsoc.github.io/support/faq.html)

---------------------------------------

[![thingSoC](http://thingsoc.github.io/img/projects/thingSoC/thingSoC_thumb.png?raw=true) 
*thingSoC*](http://thingsoc.github.io)

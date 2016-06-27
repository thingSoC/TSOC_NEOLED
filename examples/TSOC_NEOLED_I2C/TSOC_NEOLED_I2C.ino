/*  ------------------------------------------
 *  TSOC_NEOLED I2C (2-Wire) Interface Example
 *  ------------------------------------------
 *  
 *  The TSOC_NEOLED Board is a programmable LED driver
 *  board for strings of WS2812 Color LEDs. The factory
 *  default programming for the TSOC_NEOLED supports up to
 *  eight (8) strings of 64 LEDs per string (512 LEDs total). 
 *  The TSOC-NEOLED allocates eight(8) bits (one byte) each 
 *  for Red, Green, Blue, and also a Yellow/White channel,
 *  for a 32 bit value per LED, or a total of 2048 bytes.
 *  
 *  The color ordering (byte address) is as follows :
 *  0 - LED0 Green
 *  1 - LED0 Red
 *  2 - LED0 Blue
 *  3 - LED0 Yellow
 *  4 - LED1 Green
 *  5 - LED1 Red
 *  6 - LED1 Blue
 *  7 - LED1 Yellow
 *  
 *  The TSOC_NEOLED looks to the Arduino like an I2C SRAM (memory) 
 *  of 2048 bytes in size. Simply writing to the TSOC_NEOLED like an
 *  I2C memory caues the corresponding LED to light up on the display.
 *  
 *  If the LEDs are RGB only type, then the Yellow channel is not used,
 *  however the addressing remains the same, that is to say, memory is 
 *  reserved for the Yellow/White channel, even if it is not used.
 *  
 *  If the LED string (or matrix panel) is less than 64 LEDs (i.e. string of 30 or 60),
 *  then the extra LED positions are not used, however the addressing remains the same, 
 *  that is to say, memory is reserved for 64 LEDs per string, even if it is less than that.
 *  
 *  The Default I2C address for the TSOC_NEOLED is 8 (Seven bits).
 *  
 *  This simple example lights each color of each LED in sequence,
 *  from low addresses to high addresses.
 *  
 */
#include <Wire.h>
#define TSOC_NEOLED_I2CADDRESS         8  // default I2C address
#define TSOC_NEOLED_LED_PER_STRING    64  // default number of LEDs per string
#define TSOC_NEOLED_NUM_STRINGS        1  // set this to the number of strings installed (max=8)
#define TSOC_NEOLED_NUM_COLORS         4  // default is RGBY color space
#define TSOC_NEOLED_LED_ON          0xFF  // LED full brightness
#define TSOC_NEOLED_LED_OFF         0x00  // LED off
#define TSOC_NEOLED_LED_DELAY        100  // Delay to process the I2C write transaction

void setup() {
 Wire.begin();  // Start the Arduino I2C interface
}

byte column, row = 0;
void loop() {
  // Simple test of each LED in order from low address to high address
  for (row=0; row < TSOC_NEOLED_NUM_STRINGS; row++) { 
    for (column=0; column < (TSOC_NEOLED_LED_PER_STRING*TSOC_NEOLED_NUM_COLORS); column++) {  
        // Turn one color of one LED On
        Wire.beginTransmission(TSOC_NEOLED_I2CADDRESS);  // Start the I2C transaction
        Wire.write(row);                                 // Send the high byte of 16 bit memory address
        Wire.write(column);                              // Send the low byte of 16 bit memory address  (ie. the 
        Wire.write(TSOC_NEOLED_LED_ON);                  // Send a single data byte  (we could send more...)
        Wire.endTransmission();                          // End the I2C transaction
        delay(TSOC_NEOLED_LED_DELAY);                    // Delay to process the write cycle
      
        // Turn one color of one LED Off
        Wire.beginTransmission(TSOC_NEOLED_I2CADDRESS);  // Start the I2C transaction
        Wire.write(row);                                 // Send the high byte of address (the string number)
        Wire.write(column);                              // Send the low byte of address (the LED+Color number)
        Wire.write(TSOC_NEOLED_LED_OFF);                 // Send a single data byte  (we could send more...)
        Wire.endTransmission();                          // End the I2C transaction
        delay(TSOC_NEOLED_LED_DELAY);                    // Delay to process the write cycle
    }
  }
}

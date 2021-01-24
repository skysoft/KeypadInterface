# KeypadInterface
PIC16F15324 based keypad 4x4 or 3x4 to I2C interface with interrupt line
3.3v and 5v compatible

Use this to interface a standard keypad to I2C. Reduces needed GPIO pins on main uC and makes main uC program simpler. 

Connections : 
Column - Port
C1 - RA3
C2 - RA2 
C3 - RA1
C4 - RA0

Row - Port
R1 - RC3
R2 - RC2
R3 - RC1
R4 - RC0

I2C: 
SDA - RC5
SCL - RA5

Interrupt : 
RC4 (open drain) 

Tips:
*don't forget i2c pullup resistors
*disconnect programmer while testing (pulldowns lines) 

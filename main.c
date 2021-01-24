
#include "mcc_generated_files/mcc.h"
#include "keypad.h"

volatile uint8_t keypressed[10];
volatile uint8_t index = 0;
volatile uint8_t inbuf = 0;

void main(void)
{
//  keypressed = 0xFF;
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
EUSART1_Write('!');
    while (1)
    {
      uint8_t keypress = 0;
      
      
      if( keypress = getKey() )
      {
          
        if (index<11) // max 10 chars in de buffer
        {
          inbuf=1;
          keypressed[index] = keypress;
          index++;
        }
      }
      if (inbuf) //interruptlijn
      {
        RC4 = 1;
      }
      else
      {
        RC4 = 0;
      }
      //Sense_Keypress();
      
    }
}

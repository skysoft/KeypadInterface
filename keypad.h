/**
 * @file keypad.h
 * @author Embedded Laboratory
 * @date June 16, 2016
 * @brief Matrix Keypad Related Macros and Function Prototypes.
 *
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define _XTAL_FREQ 4000000
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_ROW         4                 /**< Maximum Row.*/
#define MAX_COL         4                 /**< Maximum Column.*/
#define ROW_1_PIN       PORTCbits.RC3     /**< Col 1 Pin Number.*/
#define ROW_1_DIR       TRISCbits.TRISC3  /**< Col 1 Direction.*/
#define ROW_2_PIN       PORTCbits.RC2     /**< Col 2 Pin Number.*/
#define ROW_2_DIR       TRISCbits.TRISC2  /**< Col 2 Direction.*/
#define ROW_3_PIN       PORTCbits.RC1     /**< Col 3 Pin Number.*/
#define ROW_3_DIR       TRISCbits.TRISC1  /**< Col 3 Direction.*/
#define ROW_4_PIN       PORTCbits.RC0     /**< Col 4 Pin Number.*/
#define ROW_4_DIR       TRISCbits.TRISC0  /**< Col 4 Direction.*/

#define COL_1_PIN       PORTAbits.RA3     /**< Row 1 Pin Number.*/
//#define COL_1_DIR       TRISAbits.TRISA3  /**< Row 1 Direction.*/
#define COL_2_PIN       PORTAbits.RA2     /**< Row 2 Pin Number.*/
#define COL_2_DIR       TRISAbits.TRISA2  /**< Row 2 Direction.*/
#define COL_3_PIN       PORTAbits.RA1     /**< Row 3 Pin Number.*/
#define COL_3_DIR       TRISAbits.TRISA1  /**< Row 3 Direction.*/
#define COL_4_PIN       PORTAbits.RA0     /**< Row 4 Pin Number.*/
#define COL_4_DIR       TRISAbits.TRISA0  /**< Row 5 Direction.*/




#define NO_KEYs                 255u      /**< No Key Pressed.*/
#define NO_KEY                  0u        /**< No Key Pressed.*/

/**
 * @brief Keypad States
 *
 * Different States of Matrix Keypad used by State Machine.
 */
typedef enum _Keypad_State_e
{
  KEYPAD_UP = 0,      /**< Key Up State, Initial State.*/
  KEYPAD_PRESSED,     /**< Key Pressed Detected State.*/
  KEYPAD_DOWN,        /**< Key Still Pressed State.*/
  KEYPAD_HELD,        /**< Key Hold Down for Repetetion State.*/
  KEYPAD_RELEASED,    /**< Key Release State.*/
  KEYPAD_DEBOUNCE     /**< Key Debouncing State.*/
} Keypad_State_e;

/**
 * @brief Keypad Structure
 *
 * Handle Matrix Keypad Data.
 */
typedef struct _Keypad_s
{
  uint8_t keyPressed;             /**< Key Pressed Detected.*/
  uint8_t keySensed;              /**< Key Sensed based on algorithm.*/
  uint32_t keyStatus_timeStamp;    /**< Key State Change Timestamp.*/
  Keypad_State_e keypad_state;  /**< Keypad Current State.*/
} Keypad_s;

/* Public Function Prototypes*/
void Initialize_Keypad( void );
uint8_t getKey( void );



#endif /* KEYPAD_H_ */

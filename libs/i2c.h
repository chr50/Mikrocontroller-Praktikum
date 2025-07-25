/***************************************************************************//**
 * @file    i2c.h
 * @author  Christopher Haas
 * @date    01.06.23
 *
 * @brief   Header file for I2C Functions
 *
 ******************************************************************************/

#ifndef EXERCISE_LIBS_I2C_H_
#define EXERCISE_LIBS_I2C_H_

/******************************************************************************
 * INCLUDES
 *****************************************************************************/

#include <msp430g2553.h>
#include "./common_isr.h"

/******************************************************************************
 * CONSTANTS
 *****************************************************************************/



/******************************************************************************
 * VARIABLES
 *****************************************************************************/

unsigned char txCounter;    // variable to keep track of the remaining bytes in the transmission data stack
                            // set in i2c_write function, decremented in transmission ISR

unsigned char * ptxData;    // pointer to the transmission data stack
                            // set in i2c_write function, incremented in transmission ISR

unsigned char rxCounter;    // variable to keep track of the remaining bytes in the receiver data stack
                            // set in i2c_read function, decremented in transmission ISR

unsigned char * prxData;    // pointer to the receiver data stack
                            // set in i2c_read function, incremented in transmission ISR

/******************************************************************************
 * FUNCTION PROTOTYPES
 *****************************************************************************/

// Initialize the I2C state machine. The speed should be 100 kBit/s.
// <addr> is the 7-bit address of the slave (MSB shall always be 0, i.e. "right alignment"). (2 pts.)
void i2c_init (unsigned char addr);

// Write a sequence of <length> characters from the pointer <txData>.
// Return 0 if the sequence was acknowledged, 1 if not. Also stop transmitting further bytes upon a missing acknowledge.
// Only send a stop condition if <stop> is not 0. (2 pts.)
unsigned char i2c_write(unsigned char length, unsigned char * txData, unsigned char stop);

// Returns the next <length> characters from the I2C interface. (2 pts.)
void i2c_read(unsigned char length, unsigned char * rxData);

void i2c_tx_isr(void);
void i2c_rx_isr(void);

#endif /* EXERCISE_LIBS_I2C_H_ */

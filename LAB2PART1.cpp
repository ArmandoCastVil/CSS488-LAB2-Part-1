/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    250


int main()
{
    //LAB 2 Part 1 starts here
    // Initialise the digital pin PA_5 as an output
    DigitalOut led(PA_5);
    // Initialise the digital button PC_13 as an input
    DigitalIn button(PC_13);
    //configure button with internal pull up resistor
    button.mode(PullUp);  
    // boolean that stores whether the button is been pressed
    bool buttonpress=false;

    while (true) {
         /* if statement to turn off led when button isnt being pressed*/
         if(button)
        {
            led=0;  
        }
          /* if statement to change the previous boolean, sleep_for is used to
        prevent multiple inputs from being counted due to bouncing*/
        if(!button)
        {
            thread_sleep_for(BLINKING_RATE_MS);
            buttonpress=!buttonpress;     
        }
         if(buttonpress==true)
        {
            buttonpress=false;
            led = !led;
        }
            
    }
}

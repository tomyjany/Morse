/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iterator>
#include <string>
#include "morse.h"
#include "mbed.h"
#include <chrono>

// Blinking rate in milliseconds
#define TASK_BLICK 0
#define TASK_MORSE 1
#define LED_BLICK_ON 100ms
#define LED_BLICK_OFF 100ms

DigitalOut bspLED(LED1);

using std::string;
void morse(){

}

int main()
{
    string jmeno = "TOMAS";
    bspLED = 1;
    morseBlink(jmeno,bspLED);
    bspLED = 1;
    
}

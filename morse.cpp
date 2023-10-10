#include <string>
#include "./morse.h"
#include "mbed.h"
#define LED_ON    1500ms
#define LED_OFF     200ms
#define DOT_ON      200ms
#define DASH_ON     1000ms
#define PAUSE 2000ms


void morseBlink(string jmeno,DigitalOut bspLED)
{
    string morse[39] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", 
"...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", 
".-.-.-", "--..--", "..--.."};

    char alphabet[39] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ']', ',', '?'};
    // Initialise the digital pin LED1 as an output

    for(char& c : jmeno) {
        for(int i =0;i<39;i++){
            if(c==alphabet[i]){
                for(char& l : morse[i]){
                    if (l=='.'){
                        bspLED = 0;
                        ThisThread::sleep_for(DOT_ON);
                        bspLED = 1;
                        ThisThread::sleep_for(LED_OFF);
                    }else if(l=='-'){
                        bspLED = 0;
                        ThisThread::sleep_for(DASH_ON);
                        bspLED = 1;
                        ThisThread::sleep_for(LED_OFF);
                    }

                }
                bspLED = 1;
                ThisThread::sleep_for(PAUSE);
            }
            bspLED = 1;
        }
    }
}
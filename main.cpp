/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @brief This file is based on the MAPLE MINI example from ChibiOS
 *
 * @file main.cpp
 * @author Alex Au
 * @date 2018-09-11
 */

#include "ch.hpp"

#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"
#include <stdlib.h>
#include <cstring>

using namespace chibios_rt;
/*
 * Application entry point.
 */
/*typedef struct{
  uint8_t	length;
  uint8_t  segment[8];
} morse_code_t;

morse_code_t champion[8] = {
  {4, {2, 1, 2, 1}},
  {4, {1, 1, 1, 1}},
  {2, {1, 2, 0, 0}},
  {2, {2, 2, 0, 0}},
  {4, {1, 2, 2, 1}},
  {2, {1, 1, 0, 0}},
  {3, {2, 2, 2, 0}},
  {2, {2, 1, 0, 0}}
};
int lengtsh = sizeof(champion)/sizeof(int); 
void morse_code(const morse_code_t* code)
{
  //int i;
  for(int i = 0; i < code->length; i++)
//Display the dashes and dots in the code
  {
    palSetPad(GPIOA, GPIOA_LED);
    chThdSleepMilliseconds(200); //The led is initially off
    palClearPad(GPIOA, GPIOA_LED);
    if(code->segment[i] == 2)
      chThdSleepMilliseconds(600);
    else if(code->segment[i] == 1)
      chThdSleepMilliseconds(200);
  }
  palSetPad(GPIOA, GPIOA_LED);
}*/
int ind = 0;
int letmetry[8][4]={
  {2, 1, 2, 1},
  {1, 1, 1, 1},
  {1, 2, 0, 0},
  {2, 2, 0, 0},
  {1, 2, 2, 1},
  {1, 1, 0, 0},
  {2, 2, 2, 0},
  {2, 1, 0, 0}
};

void canFigureOut(){
  int touse[4]={};
  for(int translate = 0; translate<4; translate++){
    touse[translate]=letmetry[ind][translate];
    }
    ind++;
  for(int i = 0; i < 4; i++)
//Display the dashes and dots in the code
  {
    palSetPad(GPIOA, GPIOA_LED);
    chThdSleepMilliseconds(200); //The led is initially off
    palClearPad(GPIOA, GPIOA_LED);
    if(touse[i] == 2)
      chThdSleepMilliseconds(600);
    else if(touse[i] == 1)
      chThdSleepMilliseconds(200);
  }
    palSetPad(GPIOA, GPIOA_LED);
    if(ind == 8){
      ind = 0;
    }
}

//int a[4] = {'1', '2', '3', '4'};
//bool led_on; //LED ON
static THD_WORKING_AREA(button_thread_wa, 128);
static THD_FUNCTION(button_thread, p){
  bool buttond = false;
  while(true){
    if(!palReadPad(GPIOA, GPIOA_BUTTON))
    {
     canFigureOut(); 
    }

  }
}
/*static THD_WORKING_AREA(led_thread_wa, 128);
static THD_FUNCTION(led_thread, p){
 while(true){
    palTogglePad(GPIOA, GPIOA_LED);
    chThdSleepMilliseconds(250);
  } 
}*/
int main(void)
{

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();
  //morse_code(champion);
 // canFigureOut();
  /*
   * Normal main() thread activity
   */
 chThdCreateStatic(button_thread_wa, sizeof(button_thread_wa), NORMALPRIO, button_thread, NULL);
// chThdCreateStatic(led_thread_wa, sizeof(led_thread_wa), NORMALPRIO, led_thread, NULL);
  while (true)
  {
    systime_t startT = chibios_rt::System::getTime();
    //palTogglePad(GPIOA, GPIOA_LED);
    //do something..
    chibios_rt::BaseThread::sleepUntil(startT + TIME_MS2I(500));
    //chThdSleepMilliseconds(500); <- any difference using this?
  }
}

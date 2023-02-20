/*!
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.2
 *
 * @date        2022-01-05
 *
 * @attention
 *
 *  Copyright (C) 2020-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be usefull and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

#include "main.h"

volatile uint32_t tick = 0;

/*!
 * @brief       Main program
 *
 * @param       None
 *
 * @retval      None
 *
 */
int main(void)
{
    TMR_BaseConfig_T TMR_BaseConfigStruct;

    APM_MINI_LEDInit(LED2);

    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_TMR1);

    TMR_BaseConfigStruct.clockDivision = TMR_CLOCK_DIV_1;
    TMR_BaseConfigStruct.countMode = TMR_COUNTER_MODE_UP;
    TMR_BaseConfigStruct.division = 71;
    TMR_BaseConfigStruct.period = 999;
    TMR_BaseConfigStruct.repetitionCounter = 0;
    TMR_ConfigTimeBase(TMR1, &TMR_BaseConfigStruct);

    TMR_EnableInterrupt(TMR1, TMR_INT_UPDATE);
    NVIC_EnableIRQRequest(TMR1_UP_IRQn, 0, 0);

    TMR_Enable(TMR1);

    while(1)
    {
        APM_MINI_LEDToggle(LED2);
        Delay();
    }
}

/*!
 * @brief       Delay
 *
 * @param       None
 *
 * @retval      None
 *
 */
void Delay(void)
{
    tick = 0;

    while(tick < 500);
}


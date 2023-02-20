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
    APM_MINI_LEDInit(LED2);
    APM_MINI_LEDInit(LED3);
    APM_MINI_PBInit(BUTTON_KEY1, BUTTON_MODE_EINT);

    RCM_EnableAPB1PeriphClock(RCM_APB1_PERIPH_WWDT);

    if(RCM_ReadStatusFlag(RCM_FLAG_WWDTRST) == SET)
    {
        APM_MINI_LEDOn(LED3);
        RCM_ClearStatusFlag();
    }
    else
    {
        APM_MINI_LEDOff(LED3);
    }

    SysTick_Config(SystemCoreClock / 1000);

    WWDT_ConfigTimebase(WWDT_TIME_BASE_8);
    WWDT_ConfigWindowData(80);
    WWDT_Enable(127);

    while(1)
    {
        APM_MINI_LEDToggle(LED2);
        Delay();
        WWDT_ConfigCounter(127);

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
    while(tick < 44);
}


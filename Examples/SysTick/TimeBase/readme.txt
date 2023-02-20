/*!
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
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


&par Example Description

The example shows how to configure the SysTick to generate a time base equal to
1 ms. A "Delay" function is implemented based on the SysTick end-of-count event
which delays exactly half a second, and the LED's on-off state changes every second.

&par Directory contents

  - SysTick/TimeBase/src/apm32f10x_it.c     Interrupt handlers
  - SysTick/TimeBase/src/main.c                      Main program

&par Hardware and Software environment

  - This example runs on APM32F103_MINI Devices.
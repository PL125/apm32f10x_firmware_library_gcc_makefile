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

This example aims to show how to use WWDT.
If  is_OverTime = 0 , System would not reset for feeding dog timely. LED2 Toggle.
Pressing KEY1 to stop feed dog will trigger system reset when the counter reach a given
timeout value. LED3 will be lighted when a system reset is triggered by IWDT.

&par Directory contents

  - WWDT/Reset/src/apm32f10x_it.c     Interrupt handlers
  - WWDT/Reset/src/main.c                      Main program

&par Hardware and Software environment

  - This example runs on APM32F103 MINI Devices.
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

This example describes how to use  ADC1 to monitor the voltage of ADC1_Channel14 continuously.
If the voltage on ADC1_Channel14(PC4) is not in the thresholds which is setted brefore, analog watchdog
interrupt will generate and light LED2.

&par Directory contents

  - ADC/AnalogWatchdog/src/apm32f10x_int.c     Interrupt handlers
  - ADC/AnalogWatchdog/src/main.c                      Main program


&par Hardware and Software environment

  - This example runs on APM32F103_MINI Devices.
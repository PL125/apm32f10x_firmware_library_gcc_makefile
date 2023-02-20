#include "apm32f10x.h"
#include "apm32f10x_gpio.h"
#include "apm32f10x_rcm.h"


void led_init()
{
    GPIO_Config_T  configStruct;

    /** Enable the GPIO_LED Clock */
    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOB);

    /** Configure the GPIO_LED pin */
    configStruct.pin = GPIO_PIN_2;
    configStruct.mode = GPIO_MODE_OUT_PP;
    configStruct.speed = GPIO_SPEED_50MHz;

    GPIO_Config(GPIOB, &configStruct);
    GPIOB->BC = GPIO_PIN_2;
}


int main(void)
{
	led_init();
    while (1)
    {
        Delay();
		GPIOB->ODATA ^= GPIO_PIN_2;
    }
}

void Delay(void)
{
    volatile uint32_t delay = 0xfffff;

    while(delay--);
}


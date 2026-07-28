/* Blink LED example for LAUNCHXL-F2800157
 * Uses TI C2000 DriverLib / Device support.
 * If DEVICE_GPIO_PIN_LED1 is not defined in your board headers,
 * adjust LED_PIN to the correct GPIO number for your board.
 */

#include <stdint.h>
#include <stdbool.h>

#include "device.h"
#include "board.h"
#include "f280015x_device.h"
#include "driverlib.h"

/* Fallback LED pin if board header doesn't define one */
#ifndef DEVICE_GPIO_PIN_LED1
#define LED_PIN 31U /* adjust as needed for your board */
#else
#define LED_PIN DEVICE_GPIO_PIN_LED1
#endif

int main(void)
{
    /* Initialize device clock and peripherals */
    Device_init();
    Device_initGPIO();

    /* Configure the LED pin as a push-pull output */
    GPIO_setPadConfig(LED_PIN, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(LED_PIN, GPIO_DIR_MODE_OUT);

    for(;;)
    {
        GPIO_togglePin(LED_PIN);
        DEVICE_DELAY_US(500000); /* 500 ms */
    }

    /* Should never reach here */
    return 0;
}

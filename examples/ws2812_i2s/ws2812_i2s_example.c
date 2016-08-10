#include "espressif/esp_common.h"
#include "FreeRTOS.h"
#include "task.h"
#include "esp/uart.h"
#include <stdio.h>
#include <stdint.h>

#include "ws2812_i2s/ws2812_i2s.h"

static void demo(void *pvParameters)
{
    printf("init ws2812 i2s\n");
    ws2812_i2s_init();
    printf("init ws2812 i2s done\n");

    while (1) {
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void user_init(void)
{
    uart_set_baud(0, 115200);

    xTaskCreate(&demo, (signed char *)"ws2812_i2s", 256, NULL, 10, NULL);
}
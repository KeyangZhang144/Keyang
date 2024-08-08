/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hcsr04.h"

int main() {
    timer_hw->dbgpause = 0;
    stdio_init_all();
    int distance;
    while(true){
        hcsr04_init();
        distance = hcsr04_get_distance();
        printf("distance : %d\n", distance);
        //printf("distance : %.2f\n", distance);
        busy_wait_ms(500);
    }
/*    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(250);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(250);
    }
    */
}

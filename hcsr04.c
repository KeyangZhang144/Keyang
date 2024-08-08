#include <stdio.h>
#include "pico/stdlib.h"
#include "hcsr04.h"
#include "pico/time.h"

void hcsr04_init(){
    gpio_init (ECHO_PIN);
    gpio_init (TRIG_PIN);
    gpio_set_dir (ECHO_PIN, GPIO_IN);
    gpio_set_dir (TRIG_PIN, GPIO_OUT);
    gpio_put (TRIG_PIN, false);
}
int hcsr04_get_distance(){
    // hcsr04_get_distance returns the distance measured by the sensor in meters
    int time0;
    absolute_time_t time1, time2;
    // fire ultrasonic signal
    gpio_put(TRIG_PIN, true);
    busy_wait_us_32(100);
    gpio_put(TRIG_PIN, false);
    time1 = get_absolute_time();
    // wait for echo high
    while (!gpio_get(ECHO_PIN));
    time2 = get_absolute_time();
    time0 = absolute_time_diff_us(time1, time2);
    time0 *= 170;
    return time0;
}

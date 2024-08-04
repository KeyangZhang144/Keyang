#include <stdio.h>
#include "pico/stdlib.h"
#include "hcsr04.h"
#include "pico/time.h"

void hcsr04_init(){
    gpio_init (ECHO_PIN);
    gpio_init (TRIG_PIN);
    gpio_set_dir (ECHO_PIN, false);
    gpio_set_dir (TRIG_PIN, true);
    gpio_put (TRIG_PIN, false);
}

double hcsr04_get_distance(){
    double time0;
    absolute_time_t time1, time2;
    gpio_put(TRIG_PIN, true);
    time1 = get_absolute_time();
    while (!gpio_get(ECHO_PIN));
    time2 = get_absolute_time();
    time0 = absolute_time_diff_us(time1, time2);
    return time0 * 170;
}

int hcsr() {
    double distance;
    hcsr04_init();
    distance = hcsr04_get_distance();
    printf("distance : %.2f\n", distance);
}

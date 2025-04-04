#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/rand.h"


//light each lamp in a row with bitmask
#define START_PIN 6
#define NUMBER_OF_LEDS 10
int main() {
    stdio_init_all();
    sleep_ms(1000);
    uint32_t led_mask = (1 << NUMBER_OF_LEDS) - 1;
    printf("%b\n",led_mask);
    uint32_t mask_offset = led_mask << START_PIN;
    printf("%b\n",mask_offset);
    // 0b1111111111000000
    gpio_init_mask(mask_offset);
    gpio_set_dir_masked(mask_offset,mask_offset);


    while (true) {
        gpio_put_masked(mask_offset,mask_offset >> (get_rand_32()%11));
        sleep_ms(100);
    }
}



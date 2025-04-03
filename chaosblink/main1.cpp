#include "pico/stdlib.h"
#include "pico/rand.h"
#include <stdio.h>
#define LED1 15
#define LED2 14
#define LED3 13
#define LED4 12
#define LED5 11
#define LED6 10
#define LED7 9
#define LED8 8
#define LED9 7
#define LED10 6
#define NUM_OF_LEDS 11
const uint led_lights[] = {LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8,LED9,LED10};

bool blink_callback(struct repeating_timer * t) {
    uint random_index = get_rand_32()%NUM_OF_LEDS;
    gpio_put(led_lights[random_index],1);
    random_index = get_rand_32()%NUM_OF_LEDS;
    gpio_put(led_lights[random_index],0);
    return 1;
}





int main() {
    int led_list_lenght = sizeof(led_lights)/sizeof(led_lights[0]);
    for(int i = 0; i < led_list_lenght; i++) {
        gpio_init(led_lights[i]);
        gpio_set_dir(led_lights[i], 1);
    }


   repeating_timer timer;
   add_repeating_timer_ms(10,blink_callback, nullptr, &timer);
    
    while(true) {
        sleep_ms(100);
    }

}

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

//blink 1 led each time
//blink several lights at the same time. bitwise
int main() {
    stdio_init_all();

    const uint led_lights[] = {LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8,LED9,LED10};
    int led_list_lenght = sizeof(led_lights)/sizeof(led_lights[0]);
    for(int i = 0; i < led_list_lenght; i++) {
        gpio_init(led_lights[i]);
        gpio_set_dir(led_lights[i], 1);
    }
   

    while(true) {
        uint random_index = get_rand_32();
        gpio_put(led_lights[random_index%11],1);
        sleep_ms(10);
        gpio_put(led_lights[random_index%11],0);
        sleep_ms(10);
    }
}
        


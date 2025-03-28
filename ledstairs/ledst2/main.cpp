#include "pico/stdlib.h"



int main() {
    //FOR LED LAMPS
    const uint LED1 = 16;
    const uint LED2 = 17;
    const uint LED3 = 18;
    const uint LED4 = 19;

    gpio_init(LED1);
    gpio_init(LED2);
    gpio_init(LED3);
    gpio_init(LED4);

    gpio_set_dir(LED1, 1);
    gpio_set_dir(LED2, 1);
    gpio_set_dir(LED3, 1);
    gpio_set_dir(LED4, 1);
    //FOR BTN
    const uint BTN = 15;
    gpio_init(BTN);
    gpio_set_dir(BTN, 0);
    gpio_pull_up(BTN);

    bool led_status = false;

    while(true) {
        if(!gpio_get(BTN)) {
            led_status = !led_status;
        }
        if(led_status) {
            gpio_put(LED1,1);
            sleep_ms(100);
        }
        else {
            gpio_put(LED1,0);
            sleep_ms(100);
        }
    }
}





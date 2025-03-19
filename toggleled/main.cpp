#include "pico/stdlib.h"

int main(){
    const uint LED_PIN = 16;
    const uint BTN = 17;

    gpio_init(LED_PIN);
    gpio_init(BTN);

    gpio_set_dir(LED_PIN, 1);
    gpio_set_dir(BTN,0);
    gpio_pull_up(BTN);
    bool led_state = false;
    int iter1 = 0;
    int iter2 = 0;

    while(true) {
        if(gpio_get(BTN)){
            iter1 ++;
            iter2 = iter1;
        }
     
        if(!gpio_get(BTN)) {
            if(iter1 == iter2){
                led_state = !led_state;
                iter2++;
            }

        }
        else if(led_state) {
            gpio_put(LED_PIN,1);
            sleep_ms(10);
        }
        else {
            gpio_put(LED_PIN, 0);
            sleep_ms(10);
        }
        
    } 

    return 0;
}

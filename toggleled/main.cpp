#include "pico/stdlib.h"

int main(){
    const uint LED_PIN = 16;
    const uint BTN = 17;

    gpio_init(LED_PIN);
    gpio_init(BTN);

    gpio_set_dir(LED_PIN, 1);
    gpio_set_dir(BTN,0);
    gpio_pull_up(BTN);

    while(true) {
  
        static bool state = false;
        if(gpio_get(BTN) == 0){
            state = !state;
        }
        if(state == false) {
            gpio_put(LED_PIN,0);
            sleep_ms(100);
        }
        else {
            gpio_put(LED_PIN,1);
            sleep_ms(100);
        }

     
          
        
    } 

    return 0;
}

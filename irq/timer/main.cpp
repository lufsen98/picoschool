#include <iostream>
#include "hardware/timer.h"
#include "pico/stdlib.h"

#define LED 15 
bool timer_callback(struct repeating_timer_t * rt) {
        bool led_on = gpio_get(LED);
        gpio_put(LED,!led_on);
        return true;
}
int main() {
   gpio_init(LED);
   gpio_set_dir(LED,1);

   repeating_timer_t timer;

   add_repeating_timer_ms(100,timer_callback,nullptr, &timer);

   while(true) {
       sleep_ms(100);
   }
}


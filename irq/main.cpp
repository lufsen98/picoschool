#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include <iostream>
#define LED 15
#define BTN 16
void call_back(uint gpio,uint32_t event) {
        bool led_on = gpio_get(LED);
        gpio_put(LED,!led_on);

};
//volatile viktigt att sätta så inte kompilatorn tar bort variabeln eftersom vi inte anropar call_back vi registerar den bara.
int main() {
    stdio_init_all();

    gpio_init(LED);
    gpio_set_dir(LED,1);
    
    gpio_init(BTN);
    gpio_set_dir(BTN,0);
    gpio_pull_up(BTN);
    gpio_set_irq_enabled_with_callback(BTN,GPIO_IRQ_EDGE_RISE,true,&call_back);
    while(true) {
        sleep_ms(100);
    }
}

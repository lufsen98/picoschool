#include "pico/stdlib.h"

int main() {
    //LED Pins defined
    const uint arr[5] = {16,17,18,19,20};
    //BUTTON Pin defined 
    const uint BTN = 15;

    //gpio_pins initialised
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        gpio_init(arr[i]);
    }
    gpio_init(BTN);

    //Define input or output for pins.
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        gpio_set_dir(arr[i],1);
    }
    gpio_set_dir(BTN, 0);

    //Define high state of button
    gpio_pull_up(BTN);
    int itr = 0; 
    while(true) {
        /*int i = 0;
        if(i == 5){
            i = 0;
        }*/
        int button_state = gpio_get(BTN);

        if(!button_state) {
            itr ++;
        }
     
        if(itr == 5){
            gpio_put(arr[itr -1], 0);
            sleep_ms(80);
            itr = 0;
        }
        gpio_put(arr[itr-1],0);
        sleep_ms(80);
        gpio_put(arr[itr],1);
        sleep_ms(80);


        /*for(i; i < sizeof(arr)/sizeof(arr[0]);i++) {
             gpio_put(arr[i-1], 0);
             gpio_put(arr[i],1);
             sleep_ms(100);
             if(i == (sizeof(arr)/sizeof(arr[0])) - 1) {
                 gpio_put(arr[i], 0);
                 sleep_ms(100);
             }
        }*/

    }

}



   
   
   
   
   
   
   
   

    

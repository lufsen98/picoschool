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
    int length = sizeof(arr)/sizeof(arr[0]);
    int itr = 0;

    int itr2= 0;
    int itr3 = 0;
    while(true) {
        if(gpio_get(BTN))  {
            itr2 ++;
            itr3 = itr2;
        }    
        if(itr == length ) { 
            itr = 0;
        } 
        if(!gpio_get(BTN) && (itr3 == itr2)) {
            if(itr == 0) {
                gpio_put(arr[length -1], 0);
            }
            else {   
                gpio_put(arr[itr-1], 0);
            }
            sleep_ms(100);
            gpio_put(arr[itr], 1);
            sleep_ms(100);

            itr3 ++;
            itr++;
        }
        /*int i = 0;
        if(i == 5){
            i = 0;
        }*/
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



   
   
   
   
   
   
   
   

    

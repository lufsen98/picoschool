#include "pico/stdlib.h"
#include <iostream>

int main() {
    stdio_init_all();

    std::string name;
    while (true) {
        std::cin >> name; 
        std::cout << "Hello from pico\n";
    }
    return 0;
}
    

#include <iostream>
//swap 2 numbers using bitwise operators.
int bit_counter(int num);
bool is_power_of_two(int num);
void print_bit_position(int num, int k);
void switch_bit(int num , int k);
int main() {
    //task 1.
    int a = 35;
    int b = 45;

     a = a ^ b;
     b = a ^ b;
     a = a ^ b; 
    std::cout << "a = " << a << "\nb = " << b << "\n";
    //task 2 & 3
    int num = 4;
    std::cout << bit_counter(num) << "\n";

    if(is_power_of_two(num)) {
        printf("%i is the power of 2\n", num);
    }
    else {
        printf("%i is not the power of 2\n", num);
    }
    //task4
    print_bit_position(6,4);
    //task5
    switch_bit(13,2);
    return 0;
}
//task 2
bool is_power_of_two(int num) {
    if((num & (num - 1)) == (0 && num > 0)) {
       return true; 
    }
    else {
        return false;
    }
}
//task 3
int bit_counter(int num) {
    int counter = 0;
    for(int i = 0; i < 32 ; i++) {
        printf("num: %d\n",num);
        if(num & 1) {
            counter ++;
        }
        num = num >> 1;
    }
    return counter;
} 
// task 4 
void print_bit_position(int num , int k) {
    printf("%i\n",((num >> k) & 1)); 
       
}
//task5
void switch_bit(int num, int k) {
    //bitmask1(num) 0b1101 = int 3
    //position:        210         
    //bitmask2(k)   0b0001 = int 1 -> postion value: 2 of bitmask1
    //
    int num2 = 0;
    num2 = num^(1 << k); 
   
    printf("%i after switch bit position %i is: %i\n",num, k, num2);
}

#include <stdio.h>

int main() {
    int num, original_num;
    int power = 1;
    int ones_count = 0;

   
    printf("Enter a positive decimal integer: ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Error: Please enter a valid positive integer.\n");
        return 1;
    }

    original_num = num; 

  
    while (power * 2 <= num) {
        power *= 2;
    }


    printf("Binary representation: ");
    
    int current_power = power;
    while (current_power > 0) {
        if (num >= current_power) {
            printf("1");
            ones_count++;
            num -= current_power; 
        } else {
            printf("0");
        }
        
        current_power /= 2; 
    }
    printf("\n");

   
    printf("Number of 1 bits: %d\n", ones_count);

    return 0;
}


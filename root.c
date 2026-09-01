#include <stdio.h>

int main() {
    long long current;

   
    printf("Enter a positive integer: ");
    if (scanf("%lld", &current) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    
    if (current <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    printf("Starting value: %lld\n", current);

   
    while (current >= 10) {
        long long sum = 0;
        long long temp = current;

        
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        current = sum;
        printf("Intermediate sum: %lld\n", current);
    }

    printf("Digital Root: %lld\n", current);

    return 0;
}


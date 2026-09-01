#include <stdio.h>

int main() {
    long long num, original_num;
    int digit_count = 0;
    int digit_sum = 0;
    long long reversed_num = 0;

   
    printf("Enter a positive integer: ");
    if (scanf("%lld", &num) != 1 || num <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

   
    original_num = num;

  while (num > 0) {
       
        int last_digit = num % 10;

        
        digit_count++;

       
        digit_sum += last_digit;

       
        reversed_num = (reversed_num * 10) + last_digit;

       
        num = num / 10;
    }

  
    printf("\nResults for %lld:\n", original_num);
    printf("• Total number of digits: %d\n", digit_count);
    printf("• Sum of the digits:     %d\n", digit_sum);
    printf("• Reverse of the number:  %lld\n", reversed_num);

    return 0;
}


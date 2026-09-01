#include <stdio.h>

int main() {
    int target_number;
    printf("enter the target number: ");
    scanf("%d",&target_number);
    

    
    int low = 1;
    int high = 1000;
    int guess_count = 0;

    printf("Target number is %d.\n\n", target_number);


    while (low <= high) {
        
        int guess = (low + high) / 2;
        guess_count++;

        
        if (guess == target_number) {
            printf("Guessing %d... Correct!\n", guess);
            break; 
        } else if (guess < target_number) {
            printf("Guessing %d... Too low!\n", guess);
            low = guess + 1;
        } else {
            printf("Guessing %d... Too high!\n", guess);
            high = guess - 1; 
        }
    }

    printf("\nFound in %d guesses.\n", guess_count);

    return 0;
}


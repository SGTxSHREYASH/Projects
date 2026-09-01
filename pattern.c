#include <stdio.h>

int main() {
    int choice, size, i, j;


    printf("Menu:\n");
    printf("1. Right Triangle\n");
    printf("2. Inverted Right Triangle\n");
    printf("3. Square\n");
    
    
    printf("Select pattern: ");
    scanf("%d", &choice);
    printf("Enter size: ");
    scanf("%d", &size);

    
    switch (choice) {
        case 1:
            
            for (i = 1; i <= size; i++) {
                for (j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 2:
            
            for (i = size; i >= 1; i--) {
                for (j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 3:
       
            for (i = 1; i <= size; i++) {
                for (j = 1; j <= size; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid selection. Please choose 1, 2, or 3.\n");
            break;
    }

    return 0;
}


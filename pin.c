#include <stdio.h>
#include <stdbool.h>

int main() {
    const int CORRECT_PIN = 1234;
    const int MAX_ATTEMPTS = 3;
    
    int enteredPin;
    int attempts = 0;
    bool isAuthenticated = false;

    printf("=== ATM / PHONE SIMULATOR ===\n");

    do {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);
        attempts++;

        if (enteredPin == CORRECT_PIN) {
            isAuthenticated = true;
            break; 
        } else if (attempts < MAX_ATTEMPTS) {
            printf("Incorrect PIN. Please try again.\n\n");
        }
    } while (attempts < MAX_ATTEMPTS);

    
    if (isAuthenticated) {
        printf("\nAccess Granted. Welcome back!\n");
    } else {
        printf("\nToo many failed attempts. Device locked for security.\n");
    }

    return 0;
}


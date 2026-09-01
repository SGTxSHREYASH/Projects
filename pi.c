#include <stdio.h>
#include <math.h>

int main() {
    int N;
    double sum = 0.0;
    double sign = 1.0;


    printf("Enter N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    
    for (int i = 0; i < N; i++) {
        double denominator = 2.0 * i + 1.0;
        sum += sign / denominator;
        sign = -sign;
    }


    double approx_pi = sum * 4.0;
    

    double actual_pi = acos(-1.0);

  
    double error = fabs((approx_pi - actual_pi) / actual_pi) * 100.0;

    
    printf("Approximate pi: %f\n", approx_pi);
    printf("Actual pi:      %f\n", actual_pi);
    printf("Percentage error: %f%%\n", error);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function declarations */
double calculateDistance(int, int);
int calculateGeoScore(int, int);
int updateStorage(int);
int moveRover(int, int, double);

int x = 0;
int y = 0;

double battery = 100.0;
double totalDistance = 0.0;

int storage = 0;
int netSum = 0;


/* ------------------------------------------------ */
/* Calculate distance between current and new point */
/* ------------------------------------------------ */

double calculateDistance(int newX, int newY)
{
    double dist;

    dist = sqrt(pow(newX - x, 2) + pow(newY - y, 2));

    return dist;
}


/* ------------------------------------------------ */
/* Move rover if enough battery is available        */
/* ------------------------------------------------ */

int moveRover(int newX, int newY, double dist)
{
    double batteryRequired;

    batteryRequired = dist * 2.5;

    /* Check battery before changing anything */
    if (batteryRequired > battery)
    {
        printf("\nBattery insufficient! Please recharge.\n");
        printf("Movement denied!\n");

        return 0;
    }

    /* Battery is sufficient, so movement is allowed */
    battery -= batteryRequired;

    x = newX;
    y = newY;

    totalDistance += dist;

    return 1;
}


/* ------------------------------------------------ */
/* Calculate Geo Score                              */
/* ------------------------------------------------ */

int calculateGeoScore(int x1, int y1)
{
    int sumX = 0;
    int sumY = 0;

    /* Find digit sum of x */
    while (x1 > 0)
    {
        sumX += x1 % 10;
        x1 /= 10;
    }

    /* Find digit sum of y */
    while (y1 > 0)
    {
        sumY += y1 % 10;
        y1 /= 10;
    }

    netSum = sumX + sumY;

    /* Numbers less than 2 are not prime */
    if (netSum < 2)
    {
        return 0;
    }

    /* Check whether netSum is prime */
    for (int i = 2; i <= sqrt(netSum); i++)
    {
        if (netSum % i == 0)
        {
            return 0;
        }
    }

    return 1;
}


/* ------------------------------------------------ */
/* Update storage                                   */
/* ------------------------------------------------ */

int updateStorage(int geoScore)
{
    if (storage >= 50)
    {
        storage = 50;
        return storage;
    }

    if (geoScore == 1)
    {
        storage += 15;
    }
    else
    {
        storage += netSum;
    }

    /* Storage cannot exceed 50 */
    if (storage > 50)
    {
        storage = 50;
    }

    return storage;
}


/* ------------------------------------------------ */
/* Main                                             */
/* ------------------------------------------------ */

int main()
{
    int choice;
    int newX, newY;

    printf("---- Welcome to Mars Rover Simulation Program ----\n");

    printf("Battery: %.2f%% | Storage: %d/50 | Position: (%d,%d)\n",
           battery, storage, x, y);

    while (1)
    {
        printf("\n");
        printf("[1] Drive and Drill\n");
        printf("[2] Recharge\n");
        printf("[3] Transmit and Sleep\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        /* ---------------------------------------- */
        /* DRIVE AND DRILL                          */
        /* ---------------------------------------- */

        if (choice == 1)
        {
            printf("Enter the coordinates to drive to (x y): ");
            scanf("%d %d", &newX, &newY);

            double dist = calculateDistance(newX, newY);

            printf("\nDistance to destination: %.2f units\n", dist);

            /* Try to move */
            int moved = moveRover(newX, newY, dist);

            /* If movement failed, do nothing else */
            if (moved == 0)
            {
                printf("Current Battery: %.2f%%\n", battery);
                printf("Current Position: (%d,%d)\n", x, y);

                continue;
            }

            /* Movement successful */
            int geoScore = calculateGeoScore(newX, newY);

            int currentStorage = updateStorage(geoScore);

            printf("Moved to (%d,%d).\n", x, y);
            printf("Distance traveled: %.2f units\n", dist);

            printf("Remaining Battery: %.2f%%\n", battery);

            printf("Geo Score: %d\n", geoScore);
            printf("Digit Sum: %d\n", netSum);

            printf("Storage: %d/50\n", currentStorage);
        }


        /* ---------------------------------------- */
        /* RECHARGE                                 */
        /* ---------------------------------------- */

        else if (choice == 2)
        {
            printf("\nRecharging battery...\n");

            battery = 100.0;

            printf("Battery recharged to 100%%.\n");
        }


        /* ---------------------------------------- */
        /* TRANSMIT AND SLEEP                       */
        /* ---------------------------------------- */

        else if (choice == 3)
        {
            printf("\nTransmitting data and going to sleep...\n");

            printf("Total Distance Traveled: %.2f units\n",
                   totalDistance);

            printf("Final Storage: %d/50\n",
                   storage);

            printf("Final Battery: %.2f%%\n",
                   battery);

            printf("Final Position: (%d,%d)\n",
                   x, y);

            printf("Simulation ended.\n");

            exit(0);
        }


        /* ---------------------------------------- */
        /* INVALID CHOICE                           */
        /* ---------------------------------------- */

        else
        {
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
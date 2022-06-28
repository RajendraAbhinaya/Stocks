#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    int j;
    int k = 0;
    float prevPrice;
    float currPrice;
    int increment;
    float pull;
    float carry = 0;
    int sign = 1;
    int high;
    int low;
    float average;
    int middle;
    int middleSwap;

    //CONTROLS
    int start = 50;  //Starting Price
    int min = 20;    //Price will be adjusted upwards when below min value
    int max = 100;   //Price will be adjusted downwards when above max value
    int adjust = 5;  //Value of price adjustment when min/max threshold is met
    int size = 1000; //Length of price simulation
    int mod = 7;     //Modulus for random number generator

    srand(time(0));

    while(1)
    {
        prevPrice = middle = start;
        middleSwap = size / 10;
        high = low = start;
        average = 0;
        for(i=1; i<size; i++)
        {
            k++;
            if(k == middleSwap)
            {
                k = 0;
                middle = (middle + ((rand() % (max - min)) + min)) / 2;
            }
            pull = (middle - prevPrice) / ((min + max) / mod);
            increment = ((rand() % mod) + 1) * sign;
            currPrice = prevPrice + increment + carry + pull;
            carry = increment;
            sign *= -1;

            if(currPrice > max)
            {
                currPrice -= adjust;
            }
            else if(currPrice < min)
            {
                currPrice += adjust;
            }

            if(currPrice > high)
            {
                high = currPrice;
            }
            else if(currPrice < low)
            {
                low = currPrice;
            }

            average += currPrice;
            for(j=0; j<currPrice; j++)
            {
                printf("_");
            }
            printf("\n");

            prevPrice = currPrice;
        }

        average /= size;
        printf("\n==================================================================================================\n\n");
        printf("Max     = %d\n", high);
        printf("Min     = %d\n", low);
        printf("Average = %.2f\n\n", average);
        printf("Press ENTER to try again\n");
        getchar();
        system("cls");
    }
    return 0;
}

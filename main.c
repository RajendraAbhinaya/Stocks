#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    int j;
    int increment;
    int carry = 0;
    int sign = 1;
    int high;
    int low;
    float average;

    //CONTROLS
    int start = 50;
    int min = 20;
    int max = 100;
    int adjust = 5;
    int size = 1000;
    int mod = 10;

    int price[size];
    price[0] = start;
    srand(time(0));

    while(1)
    {
        high = low = start;
        for(i=1; i<size; i++)
        {
            increment = ((rand() % mod) + 1) * sign;
            price[i] = price[i-1] + increment + carry;
            carry = increment;
            sign *= -1;

            if(price[i] > max)
            {
                price[i] -= adjust;
            }
            else if(price[i] < min)
            {
                price[i] += adjust;
            }

            if(price[i] > high)
            {
                high = price[i];
            }
            else if(price[i] < low)
            {
                low = price[i];
            }
        }

        for(i=0; i<size; i++)
        {
            average += price[i];
            for(j=0; j<price[i]; j++)
            {
                printf("_");
            }
            printf("\n");
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

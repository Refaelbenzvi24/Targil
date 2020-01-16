#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void targil(int n, int length, int counter, bool state, bool stop)
{
    int num = n;
    const int numDigits = floor(log10(n));
    int digits[numDigits];

    int i = numDigits;
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;
        digits[i] = digit;
        // printf(" digits: %d i: %d ", digits[i], i);
        i--;
    }
    int lastNum = digits[counter - 1];
    int currentNum = digits[counter];

    if (counter < length)
    {
        if (lastNum < currentNum)
        {
            if (state == true)
            {
                targil(num, length, counter + 1, true, false);
            }
            else if (state == false && state != NULL)
            {
                printf("Answer: %d", 0);
            }
            else if (state == NULL)
            {
                printf("Answer: 0");
            }
        }
        else if (lastNum > currentNum)
        {
            if (state == true)
            {
                printf("Answer %d", 0);
            }
            else if (state == false)
            {
                targil(num, length, counter + 1, false, false);
            }
        }
    }
    else
    {
        if (state == true)
        {
            printf("Answer: %d", 1);
        }
        else if (state == false)
        {
            printf("Answer: %d", -1);
        }
    }
}

void main()
{
    int n;
    printf("Please enter a number which's higher than 9: ");
    scanf("%d", &n);
    const int length = floor(log10(n)) + 1;
    if (n > 9)
    {
        if (length > 10)
        {
            printf("length is more then 10");
            return 0;
        }
        else
        {
            targil(n, length, 1, NULL, false);
        }
    }
    else
    {
        printf("Number must be higher then 9");
    }
}

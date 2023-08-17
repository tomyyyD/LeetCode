#include <stdio.h>

double myPow(double x, int n)
{
    double sum = 1;
    if (n == 0)
        return sum;
    else if (x == 1.0)
        return sum;
    else if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            sum *= x;
        }
    }
    else
    {
        for (int i = 0; i < -(n + 1); i++)
        {
            sum /= x;
        }
        sum /= x;
    }
    return sum;
}

double myPowV2(double x, int n)
{
    int init_n = n;
    double sum = 1;
    if (n == 0)
        return 1;
    while (n != 0)
    {
        if (n & 1)
            sum *= x;
        n = n / 2;
        x *= x;
    }
    return (init_n >= 0) ? sum : 1.0 / sum;
}

int main()
{
    int x = -1;
    printf("%d : %d : %d\n", x >> 1, x / 2, x << 1);
    printf("3 ^ 10 = %F\n", myPowV2(3.00000, 10));
    printf("2 ^ 10 = %F\n", myPowV2(2.00000, 10));
    printf("2.1 ^ 3 = %F\n", myPowV2(2.10000, 3));
    printf("2 ^ -2 = %F\n", myPowV2(2.00000, -2));
    printf("2 ^ -4 = %F\n", myPowV2(2.00000, -4));
    return 0;
}
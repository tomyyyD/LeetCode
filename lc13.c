#include <string.h>
#include <stdio.h>

/*
Solution
================================================================================
*/

int romanToIntV1(char *s)
{
    int vals[22] = {100,
                    500,
                    0,
                    0,
                    0,
                    0,
                    1,
                    0,
                    0,
                    50,
                    1000,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    5,
                    0,
                    10};
    int len = strlen(s);
    int sum = 0;
    char addOnExit;
    for (int i = 0; i < len - 1; i++)
    {
        addOnExit = 1;
        int val = vals[s[i] - 67];
        int next_val = vals[s[i + 1] - 67];
        if (val < next_val)
        {
            sum += (next_val - val);
            i++;
            if (i != len - 2)
                addOnExit = 0;
        }
        else
        {
            sum += val;
        }
    }
    if (addOnExit)
        sum += vals[s[len - 1] - 67];

    return sum;
}

int romanToIntV2(char *s)
{
    int vals[22] = {100,
                    500,
                    0,
                    0,
                    0,
                    0,
                    1,
                    0,
                    0,
                    50,
                    1000,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    5,
                    0,
                    10};
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int val = vals[s[i] - 67];
        int next_val = vals[s[i + 1] - 67];
        if (val < next_val)
            sum -= val;
        else
            sum += val;
    }
    sum += vals[s[len - 1] - 67];
    return sum;
}

int getVal(char n)
{
    switch (n)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}
int romanToIntV3(char *s)
{
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int val = getVal(s[i]);
        int next_val = getVal(s[i + 1]);
        if (val < next_val)
            sum -= val;
        else
            sum += val;
    }
    sum += getVal(s[len - 1]);
    return sum;
}

/*
Testing
================================================================================
*/

int main()
{
    // some test cases
    printf("III: %d\n", romanToIntV3("III"));
    printf("IV: %d\n", romanToIntV3("IV"));
    printf("VII: %d\n", romanToIntV3("VII"));
    printf("IX: %d\n", romanToIntV3("IX"));
    printf("LVIII: %d\n", romanToIntV3("LVIII"));
    printf("CM: %d\n", romanToIntV3("CM"));
    printf("CMXCI: %d\n", romanToIntV3("CMXCI"));
    printf("MCMXCIV %d\n", romanToIntV3("MCMXCIV"));
    printf("MDCXCV %d\n", romanToIntV3("MDCXCV"));
    printf("MDCXCVI %d\n", romanToIntV3("MDCXCVI"));
    printf("MMCMLXIV %d\n", romanToIntV3("MMCMLXIV"));
    return 0;
}
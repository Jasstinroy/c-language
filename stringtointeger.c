#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char *s) {
    int i = 0;
    long result = 0;  
    int sign = 1;

    while (s[i] == ' ')
        i++;


    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-')
            sign = -1;
        i++;
    }


    while (isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');

        if (sign * result >= INT_MAX)
            return INT_MAX;
        if (sign * result <= INT_MIN)
            return INT_MIN;

        i++;
    }

    return (int)(sign * result);
}

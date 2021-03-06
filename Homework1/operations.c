#include "header.h"

int		ft_atoi(char *string)
{
    // Converts the number from a string format to an integer.

    int number, i;

    number = 0;
    i = 0;
    while (string[i])
    {
        number = number * 10 + (string[i] - 48);
        i++;
    }
    return (number);
}

char	*ft_itoa(int number)
{
    // Converts an integer number into a string format number.		

    static char buff[32] = "0";
    int         i;

    while (number)
    {
        buff[i] = "0123456789abcdef"[number % 10];
        --i;
        number /= 10;
    }
    return (buff + i + 1);
}

int		power(int base, int exponent)
{
    // Calculates 'base' at the power of 'exponent'.

    int i, result;

    if (base == 0)
        return (0);
    if (exponent == 0)
        return (1);
    result = base;
    for (i = 2; i <= exponent; i++)
        result *= base;
    return (result);
}

int		charToIntDigit(char c)
{
    // Converts a digit from character to integer.

    if (c == 'A' || c == 'a')
        return (10);
    else if (c == 'B' || c == 'b')
        return (11);
    else if (c == 'C' || c == 'c')
        return (12);
    else if (c == 'D' || c == 'd')
        return (13);
    else if (c == 'E' || c == 'e')
        return (14);
    else if (c == 'F' || c == 'f')
        return (15);
    else
        return (c - 48);
}

char	ft_digit(int rest)
{
    // Converts the rest into a character, ready to be added to the result, at the beginning of the string.

    if (rest == 10)
        return 'A';
    else if (rest == 11)
        return 'B';
    else if (rest == 12)
        return 'C';
    else if (rest == 13)
        return 'D';
    else if (rest == 14)
        return 'E';
    else if (rest == 15)
        return 'F';
    else
        return (rest + 48);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    int     i;
    int     j;

    if (!(result = (char*)malloc(sizeof(strlen(s1) + strlen(s2) + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
        result[i++] = s1[j++];
    j = 0;
    while (s2[j])
        result[i++] = s2[j++];
    result[i] = '\0';
    return (result);
}

void	add_digit(char *result, char digit)
{
    // Adds a digit at the beginning of the result string.

    char    *new_result;
    int     i;

    new_result = (char*)malloc(sizeof(char) * (strlen(result) + 1));
    new_result[0] = digit;
    i = 0;
    while (result[i])
    {
        new_result[i + 1] = result[i];
        i++;
    }
    strncpy(result, new_result, strlen(new_result));
}

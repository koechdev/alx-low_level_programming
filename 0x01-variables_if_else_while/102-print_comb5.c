#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 0; i < 100; i++)
    {
        for (j = i; j < 100; j++)
        {
            int first_digit_i = i / 10;
            int second_digit_i = i % 10;
            int first_digit_j = j / 10;
            int second_digit_j = j % 10;

            putchar('0' + first_digit_i);
            putchar('0' + second_digit_i);
            putchar(' ');

            putchar('0' + first_digit_j);
            putchar('0' + second_digit_j);
            if (i != 99 || j != 99)
            {
                putchar(',');
                putchar(' ');
            }
        }
    }
    return 0;
}
}


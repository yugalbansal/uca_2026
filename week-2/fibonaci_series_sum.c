#include <stdio.h>

int fibonaci_seq_bruteforce(int n)
{
    int a = 1, b = 1;
    int sum = 0;

    while (b <= n)
    {
        if (b % 2 == 0)
            sum += b;

        int c = a + b;
        a = b;
        b = c;
    }

    return sum;
}

int fibonaci_seq_optimized(int n)
{
    int a = 2;
    int b = 8;
    int sum = 0;

    while (a <= n)
    {
        sum += a;

        int c = 4 * b + a;
        a = b;
        b = c;
    }

    return sum;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonaci_seq_bruteforce(n));
    printf("%d\n", fibonaci_seq_optimized(n));
    return 0;
}
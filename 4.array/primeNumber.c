#include <stdio.h>
#include <stdbool.h>

int primes[100] = {0};
int primeIndex = 2;

int main()
{
    primes[0] = 2;
    primes[1] = 3;
    bool isprime = true;
    for (int i = 4; i < 100; i++)
    {
        isprime = true;

        for (int j = 0; j < primeIndex; j++)
        {
            if (i % primes[j] == 0)
            {
                isprime = false;
                break;
            }
        }

        if (isprime == true)
        {
            primes[primeIndex] = i;
            primeIndex++;
        }
    }

    for (int i = 0; i < primeIndex; i++)
    {
        printf("%d ", primes[i]);
    }

    return 0;
}
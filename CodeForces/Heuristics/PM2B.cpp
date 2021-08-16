#include <stdio.h>

int main()
{
    long int n;
    long long int sum = 0;
    scanf("%ld", &n);
    long int a[n];
    for (long int i = 0; i < n; i++)
    {
        scanf("%ld", &a[i]);
    }
    for (long int i = 0; i < n; i++)
    {
        sum += a[i];
        printf("%ld ", sum / (i + 1));
    }
    return 0;
}

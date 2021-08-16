#include <stdio.h>

int main()
{
    long int n;
    float k1, k2, k3, v;
    float t;
    int t1;
    scanf("%ld", &n);
    for (long int i = 0; i < n; i++)
    {
        scanf("%f %f %f %f", &k1, &k2, &k3, &v);
        t = (10000000 / (k1 * k2 * k3 * v));
        t1 = t;
        if (k1 > 0 && k1 < 2 && k2 > 0 && k2 < 2 && k3 > 0 && k3 <= 1 && v > 9 && v < 11)
            if (t1 < 957455)
                printf("YES\n");
            else
                printf("NO\n");
    }

    return 0;
}
#include <stdio.h>

int main()
{
    long int n;
    scanf("%ld", &n);
    int ar[21] = {}; //-10 -9 ... 9 10

    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        ar[temp + 10]++;
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += ar[i] * 1ll * ar[20 - i];
    }

    ans += ar[10] * 1ll * (ar[10] - 1) / 2;
    printf("%lld", ans);
}

/*#include <stdio.h>
     
    int main()
    {
        long int n;
        int ctr = 0;
        scanf("%ld", &n);
        int a[n];
        for (long int i = 0; i < n; i++)
        {
            scanf("%ld", &a[i]);
        }
        for (long int i = 0; i < n; i++)
        {
            for (long int j = i + 1; j < n; j++)
            {
                if (a[j] == -a[i])
                {
                    ctr++;
                }
            }
        }
        printf("%d", ctr);
        return 0;
    }*/
#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    int arr[test];
    for (int m = 0; m < test; m++)
    {
        int n;
        scanf("%d", &n);
        int ar[n], ctrl = 0;
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &ar[i]);
            sum = sum + ar[i];
        }
        if (sum % 2 != 0)
        {
            arr[m] = 1;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (ar[i] % 2 == 0)
                    ctrl++;
            }
            if (ctrl == n || ctrl == 0)
                arr[m] = 0;
            else
                arr[m] = 1;
        }
    }
    for (int t = 0; t < test; t++)
    {
        if (arr[t] == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
#include <iostream>
typedef long long ll;

int main()
{
    std::ios::sync_with_stdio(false);

    ll n;
    std::cin >> n;
    long long arr[n];
    long long max_sum = 0;

    for (ll i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (ll i = 0; i < n; i++)
    {

        long long sum = 0;
        long long a = 1;

        ll rem = n - i;

        while (((a * a + a) / 2) <= rem)
        {
            a++;
        }
        a--;

        long long max = (a * a + a) / 2;

        for (ll j = 0; j < max; j++)
        {
            sum = sum + arr[i + j];
        }

        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }

    std::cout << max_sum << "\n";

    return 0;
} //main
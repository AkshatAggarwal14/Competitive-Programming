#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{

    int n;
    cin >> n;
    n += 2;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll sum = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
        sum += arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (sum - arr[i] == arr[n - 1]) //if x was smaller than sum thus last element is sum
        {
            for (int j = 0; j < n - 1; j++)
                if (j != i)
                    cout << arr[j] << " ";
            cout << "\n";
            return;
        }
    }
    ll s = 0;
    for (int i = 0; i < n - 2; i++) //s is sum excluding last 2 elements
        s += arr[i];
    if (s == arr[n - 2]) //if x is greater than sum thus sum is second last element
    {
        for (int i = 0; i < n - 2; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    cout << -1 << "\n";
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
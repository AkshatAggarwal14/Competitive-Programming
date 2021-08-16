#include <iostream>
using namespace std;

int a[4];

int main()
{
    int n, sum = 0;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        sum += x;
        a[x]++;
    }
    if (sum == 1 or sum == 2 or sum == 5)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    while (a[1] > 0 and a[2] > 0)
    {
        a[3]++;
        ans++;
        a[1]--;
        a[2]--;
    }
    if (a[1] > 0)
    {
        ans += a[1] - a[1] / 3;
        if (a[1] == 1 and a[3] == 0)
            ans++;
    }
    if (a[2] > 0)
    {
        ans += a[2] - a[2] / 3;
        if (a[2] % 3 == 1 and a[4] == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
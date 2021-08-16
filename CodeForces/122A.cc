//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

bool isLucky(ll n)
{
    int flag = 1;
    while (n)
    {
        int digit = n % 10;
        if (digit != 4 && digit != 7)
        {
            flag = 0;
            break;
        }
        n /= 10;
    }
    if (flag)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, temp = 0;
    cin >> n;
    if (isLucky(n) == 1)
    {
        cout << "YES\n";
        return 0;
    }
    rep(i, 1, n)
    {
        if (n % i == 0 && isLucky(i) == 1)
        {
            temp = 1;
            break;
        }
    }
    if (temp)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

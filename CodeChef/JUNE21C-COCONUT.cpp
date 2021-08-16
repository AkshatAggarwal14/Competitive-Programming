#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    if (t >= 1 && t <= 15000)
        while (t--)
        {
            ll xa, xb, Xa, Xb;
            cin >> xa >> xb >> Xa >> Xb;
            if (xa >= 100 && xa <= 200 && xb >= 400 && xb <= 500 && Xa >= 1000 && Xa <= 1200 && Xb >= 1000 && Xb <= 1500 && Xa % xa == 0 && Xb % xb == 0)
                cout << Xa / xa + Xb / xb << "\n";
        }
    return 0;
}
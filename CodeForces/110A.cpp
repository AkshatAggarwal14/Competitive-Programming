//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, c47 = 0, co = 0;
    cin >> t;
    while (t)
    {
        int dig = t % 10;
        if (dig == 4 || dig == 7)
            c47++;
        t /= 10;
    }
    if (c47 == 4 || c47 == 7)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
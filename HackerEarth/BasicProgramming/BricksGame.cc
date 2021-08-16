//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll s = 0, flag = 0;
    for (ll i = 1;; i++)
    {
        s += i;
        if (s >= n)
        {
            flag = 1;
            break;
        }
        s += 2 * i;
        if (s >= n)
        {
            flag = 2;
            break;
        }
    }
    if (flag == 1)
        cout << "Patlu";
    else
        cout << "Motu";
    return 0;
}
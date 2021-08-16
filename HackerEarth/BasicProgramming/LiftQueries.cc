//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    ll a = 1, b = 7;
    rep(i, 0, t)
    {
        ll n;
        cin >> n;
        ll disA = n - a, disB = n - b;
        if (abs(disA) < abs(disB))
        {
            a = n;
            cout << "A\n";
        }
        else if (abs(disA) == abs(disB))
        {
            if (disA >= 0 && disB <= 0)
            {
                a = n;
                cout << "A\n";
            }
            else if (disA <= 0 && disB >= 0)
            {
                b = n;
                cout << "B\n";
            }
            else if (disA * disB >= 0)
            {
                a = n;
                cout << "A\n";
            }
        }
        else
        {
            b = n;
            cout << "B\n";
        }
    }
    return 0;
}
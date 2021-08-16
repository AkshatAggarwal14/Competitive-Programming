//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    /**
In one move, he is allowed to apply one of the two following move on the number:
1. Add 3 to the num, i.e. num = num + 3
2. Subtract 1 from the num, i.e. num = num - 1
Print the minimum number of moves required to make the number a perfect square.
    */
    ll sqroot;
    ll backmoves, n;
    ll frontdiff;
    ll moves = 0;
    std::cin >> n;
    sqroot = std::sqrt(n);
    if (sqroot * sqroot == n)
    {
        cout << "0\n";
        return;
    }
    backmoves = n - sqroot * sqroot;
    frontdiff = (sqroot + 1) * (sqroot + 1) - n;
    ll numOf3 = frontdiff / 3;
    moves = moves + numOf3;
    ll rem = frontdiff - 3 * numOf3;
    {
        if (rem == 2)
            moves = moves + 2;
        else if (rem == 1)
            moves = moves + 3;
    }
    if (backmoves >= moves)
        cout << moves << "\n";
    else
        cout << backmoves << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int M, S;
    cin >> M >> S;
    if (M >= 1 && M <= 100 && S >= 1 && S <= 10)
        cout << M / S << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    if (t >= 1 && t <= 1000)
        while (t--)
            solve();
    return 0;
}
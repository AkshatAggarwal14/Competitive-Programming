//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "NO\n";
    else
        cout << "YES\n";
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
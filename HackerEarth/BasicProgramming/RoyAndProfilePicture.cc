//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l, n;
    cin >> l >> n;
    while (n--)
    {
        ll w, h;
        cin >> w >> h;
        if (w < l || h < l)
            cout << "UPLOAD ANOTHER\n";
        else if (w == h && w >= l && h >= l)
            cout << "ACCEPTED\n";
        else if (w >= l && h >= l)
            cout << "CROP IT\n";
    }
    return 0;
}
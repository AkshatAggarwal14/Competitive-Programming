//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    ll x = 0, y = 0;
    rep(i, 0, str.length())
    {
        if (str[i] == 'z')
            x++;
        else
            y++;
    }
    if (2 * x == y)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
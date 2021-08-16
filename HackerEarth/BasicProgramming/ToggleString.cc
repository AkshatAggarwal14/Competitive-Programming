//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    rep(i, 0, s.length())
    {
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
        else
            s[i] = toupper(s[i]);
    }
    cout << s;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
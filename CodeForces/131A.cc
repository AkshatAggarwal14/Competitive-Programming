//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll flag = 0;
    rep(i, 1, s.length())
    {
        if (isupper(s[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        rep(i, 0, s.length())
        {
            if (isupper(s[i]) != 0)
                s[i] = tolower(s[i]);
            else
                s[i] = toupper(s[i]);
        }
    cout << s;
    return 0;
}
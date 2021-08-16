//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, s1;
    cin >> s;
    s1 = s;
    reverse(s.begin(), s.end());
    if (s1 == s)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
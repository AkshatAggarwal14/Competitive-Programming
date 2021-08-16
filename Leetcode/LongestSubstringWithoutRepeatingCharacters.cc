//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

bool areDistinct(string str, int i, int j)
{

    // Note : Default values in visited are false
    vector<bool> visited(26);

    for (int k = i; k <= j; k++)
    {
        if (visited[str[k] - 'a'] == true)
            return false;
        visited[str[k] - 'a'] = true;
    }
    return true;
}

int longestUniqueSubsttr(string str)
{
    int n = str.size();
    int res = 0; // result
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
    return res;
}

void solve()
{
    string s;
    cin >> s;
    cout << longestUniqueSubsttr(s) << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
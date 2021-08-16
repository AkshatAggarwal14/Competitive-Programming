#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    char a[400][400];

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '*')
                v.push_back({i, j});
        }
    }

    if (v[0].first == v[1].first) //both have same i
    {
        if (v[0].first == 0)
        {
            a[v[0].first + 1][v[0].second] = '*';
            a[v[1].first + 1][v[1].second] = '*';
        }
        else
        {
            a[0][v[0].second] = '*';
            a[0][v[1].second] = '*';
        }
    }
    else if (v[0].second == v[1].second) //both have same j
    {
        if (v[0].second == 0)
        {
            a[v[0].first][v[0].second + 1] = '*';
            a[v[1].first][v[1].second + 1] = '*';
        }
        else
        {
            a[v[0].first][0] = '*';
            a[v[1].first][0] = '*';
        }
    }
    else //else make a square
    {
        a[v[0].first][v[1].second] = '*';
        a[v[1].first][v[0].second] = '*';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << endl;
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
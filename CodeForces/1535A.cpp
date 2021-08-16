/*	ॐ	*/
// Akshat Aggarwal
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ps(x, y) fixed << setprecision(y) << x
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
#define fast_io()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void solve()
{
    ll s[4], temp[4];
    fo(i, 4)
    {
        cin >> s[i];
        temp[i] = s[i];
    }
    sort(s, s + 4);
    if (temp[1] < temp[0])
    {
        ll t = temp[1];
        temp[1] = temp[0];
        temp[0] = t;
    }
    if (temp[3] < temp[2])
    {
        ll t = temp[3];
        temp[3] = temp[2];
        temp[2] = t;
    }
    if ((temp[1] == s[3] || temp[1] == s[2]) && (temp[3] == s[3] || temp[3] == s[2]))
        cout << "YES";
    else
        cout << "NO";
    return;
}

int main()
{
    fast_io();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}
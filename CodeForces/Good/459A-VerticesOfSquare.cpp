//****************master._.mind****************
//-----------Author: Akshat Aggarwal-----------
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define ub upper_bound
#define lb lower_bound
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
#define ln "\n"
#define sz(x) ((ll)(x).size())
#define cn cout << "\n"
#define cy cout << "YES"
#define cno cout << "NO"
#define re return
#define fast_io()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
//cin.tie(NULL) is used to read all input before displaying any output
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-12;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
//ll divisorCount(ll);

void solve()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // if (x1 == x2)
    //     cout << x1 + abs(y1 - y2) << " " << y1 << " " << x2 + abs(y1 - y2) << " " << y2;
    // else if (y1 == y2)
    //     cout << x1 << " " << y1 + abs(x1 - x2) << " " << x2 << " " << y2 + abs(x1 - x2);
    // else if (abs(x1 - x2) == abs(y1 - y2))
    //     cout << x1 << " " << y2 << " " << x2 << " " << y1;
    // else
    //     cout << -1;

    //can be further reduced to

    if (x1 == x2 || y1 == y2)
        cout << x1 + abs(y1 - y2) << " " << y1 + abs(x1 - x2) << " " << x2 + abs(y1 - y2) << " " << y2 + abs(x1 - x2);
    else if (abs(x1 - x2) == abs(y1 - y2))
        cout << x1 << " " << y2 << " " << x2 << " " << y1;
    else
        cout << -1;
    re;
}

int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    clock_t start, end;
    start = clock();

    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
        cn;
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "Time taken:" << ln << ps(time_taken, 6) << " sec\n";
    re 0;
}

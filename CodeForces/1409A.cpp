//****************master._.mind****************
//-----------Author: Akshat Aggarwal-----------
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define ub() upper_bound()
#define lb() lower_bound()
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
const double eps = 1e-12;
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

    ll a, b, ans = 0;
    cin >> a >> b;
    ll diff = abs(a - b);
    //! M1 <-- just M2 in one line
    cout << (diff + 9) / 10;
    //! M2
    // if (diff % 10 == 0)
    //     cout << diff / 10;
    // else
    //     cout << diff / 10 + 1;
    //! M3
    // if (a == b)
    // {
    //     cout << 0;
    //     return;
    // }
    // if (a > b)
    // {
    //     ll temp = a;
    //     a = b;
    //     b = temp;
    // }
    // b -= a;
    // for (ll i = 10; i >= 1; i--)
    // {
    //     if (b == 0)
    //         break;
    //     ll temp = b / i;
    //     b -= temp * i;
    //     ans += temp;
    // }
    // cout << ans;
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
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
    ll n;
    cin >> n;
    ll arr[n];
    set<ll> b;
    fo(i, n)
    {
        cin >> arr[i];
        b.insert(arr[i]);
    }
    // fo(i, n)
    // {
    //     fo(j, n)
    //     {
    //         b.insert(abs(arr[i] - arr[j]));
    //     }
    // }
    ll prev = b.size();
    while (true)
    {
        vl c(all(b));
        sortall(c);
        for (ll i = 0; i < c.size(); i++)
            for (ll j = i + 1; j < c.size(); j++) //! when here j=0 TLE
                if (c[i] != c[j])
                    b.insert(abs(c[i] - c[j]));
        if (b.size() > 300)
        {
            cout << "no\n";
            return;
        }
        if (b.size() == prev)
            break;
        prev = b.size();
    }

    cout << "yes\n"
         << b.size() << "\n";
    tr(it, b) cout << *it << " ";
    cout << "\n";
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
        // cout << "\n";
    }
    return 0;
}
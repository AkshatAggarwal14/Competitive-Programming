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
    ll n;
    cin >> n;
    ll arr[n], sorted[n];
    fo(i, n)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted, sorted + n);
    vpl ans;
    fo(i, n - 1)
    {
        if (sorted[i] != arr[i]) //if that index doesnt match with sorted array
        {
            rep(j, i + 1, n)
            {
                if (arr[j] == sorted[i])
                {
                    ans.pb({i, j});
                    swap(arr[i], arr[j]);
                    break; // go to next i
                }
            }
        }
    }

    cout << sz(ans) << ln;
    for (auto x : ans)
        cout << x.F << " " << x.S << ln;

    re;
}

int main()
{
    fast_io();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        // cn;
    }
    re 0;
}

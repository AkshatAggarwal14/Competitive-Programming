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
    ll arr[n], brr[n];
    fo(i, n)
    {
        cin >> arr[i];
        brr[i] = arr[i];
    }

    sort(brr, brr + n);
    int flag = 0;

    fo(i, n) if (arr[i] != brr[i])
        flag = 1;

    if (flag == 0) //if already sorted
        cout << 0;
    else if (arr[0] == 1 || arr[n - 1] == n)
        cout << 1;
    else if (arr[0] == n && arr[n - 1] == 1)
        cout << 3;
    else
        cout << 2;

    re;
}

int main()
{
    fast_io();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cn;
    }
    re 0;
}

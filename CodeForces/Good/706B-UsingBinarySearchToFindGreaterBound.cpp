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

bool check(ll dig, ll k, ll arr[])
{
    int ele = arr[dig];
    if (k <= ele)
        return 1;
    else
        return 0;
}
void binsrch(ll k, ll arr[], ll n)
{
    ll lo = 0, hi = n;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid, k, arr))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    //if a[lo] is k
    if (arr[lo] <= k)
        cout << lo + 1 << "\n";
}

void solve()
{

    ll n, q;
    cin >> n;
    ll arr[n + 10] = {0};
    fo(i, n)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> q;
    fo(i, q)
    {
        ll x;
        cin >> x;
        ll low = 0, high = n; // numElems is the size of the array i.e arr.size()
        while (low != high)
        {
            ll mid = (low + high) / 2; // Or a fancy way to avoid int overflow
            if (arr[mid] <= x)         //! Important condition NOT arr[mid]<x
                low = mid + 1;
            else
                high = mid;
        }
        cout << low << "\n";
        //* M2
        // cout<<upper_bound(arr, arr + n, x) - arr<<"\n";
        // //! https://stackoverflow.com/questions/6553970/find-the-first-element-in-a-sorted-array-that-is-greater-than-the-target
    }
    return;
}

int main()
{
    fast_io();
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
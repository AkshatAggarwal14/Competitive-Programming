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
    // radius must be max of difference between consecutive lights/2 <---ans
    ll n, l, num;
    cin >> n >> l;
    vl arr;
    fo(i, n)
    {
        cin >> num;
        arr.pb(num);
    }
    ll mini = *min_element(all(arr)), maxi = *max_element(all(arr));
    arr.pb(-mini);        // this is done as if lights at 2,5 where l=5 thus -2 has to be added so ans=2 as from 0
                          // it was done to create mirror image of min element with 0 as mirror
    arr.pb(2 * l - maxi); // this is done to create mirror image of max element with "l" as mirror
    ll diff[n + 1];       // to calculate difference of position between consecutive lights
    sort(all(arr), greater<ll>());
    fo(i, n + 1) diff[i] = arr[i] - arr[i + 1];
    double ans = (double)*max_element(diff, diff + n + 1) / 2;
    cout << ps(ans, 12);

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
        cout << "\n";
    }
    return 0;
}
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

    ll n, num, ans;
    cin >> n;
    ll arr[n], count[5]{0};                   //!ignore count[0] and use 1,2,3,4 to count
    fo(i, n)                                  //
    {                                         //
        cin >> num;                           //
        count[num]++;                         //! stores count of 1,2,3,4
    }                                         //
    ans = count[4];                           //! first atleast taxis = 4 ka group
    ans += count[3];                          //
    count[1] = max(count[1] - count[3], 0LL); //! from 1 and 3
    ans += count[2] / 2;                      //! from 2's
    count[2] %= 2;                            //
    if (count[2])                             //
    {                                         //
        ++ans;                                //
        if (count[1])                         //
            --count[1];                       //
        if (count[1])                         //
            --count[1];                       //
    }                                         //! from 1 and 2's
    ans += count[1] / 4;                      //
    count[1] %= 4;                            //! 4 from 1's
    ans += count[1] / 3;                      //
    count[1] %= 3;                            //! 3 from 1's
    ans += count[1] / 2;                      //
    count[1] %= 2;                            //! 2 from 1's
    ans += count[1];                          //! remaining 1's in seperate taxi's as all other pairs already made

    cout << ans << endl;
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
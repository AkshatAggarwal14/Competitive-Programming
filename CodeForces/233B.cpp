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

ll DigitSum(ll n)
{
    ll sum = 0;
    string s = to_string(n);
    fo(i, s.length()) sum += s[i] - '0';
    return sum;
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = -1;
    for (ll sx = 1; sx <= 162; sx++) // max sx is of 99999999.. 18 digits => 9*18 => 162
    {
        double sq1 = sqrtl(sx * sx + 4 * n); // sqrtl is sqrt for ll
        ll sq2 = (ll)sqrtl(sx * sx + 4 * n);
        ll x = (sq2 - sx) / 2; //-b+sq2/2 <- quadratic formula, only one solution here as x>0
        if ((sq1 - sq2) == 0.0)
        { /// if determinant is full square
            if (x > 0 && DigitSum(x) == sx)
            {
                ans = x;
                break;
            }
        }
    }
    cout << ans;
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
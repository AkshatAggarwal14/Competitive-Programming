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
    //! M1 number of round numbers required will be number of digits in n that are no zero, example: 509=500+9,1012=1000+10+2
    string s;
    cin >> s;
    int n = s.length();
    int count = 0;
    fo(i, n) if (s[i] != '0') // count number of digits that are not zero
        count++;
    cout << count << endl;
    for (int i = 0; i < n; ++i)
        if (s[i] != '0')
            cout << (s[i] - '0') * pow(10, (n - 1) - i) << " ";

    //! M2 Brute force method by making a vector with all round numbers until n
    // vl vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    // sort(all(vec), greater<ll>());
    // vl ans;
    // ll n, k = 0;
    // cin >> n;
    // for (ll i = 0; i < vec.size() && n > 0; i++)
    // {
    //     ll times = n / vec[i];
    //     n -= vec[i] * times;
    //     k += times;
    //     if (times != 0)
    //         ans.insert(ans.end(), times, vec[i]);
    // }
    // cout << k << "\n";
    // tr(it, ans) cout << *it << " ";
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
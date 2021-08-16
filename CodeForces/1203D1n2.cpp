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

    string s;
    cin >> s;
    string t;
    cin >> t;
    int n = s.size(), m = t.size();
    int mx[m + 1];
    int j = m - 1;
    mx[m] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == t[j])
        {
            mx[j] = i;
            j--;
        }
        if (j < 0)
            break;
    }
    int ans = mx[0]; // position of first element of subsequence from end
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[j])
        {
            ans = max(ans, mx[j + 1] - (i + 1)); //mx[j+1] is position of next letter in subsequence
            // we find max of ans, distance between two letters of subsequence
            j++;
        }
        if (j >= m)
            break;
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
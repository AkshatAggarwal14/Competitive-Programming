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
    //! M1- USE MAPS
    /* string s;
    * set<char> found;
    * getline(cin, s);
    * ll i = 1;
    * fo(i, s.length())
    * {
    *     if (s[i] == ' ' || s[i] == ',' || s[i] == '{')
    *         continue;
    *     else if (s[i] == '}')
    *         break;
    *     else
    *         found.insert(s[i]);
    * }
    * tr(i, found) { cout << *i << " "; }
    * cout << found.size() << endl;
    */
    //! M2- SORT STRING
    int c = 0;
    string s;
    getline(cin, s);
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '}' || s[i] == ',' || s[i] == ' ')
            continue;
        else
        {
            if (s[i] != s[i + 1])
                c++;
        }
    }
    cout << c;
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
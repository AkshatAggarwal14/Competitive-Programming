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

void solve() {
    string s;
    cin >> s;
    while (true) {
        ll i = s.find("WUBWUB");
        if (i == string::npos)
            break;
        s.replace(i, 3, "");
    }
    while (true) {
        ll i = s.find("WUB");
        if (i == string::npos)
            break;
        else if (i == 0)
            s.replace(i, 3, "");
        else
            s.replace(i, 3, " ");
    }
    cout << s;

    // string s;
    // cin >> s;
    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (s[i] != 'W' || s[i + 1] != 'U' || s[i + 2] != 'B') //if it forms something else than WUB
    //     {
    //         cout << s[i];
    //         if (s[i + 1] == 'W' && s[i + 2] == 'U' && s[i + 3] == 'B') // next 3 letters are WUB then space
    //             cout << " ";
    //     }
    //     else
    //         i += 2;
    // }
    /*
    string s;
    cin >> s;
    while (true)
    {
        ll i = s.find("WUB");
        if (i == string::npos)
            break;
        else if (i == 0)
            s.replace(i, 3, "");
        else
            s.replace(i, 3, " "); //!ADDS UNNECESSARY SPACES
    }
    cout << s;
*/
    return;
}

int main() {
    fast_io();
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
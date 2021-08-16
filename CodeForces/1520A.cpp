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

    int alphabet_count[26] = {0};
    int n;
    cin >> n;
    string s;
    cin >> s;
    fo(i, s.length())
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 1);
            i--; // to come back and not miss any letter
        }
    }
    fo(i, s.length()) alphabet_count[s[i] - 'A']++;

    // cout << s << endl;
    // int flag = 0;
    // for (int j = 0; j < 26; j++) {
    //     if (alphabet_count[j] > 1) {
    //         cout << "NO\n";
    //         break;
    //     } else {
    //         flag = 1;
    //     }
    // }
    // if (flag) cout << "YES\n";

    sort(alphabet_count, alphabet_count + 26); //! now last element is largest
    if (alphabet_count[25] > 1)                //checking if last element of sorted array is greater than 1
        cout << "NO";
    else
        cout << "YES";

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
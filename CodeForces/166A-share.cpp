#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double
#define ull unsigned long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define rall(x) (x).rbegin(), (x).rend()
#define ps(x, y) fixed << setprecision(y) << x
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define sz(x) ((ll)(x).size())
#define fast_io()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;

ll n, k;

void solve() {
    cin >> n >> k;
    vpl arr(n);
    map<pl, ll> mep;
    fo(i, n) {
        cin >> arr[i].ff >> arr[i].ss;
        mep[arr[i]]++;
    }
    sort(all(arr), [&](pl a, pl b) {  //lambda
        if (a.ff > b.ff)
            return true;
        else if (a.ff == b.ff) {
            if (a.ss < b.ss)
                return true;
            else
                return false;
        } else
            return false;
    });
    // _print(arr);
    cout << mep[arr[k - 1]] << '\n';
    return;
}

int main() {
    ll tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}

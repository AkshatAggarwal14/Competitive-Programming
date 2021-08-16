//**********************master._.mind**********************
//-----------------Author: Akshat Aggarwal-----------------
//If you don't understand the code below... dont worry, i didn't either
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double
#define ull unsigned long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
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
#define endl "\n"
#define ln "\n"
#define sz(x) ((ll)(x).size())
#define cn cout << "\n"
#define cy cout << "YES"
#define cno cout << "NO"
#define re return
#define fast_io()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
//cin.tie(NULL) is used to read all input before displaying any output
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const double eps = 1e-12;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

//divisor_count(ll)
//prime_facorisation(n)
//primes_less_than(n)

//* Global vars
ll n;

void solve() {
    //*********************CODE STARTS HERE*********************

    cin >> n;
    ll V[n];
    rep(i, 0, n) {
        cin >> V[i];
        if (V[i] < 0 || V[i] > 5) re;
    }

    ll best = n;
    ll worst = 1;
    rep(i, 0, n) {
        vector<bool> infect(n);
        infect[i] = true;
        ll cnt = 0;
        ll mx = V[i], mn = V[i];
        for (ll j = i - 1; j >= 0; j--) {
            if (V[j] > V[i]) infect[j] = true;
            mx = max(mx, V[j]);
        }
        rep(j, i + 1, n) {
            if (V[j] < mx) infect[j] = true;
            mn = min(mn, V[j]);
        }
        for (ll j = i - 1; j >= 0; j--) {
            if (V[j] > mn) infect[j] = true;
        }
        rep(j, 0, n) cnt += infect[j];
        worst = max(worst, cnt);
        best = min(best, cnt);
    }

    if (n >= 3 && n <= 5)
        cout << best << " " << worst;

    //**********************CODE ENDS HERE**********************
    re;
}  //todo solve

int main() {
    fast_io();

    ll testcases = 1;
    //todo testcases
    cin >> testcases;
    if (testcases >= 1 && testcases <= 100000)
        while (testcases--) {
            solve();
            cn;
        }

    re 0;
}  //todo main

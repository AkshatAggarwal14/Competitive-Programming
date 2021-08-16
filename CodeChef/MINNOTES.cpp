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

//* --------pre defined functions--------
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

//divisor_count(ll)
//prime_facorisation(n)
//primes_less_than(n)

ll MaxGCD(vl a) {
    ll n = a.size();
    ll Prefix[n + 2], Suffix[n + 2];
    Prefix[1] = a[0];
    for (ll i = 2; i <= n; i += 1) {
        Prefix[i] = __gcd(Prefix[i - 1], a[i - 1]);
    }
    Suffix[n] = a[n - 1];
    for (ll i = n - 1; i >= 1; i -= 1) {
        Suffix[i] = __gcd(Suffix[i + 1], a[i - 1]);
    }
    ll ans = max(Suffix[2], Prefix[n - 1]);
    for (ll i = 2; i < n; i += 1) {
        ans = max(ans, __gcd(Prefix[i - 1], Suffix[i + 1]));
    }
    return ans;
}

ll gcdVec(vl a) {
    ll gcd = a[0];
    rep(i, 1, a.size()) {
        gcd = __gcd(gcd, a[i]);
    }
    return gcd;
}

//* Global vars
ll n;

void solve() {
    //*********************CODE STARTS HERE*********************

    cin >> n;
    vl arr(n);
    map<ll, ll> mp;
    fo(i, n) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    fo(i, n) if (arr[i] < 1 or arr[i] > 1e9) re;

    if (mp.size() == 1) {
        cout << n;
        re;
    }
    sortall(arr);
    ll gcd = MaxGCD(arr);
    // _print(gcd);
    if (gcd == gcdVec(arr)) {
        arr[n - 1] = gcd;
        ll ans = 0;
        fo(i, n) ans += arr[i] / gcd;
        if (n >= 1 && n <= 1e5)
            cout << ans;
        re;
    }
    // 2 2 4 6 must give 5 but its giving 8
    ll ans = 1;
    fo(i, n) if (arr[i] % gcd == 0) ans += arr[i] / gcd;
    if (n >= 1 && n <= 1e5)
        cout << ans;

    //**********************CODE ENDS HERE**********************
    re;
}  //todo solve

int main() {
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    clock_t start, end;
    start = clock();

    ll testcases = 1;
    //todo testcases
    cin >> testcases;
    if (testcases >= 1 && testcases <= 120000)
        while (testcases--) {
            solve();
            cn;
        }

    //* -----for time calc-----
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "\nTime taken:" << ln << ps(time_taken, 6) << " sec\n";
    re 0;
}  //todo main

//* ------function definitions------
template <class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
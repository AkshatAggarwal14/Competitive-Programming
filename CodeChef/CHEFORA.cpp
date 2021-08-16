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

//* Global vars
vl pal, prefix(100000);
ll l, r;
string s;
// string rev;
ll num;

//ALL ODD palindrome in series are in form: 1-1 2-2 ... 10-101... 956-95659
void fill() {
    for (ll i = 1; i <= 100000; i++) {
        s = to_string(i);
        if (s.length() >= 2)
            for (ll i = s.length() - 2; i >= 0; i--) s += s[i];
        // rev = s.substr(0, s.size() - 1);
        // reverse(all(rev));
        // s += rev;
        stringstream ss(s);
        ss >> num;
        pal.pb(num);
    }
}

void fillPrefix() {
    prefix[0] = pal[0];
    rep(i, 1, pal.size()) prefix[i] = (pal[i] + prefix[i - 1]);
}

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}

void solve() {
    //*********************CODE STARTS HERE*********************

    //* testing stuff
    // cout << prefix.size() << ln;
    // for (auto &x : prefix) cout << x << " ";
    // cout << pal.size() << ln;
    // for (auto &x : pal) cout << x << " ";

    cin >> l >> r;
    ll raiseto = prefix[r - 1] - prefix[l - 1];
    // deb(raiseto);
    //? now just need to calculate A[l]^raiseto <>mod
    // cout << pal[l - 1] << "^" << raiseto << " = ";
    if (l >= 1 && l < r && r <= 1e5)
        cout << power(pal[l - 1], raiseto, mod);

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

    fill();
    fillPrefix();

    ll testcases = 1;
    //todo testcases
    cin >> testcases;
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
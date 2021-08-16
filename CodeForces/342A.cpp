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
#define sz(x) ((ll)(x).size())
#define ln '\n'
#define cy cout << "YES"
#define cno cout << "NO"
#define cn cout << '\n'
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
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;

//* --------Debug--------
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
ll n;

void solve() {
    //*********************CODE STARTS HERE*********************

    cin >> n;
    // only 1 2 4, 1 3 6, 1 2 6 are possible
    ll cnt[8] = {};
    vl arr(n);
    fo(i, n) cin >> arr[i], ++cnt[arr[i]];
    if (cnt[5] || cnt[7])
        cout << -1;
    else {
        ll type1 = cnt[4];  // 1 2 4
        cnt[4] -= type1;
        cnt[2] -= type1;
        cnt[1] -= type1;
        ll type2 = cnt[3];  // 1 3 6
        cnt[6] -= cnt[3];
        cnt[3] -= type2;
        cnt[1] -= type2;
        int type3 = cnt[6];  // 1 2 6
        // cout << "f";
        if (type3 < 0) {
            cout << -1;
            re;
        }
        cnt[6] -= type3;
        cnt[2] -= type3;
        cnt[1] -= type3;
        for (int i = 1; i <= 7; ++i) {
            if (cnt[i] != 0) {  //all are not used
                cout << -1;
                re;
            }
        }
        fo(i, type1) cout << "1 2 4\n";
        fo(i, type2) cout << "1 3 6\n";
        fo(i, type3) cout << "1 2 6\n";
    }

    //! TLE
    /*
    vector<pair<ll, bool>> vec(n, {0, true});
    fo(i, n) cin >> vec[i].ff;
    sortall(vec);
    vector<vector<ll>> ans;
    for (ll i = 0; i < n - 2; i++) {
        if (vec[i].ss == true) {
            // deb(vec[i].ss);
            for (ll j = i + 1; j < n - 1; j++) {
                if (vec[j].ss == true) {
                    for (ll k = j + 1; k < n; k++) {
                        if (vec[k].ss == true) {
                            ll a = vec[i].ff, b = vec[j].ff, c = vec[k].ff;
                            if (a < b && b < c && b % a == 0 && c % b == 0) {
                                if (vec[i].ss == true && vec[j].ss == true && vec[k].ss == true) {
                                    vl arr;
                                    arr.pb(a);
                                    arr.pb(b);
                                    arr.pb(c);
                                    ans.pb(arr);
                                    // deb2(a, b);
                                    // cout << a << " " << b << " " << c << ln;
                                    vec[i].ss = false;
                                    vec[j].ss = false;
                                    vec[k].ss = false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ans.size() == n / 3)
        for (auto x : ans) cout << x[0] << " " << x[1] << " " << x[2] << ln;
    else
        cout << -1;
    _print(vec);
*/

    //**********************CODE ENDS HERE**********************
    // cn;
    return;
}  //todo solve

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    fast_io();
    clock_t start, end;
    start = clock();

    ll tc = 1;
    //cin >> tc;
    while (tc--)
        solve();

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "Time taken:" << ln << ps(time_taken, 6) << " sec\n";
    return 0;
}  //todo main

//* ------Debug------
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
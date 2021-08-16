/*
    Akshat Aggarwal , @master._.mind , NIT Hamirpur
*/
#include "bits/stdc++.h"
using namespace std;
using namespace std::chrono;

#define ll long long
#define db long double
#define str string
#define ull unsigned long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define ln '\n'
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << "[" << #x << "]: " << x << ln
#define deb2(x, y) cout << "[" << #x << "]: " << x << ", [" << #y << "]: " << y << ln
#define bit(x) __builtin_popcount(x)
#define bitll(x) __builtin_popcountll(x)
#define popb pop_back
#define pb push_back
#define eb emplace_back
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
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define sz(x) ((ll)(x).size())
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const db eps = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;

//debug template begins
string to_string(string s) { return '"' + s + '"'; }
string to_string(char ch) {
    string s(1, ch);
    return '\'' + s + '\'';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) { return "{" + to_string(p.ff) + ", " + to_string(p.ss) + "}"; }

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << to_string(H) << ln;
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
//debug template ends

template <typename T>
void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&...args) {
    cout << t << " ";
    print(forward<Args>(args)...);
}  //print template ends

template <typename T, typename T1>
T amax(T &a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
    if (b < a) a = b;
    return a;
}

void Solution() {
    ll n;
    cin >> n;
    vl a(n);
    fo(i, n) cin >> a[i];
    vl b(n);
    fo(i, n) cin >> b[i];
    /**
     * For lexographically smallest we minimise the first element and then minimise the second element and so on.
     * 
     * Rotate B_i to position 0 such that C_0= (A_0+B_i)%N is minimum
     * 
     * there will only be atmost 2 such arrays such that 
     * C_0= X= (A_0+B_i) mod N
     * 
     * B_i= (X-A_0) mod N only 2 values
     * 
     * First step: Find X
     * Second step: Find B_i such that B_i= (X-A_0) mod N is minimum
     * Third step: Generate the possible sequences(atmost 2)
     * Fourth step: Find the best one
    */
    vl vals;
    ll best = LLONG_MAX;
    fo(i, n) {
        if ((a[0] + b[i]) % n < best) {
            best = (a[0] + b[i]) % n;
            vals.clear();
        }
        if ((a[0] + b[i]) % n == best) {
            vals.pb(i);
        }
    }
    debug(vals);

    vvl options;
    for (auto i : vals) {  //iterate over every possible B_i
        vl cur;            //current sequence
        fo(j, n) {
            cur.eb((a[j] + b[(j + i) % n]) % n);  //  b[(j + i) % n] is to rotate
        }
        options.eb(cur);
    }
    sort(all(options));
    for (auto x : options[0]) cout << x << " ";
    cout << ln;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    auto start = chrono::high_resolution_clock::now();

    ll tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-6;
    cerr << ps(time_taken, 6) << " ms" << ln;
    return 0;
}
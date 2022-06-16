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

struct pts {
    ll x, y, c;
};

void Solution() {
    ll n;
    cin >> n;
    vpl pt(n);
    vector<pair<pl, ll>> line;
    map<tuple<ll, ll, ll>, ll> mp;
    fo(i, n) cin >> pt[i].ff >> pt[i].ss;
    fo(i, n) {
        rep(j, i + 1, n) {
            ll x1 = pt[i].ff, x2 = pt[j].ff;
            ll y1 = pt[i].ss, y2 = pt[j].ss;
            ll c = x2 * y1 - x1 * y2;
            ll d = __gcd((x1 - x2), (y2 - y1));       //ax+by=c,
            ll a = (y1 - y2) / d, b = (x1 - x2) / d;  //to simplify
            c = a * x1 - b * y1;
            if (!mp[tie(a, b, c)]) {  // if doesnt already exists
                line.pb({{a, b}, c});
                mp[tie(a, b, c)] = 1;
            }
        }
    }
    debug(pt, line);
    // fo(i, sz(line)) cerr << line[i].ff.ff << " " << line[i].ff.ss << " " << line[i].ss << ln;

    ll len = sz(line), ans = 0;
    // fo(i, len) {
    //     rep(j, i + 1, len) {
    //         //as parallel lines wont intersect
    //         if (line[i].ff.ff == line[j].ff.ff && line[i].ff.ss == line[j].ff.ss)
    //             continue;
    //         ans++;
    //     }
    // }
    map<pl, ll> mepp;  //for parallel lines
    fo(i, len)++ mepp[{line[i].ff.ff, line[i].ff.ss}];
    debug(mepp);
    ll parallel = 0;
    tr(it, mepp) if (it->ss != 1) parallel += (it->ss * (it->ss - 1)) / 2;
    ans = (len * (len - 1)) / 2 - parallel;
    cout << ans << ln;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    auto start = chrono::high_resolution_clock::now();

    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        Solution();
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-6;
    cerr << ps(time_taken, 6) << " ms" << ln;
    return 0;
}
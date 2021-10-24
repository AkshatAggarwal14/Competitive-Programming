/*
    Akshat Aggarwal , @master._.mind , NIT Hamirpur
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include "bits/stdc++.h"

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

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
#define present(b, a) ((a).find((b)) != (a).end())  //if b is present in a
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
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
    ll n, w;
    cin >> n >> w;
    vl a(n);
    fo(i, n) cin >> a[i];
    vector<pair<ll, pl>> ans(n);
    fo(i, n) ans[i] = {0, {a[i], i}};  //< val, <volume, index> >
    ans[0].ff = ceil(a[0] / 2.0);
    rep(i, 1, n) ans[i].ff = (ll)ceil(a[i] / 2.0);
    // rep(i, 1, n) ans[i].ff = max((ll)ceil(a[i] / 2.0), ans[i - 1].ff);
    // debug(ans);
    ll min_tea = 0;
    fo(i, n) min_tea += ans[i].ff;
    if (min_tea > w) {
        cout << -1 << ln;
    } else {
        sort(all(ans), [&](pair<ll, pl> a, pair<ll, pl> b) { return a.ss.ff > b.ss.ff; });  //dec order of volume
        ll left_tea = w - min_tea;
        fo(i, n) {
            ll left_vol = ans[i].ss.ff - ans[i].ff;
            if (left_vol > left_tea) {
                ans[i].ff += left_tea;
                break;
            } else {
                ans[i].ff += left_vol;
                left_tea -= left_vol;
            }
            // ans[i].ff += min(left_tea, ans[i].ff - ans[i].ss.ff);
            // left_tea -= min(left_tea, ans[i].ff - ans[i].ss.ff);
        }
        sort(all(ans), [&](pair<ll, pl> a, pair<ll, pl> b) { return a.ss.ss < b.ss.ss; });  //inc order of index
        fo(i, n) cout << ans[i].ff << " ";
        cout << ln;
    }

    //read stuff at the bottom
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        Solution();
    }

    // cerr << clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}

/*
    ? Stuff to look for ->
    * stay organised
    * int overflows, array bounds, etc.
    * special cases (n=1)?
    * do something instead of nothing
    * modulo of negative numbers is not a%b, it is a%b + abs(b)
    * When using a set, lower_bound(all(set),l) is slower than set.lower_bound(l) because of random iterators
    * DONT GET STUCK ON ONE APPROACH
*/
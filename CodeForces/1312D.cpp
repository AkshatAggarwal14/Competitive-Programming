#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using ll = int64_t;
using db = double;
using str = string;
using ull = unsigned long long;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define set_bits(x) __builtin_popcountll(x)
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define ps(x, y) fixed << setprecision(y) << x
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define sz(x) ((ll)(x).size())
template <class T>
using V = vector<T>;
using vl = V<ll>;
using vvl = V<vl>;
template <class T, class U = T>
using P = pair<T, U>;
using pl = P<ll, ll>;
using vpl = V<pl>;
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const db eps = 1e-12;
const double PI = acos(-1);

template <class T, class U = T>
bool amin(T& a, U&& b) {
    return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool amax(T& a, U&& b) {
    return a < b ? a = std::forward<U>(b), true : false;
}

#define NCR
const ll N = 200043;
const ll MOD = 998244353;

ll add(ll x, ll y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}
ll mul(ll x, ll y) {
    return (x * 1ll * y) % MOD;
}
ll binpow(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) {
            res = mul(res, x);
            y--;
        } else {
            x = mul(x, x);
            y /= 2;
        }
    }
    return res % mod;
}
ll inv(int x) {
    return binpow(x, MOD - 2);
}
ll divide(ll x, ll y) {
    return mul(x, inv(y));
}
ll fact[N];
void init() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}
ll C(ll n, ll k) {
    if (n < 0 or k < 0 or k > n) return 0;
    return divide(fact[n], mul(fact[k], fact[n - k]));
}

void Solution() {
    // cout << "Case #" << _i << ": ";
    ll n, m;
    cin >> n >> m;
    /**
     * Choose n-1 distinct elements out of m = C(m, n-1)
     * Choose the element to be repeated (cant be maximum as per given condition) = (n-2)
     * Maximum and repeated - fixed, one element has 2 options, either right or left = (2 ^ n-3)
    */
    ll ans = mul(C(m, n - 1), mul(n - 2, binpow(2, n - 3)));
    cout << ans << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef NCR
    init();
#endif
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) Solution();
    cerr << "\n";
    cerr << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
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
    * string .append() or += is O1, but s = s + s is On (as it creates a copy first), use wisely
    * DONT GET STUCK ON ONE APPROACH
    * use __lg(n) instead of log2(n), int: 32 - __builtin_clz(n), ll: 63 - __builtin_clzll(n), https://codeforces.com/blog/entry/45966
    * string.rfind() finds first occurence from end
    * (a & b) + (a | b) = a + b
    * TLE due to ll ? or multiple copies of large DS?
    * Using erased iterators ?
*/
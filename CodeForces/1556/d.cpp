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
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

#define ll long long
#define db double
#define str string
#define ull unsigned long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define ln '\n'
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << "[" << #x << "]: " << x << ln
#define deb2(x, y) cout << "[" << #x << "]: " << x << ", [" << #y << "]: " << y << ln
#define bit(x) __builtin_popcount(x)
#define bitll(x) __builtin_popcountll(x)
#define pb push_back
#define eb emplace_back
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
#define present(b, a) ((a).find((b)) != (a).end())
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const db eps = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef pair<db, db> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

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

//*Operator overloads
template <typename T1, typename T2>  // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template <typename T>  // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) cin >> it;
    return istream;
}
template <typename T1, typename T2>  // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template <typename T>  // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c) cout << it << " ";
    return ostream;
}

template <typename T>
void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&...args) {
    cout << t << " ";
    print(forward<Args>(args)...);
}

ll q_and(ll i, ll j) {
    cout << "and " << i << " " << j << endl;
    ll res;
    cin >> res;
    return res;
}

ll q_or(ll i, ll j) {
    cout << "or " << i << " " << j << endl;
    ll res;
    cin >> res;
    return res;
}

void Solution() {
    //! key: (a & b) + (a | b) = a + b

    ll n, k;
    cin >> n >> k;
    ll s1 = q_and(1, 2) + q_or(1, 2);  //a+b
    ll s2 = q_and(2, 3) + q_or(2, 3);  //b+c
    ll s3 = q_and(1, 3) + q_or(1, 3);  //a+c
    vl a(n);
    a[0] = ((s1 + s3) - s2) / 2;
    a[1] = ((s1 + s2) - s3) / 2;
    a[2] = ((s2 + s3) - s1) / 2;
    for (ll i = 4; i <= n; ++i) {
        ll x = q_and(1, i) + q_or(1, i);
        a[i - 1] = x - a[0];
    }
    sort(all(a));
    cout << "finish " << a[k - 1] << endl;

    //? https://codeforces.com/blog/entry/94384?#comment-834316
    // 5n/3 queries using
    //! (a ^ b) = (a & b) ^ (a | b)
    //! (b ^ c) = (a ^ b) ⊕ (a ^ c) <- FREE
    //! (a + b) = (a ^ b) + 2 * (a & b)
}

int main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        Solution();
    }

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
*/
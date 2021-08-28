#ifndef ONLINE_JUDGE
#include "Akshat.h"
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
    //! m1 - TLE
    // ll a=1,b=1,c=1;
    // ll n;
    // cin >> n;
    // ll ctr = 0;
    // rep(i, 1, n + 1) {
    //     rep(j, 1, n + 1) {
    //         rep(k, 1, n + 1) {
    //             if (i % k == 0 && j % k == 0 && i % j == k) {
    //                 // dbg(i, j, k);
    //                 ctr++;
    //             }
    //         }
    //     }
    // }
    // cout << ctr << ln;

    //! m2 - TLE
    // ll a = 1, b = 1, c, n;
    // cin >> n;
    // vector<pair<ll, pl>> v;
    // c = 1;
    // while (c <= n) {
    //     a = c, b = a + c;
    //     while (b <= n && a <= n) {
    //         v.pb({c, {b, c}});
    //         b += c;
    //     }

    //     a = 3 * c, b = a - c;
    //     while (a <= n && b <= n) {
    //         while (b <= n && b > 0) {
    //             if (a % c == 0 && b % c == 0 && a % b == c)
    //                 v.pb({a, {b, c}});
    //             b -= c;
    //         }
    //         // v.insert({a, {b, c}});
    //         a += c;
    //         b = a - c;
    //     }

    //     c++;
    // }
    // uniq(v);
    // dbg(v);
    // cout << sz(v) << "\n";

    // p1: 2, 4, 5, 8, 9, 12, 14, 17, 18, 23,
    // p2: 1, 2, 3, 5, 6, 8, 10, 12, 13, 17,
    //3 6 9 27539

    //!m3 - TLE
    // ll n;
    // ll ans = 0;
    // cin >> n;
    // // b>c as a%b==c gives values 0,1,2...b-1 thus c<b
    // for (ll b = 2; b <= n; b++) {  //b cant be 1
    //     for (ll c = 1; c < b; ++c) {
    //         if (b % c == 0) {
    //             // dbg(b, c);
    //             // a%b==c so a start from c
    //             for (ll a = c; a <= n; a += b) {  //a+=b for every step
    //                 // dbg(a, b, c);
    //                 ans++;
    //             }
    //         }
    //     }
    // }
    // dbg(ans);
    // print(ans);

    //? m4 (USE INT)
    // int n;
    // int ans = 0;
    // cin >> n;
    // // b>c as a%b==c gives values 0,1,2...b-1 thus c<b
    // rep(c, 1, n + 1) {  //b cant be 1
    //     for (int b = c; b <= n; b += c) {
    //         if (b % c == 0) {
    //             // dbg(b, c);
    //             // a%b==c so a start from c
    //             for (int a = c; a <= n; a += b) {  //a+=b for every step
    //                 if (a % b == c) {
    //                     // dbg(a, b, c);
    //                     ans++;
    //                 }
    //             }
    //         }
    //     }
    // }
    // dbg(ans);
    // print(ans);

    //? m5
    int ans = 0;
    ll n;
    cin >> n;
    for (int c = 1; c <= n; ++c) {
        for (int b = 2 * c; b <= n; b += c) {
            ans += ((n - c) / b) + 1;  //these are only possible values of a
        }
    }
    print(ans);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }

    cerr << clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
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
*/
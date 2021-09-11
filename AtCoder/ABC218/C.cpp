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

ll n;
void Rotate(vector<vector<char>> &mat) {
    for (int x = 0; x < n / 2; x++) {
        for (int y = x; y < n - x - 1; y++) {
            int temp = mat[x][y];
            mat[x][y] = mat[y][n - 1 - x];
            mat[y][n - 1 - x] = mat[n - 1 - x][n - 1 - y];
            mat[n - 1 - x][n - 1 - y] = mat[n - 1 - y][x];
            mat[n - 1 - y][x] = temp;
        }
    }
}

void Solution() {
    cin >> n;
    vector<vector<char>> vv1(n, vector<char>(n, '.'));
    vector<vector<char>> vv2(n, vector<char>(n, '.'));
    fo(i, n) fo(j, n) cin >> vv1[i][j];
    fo(i, n) fo(j, n) cin >> vv2[i][j];

    vpl cnt2;
    fo(i, n) fo(j, n) if (vv2[i][j] == '#')
        cnt2.eb(i, j);  //storing pos of #

    ll min_i = LLONG_MAX, min_j = LLONG_MAX;
    for (auto [x, y] : cnt2) {
        amin(min_i, x);
        amin(min_j, y);
    }
    for (auto &[x, y] : cnt2) {  //normalising by subtracting mini index
        x -= min_i;
        y -= min_j;
    }

    vector<vector<char>> v = vv1;
    fo(k, 4) {
        //options of vv1
        // store pos of # and normalise, and check if equal
        //! normalise important as translation allowed
        vpl cnt1;
        fo(i, n) fo(j, n) if (v[i][j] == '#')
            cnt1.eb(i, j);

        ll min_i2 = LLONG_MAX, min_j2 = LLONG_MAX;
        for (auto [x, y] : cnt1) {
            amin(min_i2, x);
            amin(min_j2, y);
        }
        for (auto &[x, y] : cnt1) {
            x -= min_i2;
            y -= min_j2;
        }

        if (cnt1 == cnt2) {
            print("Yes");
            return;
        }
        Rotate(v);
    }
    print("No");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

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
    * (a & b) + (a | b) = a + b
    * TLE due to ll ?
*/
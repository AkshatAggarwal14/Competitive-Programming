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

vector<vector<char>> vv, check;

bool Check(ll i, ll j) {
    return (vv[i - 1][j - 1] == '#' && vv[i][j - 1] == '#' && vv[i + 1][j - 1] == '#' && vv[i + 1][j] == '#' && vv[i + 1][j + 1] == '#' && vv[i][j + 1] == '#' && vv[i - 1][j + 1] == '#' && vv[i - 1][j] == '#');
}

void Mark(ll i, ll j) {
    check[i - 1][j - 1] = '#', check[i][j - 1] = '#', check[i + 1][j - 1] = '#', check[i + 1][j] = '#', check[i + 1][j + 1] = '#', check[i][j + 1] = '#', check[i - 1][j + 1] = '#', check[i - 1][j] = '#';
}

void Solution() {
    ll n, m;
    cin >> n >> m;
    n += 2;
    m += 2;
    vv.resize(n, vector<char>(m, '.'));
    check.resize(n, vector<char>(m, '.'));
    rep(i, 1, n - 1) {
        rep(j, 1, m - 1) {
            cin >> vv[i][j];
        }
    }
    // dbg(vv);
    rep(i, 1, n - 1) {
        rep(j, 1, m - 1) {
            if (Check(i, j)) {
                Mark(i, j);
            }
        }
    }
    rep(i, 1, n - 1) {
        rep(j, 1, m - 1) {
            if (check[i][j] != vv[i][j]) {
                no();
                return;
            }
        }
    }
    yes();
}
//*read stuff at the bottom

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        Solution();
    }

    cerr << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
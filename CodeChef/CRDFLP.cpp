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

void Solution() {
    ll n;
    cin >> n;
    vl a(n), b(n);
    vector<bool> mark1(n, false), mark2(n, false);
    cin >> a;
    cin >> b;
    //start with top card

    fo(i, n) {
        if (a[i] == 0 && b[i] == 0) {
            print(0, 0);
            return;
        }
    }

    bool flag1 = false;

    ll res1 = a[0];
    rep(i, 1, n) {
        ll val1 = (res1 & a[i]), val2 = (res1 & b[i]);
        if (val1 == 0 && val2 == 0) flag1 = true;
        if (val1 >= val2) {
            res1 = val1;
        } else {
            res1 = val2;
            mark1[i] = true;
        }
    }
    ll cnt1 = count(all(mark1), true);

    bool flag2 = false;
    ll res2 = b[0];
    mark2[0] = true;
    rep(i, 1, n) {
        ll val1 = (res2 & a[i]), val2 = (res2 & b[i]);
        if (val1 == 0 && val2 == 0) flag2 = true;

        if (val1 >= val2) {
            res2 = val1;
        } else {
            res2 = val2;
            mark2[i] = true;
        }
    }
    ll cnt2 = count(all(mark2), true);

    if (flag1 && flag2) {
        print(0, 0);
        return;
    }

    // print(res1, res2);
    if (res1 > res2) {
        print(res1, cnt1);
    } else if (res2 > res1) {
        print(res2, cnt2);
    } else {
        print(res1, min(cnt1, cnt2));
    }
}
//*read stuff at the bottom

void solve() {
    ll n, ans = 0, mn = 0;
    cin >> n;
    vl a(n), b(n);
    fo(i, n) cin >> a[i];
    fo(i, n) cin >> b[i];
    vl opposite(n, -1);
    for (ll i = 30; i >= 0; i--) {
        ll possi = 1;
        fo(j, n) {
            if (opposite[j] != -1) {
                if (opposite[j] == 1)
                    possi = ((possi & (b[j] >> i) & 1));
                else
                    possi = ((possi & (a[j] >> i) & 1));
                continue;
            }
            if (((a[j] >> i) & 1) || ((b[j] >> i) & 1)) {
            } else {
                possi = 0;
                break;
            }
        }
        if (!possi)
            continue;
        ll val = 1;
        fo(j, n) {
            if (opposite[j] != -1) {
                if (opposite[j] == 1)
                    val = ((val & (b[j] >> i) & 1));
                else
                    val = ((val & (a[j] >> i) & 1));
                continue;
            }

            if (((a[j] >> i) & 1) && ((b[j] >> i) & 1)) {
            } else if (((a[j] >> i) & 1))
                opposite[j] = 0;
            else if (((b[j] >> i) & 1))
                opposite[j] = 1, mn++;
            else {
                val = 0;
                break;
            }
        }
        ans += (val * (1LL << i));
    }
    print(ans, mn);
    // ll n;
    // cin >> n;
    // vl a(n), b(n);
    // cin >> a >> b;
    // bool flag = false, flag1 = false, flag2 = false;
    // ll res1 = a[0], res2 = b[0];
    // if (res1 == 0 && res2 == 0) flag = true;
    // ll cnt1 = 0, cnt2 = 1;
    // rep(i, 1, n) {
    //     ll v11 = (res1 & a[i]), v12 = (res1 & b[i]);
    //     ll v21 = (res2 & a[i]), v22 = (res2 & b[i]);
    //     if (v11 == 0 && v12 == 0) flag1 = true;
    //     if (v21 == 0 && v22 == 0) flag2 = true;

    //     if (v11 >= v12)
    //         res1 = (res1 & v11);
    //     else
    //         res1 = (res1 & v12), cnt1++;

    //     if (v21 >= v22)
    //         res2 = (res2 & v21);
    //     else
    //         res2 = (res2 & v22), cnt2++;
    // }

    // ll ans = max(res1, res2);
    // if ((flag) || (flag1 && flag2))
    //     print(0, 0);
    // else if (ans == 0)
    //     print(0, 0);
    // else if (ans == res1 && res1 == res2)
    //     print(res1, min(cnt1, cnt2));
    // else if (ans == res1)
    //     print(res1, cnt1);
    // else
    //     print(res2, cnt2);
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
        solve();
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
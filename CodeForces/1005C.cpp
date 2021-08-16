// Problem: C. Summarize to the Power of Two
// Contest: Codeforces - Codeforces Round #496 (Div. 3)
// URL: https://codeforces.com/contest/1005/problem/C
// Author: Akshat Aggarwal , @master._.mind , NIT Hamirpur
// Created at: 02/08/2021 18:49:58 (UTC +5:30)
//
// Powered by CP Editor (https://cpeditor.org)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include "bits/stdc++.h"

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

// ll next2(ll n) {
// db nxt = log2(n);
// return static_cast<ll>(pow(2, (ll)nxt + 1));
// }

void Solution() {
    ll n;
    cin >> n;
    vl a(n);
    map<ll, ll> cnt;
    fo(i, n) cin >> a[i], ++cnt[a[i]];
    // if (n == 1) {
    // print(1);
    // return;
    // } else if (n == 2) {
    // if (bitll(a[0] + a[1]) == 1)
    // cout << 0;
    // else
    // cout << 2;
    // return;
    // }
    vl two;
    ll t = 1;
    fo(i, 33) {
        two.eb(t);
        t *= 2;
    }
    // debug(two);

    vector<bool> ok(n, false);
    fo(i, n) {
        fo(j, 33) {
            ll left = two[j] - a[i];
            if (cnt.count(left)) {
                debug(a[i], left);
                if (left == a[i]) {
                    if (cnt[left] < 2)
                        continue;
                    else
                        ok[i] = true;
                } else
                    ok[i] = true;
            }
        }
    }
    ll ans = 0;
    fo(i, n) if (!ok[i]) ans++;
    print(ans);

    // sort(all(a));
    // ll ans = 0;
    // fo(i, n) {
    // ll nx = next2(a[i]);
    // if (nx == 2 * a[i]) cout << a[i] << "-";
    // if ((nx == 2 * a[i] && cnt[a[i]] < 2) || (cnt.count(nx - a[i]) == 0)) ans++;
    // }
    // cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        Solution();
    }

    cerr << clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    return 0;
}
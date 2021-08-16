//**********************master._.mind**********************
//-----------------Author: Akshat Aggarwal-----------------
//If you don't understand the code below... dont worry, i didn't either
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

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(char ch) {
    string s(1, ch);
    return '\'' + s + '\'';
}

string to_string(const char *s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "{" + to_string(p.ff) + ", " + to_string(p.ss) + "}";
}

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

class Task {
   public:
    void Perform() {
        Read();
        Solve();
    }

   private:
    str s, t;

    void Read() {
        cin >> s >> t;
    }

    void Solve() {
        string s1, s2;
        s += "{";
        t += "{";
        ll n = s.size();
        vector<ll> idx1, idx2;
        for (ll i = 0; i < n; i++) {
            if (i & 1) {
                s1 += s[i];
                idx1.push_back(i);
            } else {
                s2 += s[i];
                idx2.push_back(i);
            }
        }
        if (check(s1, s2, t, 0, idx1, idx2) or check(s1, s2, t, 1, idx1, idx2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    bool check(string &s1, string &s2, string &t, ll start, vector<ll> &idx1, vector<ll> &idx2) {
        ll n1 = s1.size();
        ll n2 = s2.size();
        ll m = t.size();
        vector<vector<ll>> pos1(27), pos2(27);
        for (ll i = 0; i < n1; i++) {
            pos1[s1[i] - 'a'].push_back(idx1[i]);
        }
        for (ll i = 0; i < n2; i++) {
            pos2[s2[i] - 'a'].push_back(idx2[i]);
        }
        ll cur = 0;
        for (ll i = 0; i < m; i++) {
            ll x = t[i] - 'a';

            if (start & 1) {
                auto xx = lower_bound(pos1[x].begin(), pos1[x].end(), cur);
                if (xx != pos1[x].end()) {
                    cur = *xx;
                } else {
                    return false;
                }
                start ^= 1;
            } else {
                auto xx = lower_bound(pos2[x].begin(), pos2[x].end(), cur);
                if (xx != pos2[x].end()) {
                    cur = *xx;
                } else {
                    return false;
                }
                start ^= 1;
            }
        }
        return true;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    auto start = chrono::high_resolution_clock::now();

    int tc = 1;
    cin >> tc;
    while (tc--) {
        Task t;
        t.Perform();
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-6;
    cerr << ps(time_taken, 6) << " ms" << ln;
    return 0;
}

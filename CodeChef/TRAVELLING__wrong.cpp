#define ll long long
#define pb push_back
#define Mod 1000000007
#define Inf 1e18

#include <bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// member functions :
// 1. order_of_key(k) : number of elements strictly lesser than k
// 2. find_by_order(k) : k-th element in the set
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
*/

/* ************************ */

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class DSU {
   private:
    vector<int> parent, size;

   public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            parent.pb(i);
            size.pb(1);
        }
    }

    int findpar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }

    void unionbysize(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv) {
            return;
        }
        // pu chota hoga to pv mein connect kr denge
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int compsize(int u) {
        return size[u];
    }
};

// FOR unordered_map<int,int,custom_hash> TO AVOID FALTU TLE'S COZ OF ANTIHASHES.
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// finding ceil for long long
ll Ceil(ll a, ll b) {
    return (a / b + ((a ^ b) > 0 && a % b));
}

// finding ncr
ll Ncr(ll n, ll r) {
    if (n < r) return 0LL;
    ll res = 1;
    for (ll j = 0; j < r; j++) {
        // ncr = n*(n-1)(n-2)../ 1*2*3*..r
        // ncr = (n-1)cr + (n-1)c(r-1)
        res = res * (n - j);
        res = res / (j + 1);
    }
    return res;
}

// check no.is a power of 2
bool Pow_Of_Two(ll n) {
    ll val = (n & (n - 1));
    if (val == 0LL) return true;
    return false;
}

// Modular fast exponentiation
ll Power_Mod(ll x, ll n) {
    ll ans = 1LL;
    while (n > 0) {
        if (n % 2LL == 1LL) {
            ans = (ans * x) % Mod;
            n--;
        } else {
            x = (x * x) % Mod;
            n /= 2LL;
        }
    }
    return ans;
}

ll Power(ll x, ll n) {
    ll ans = 1LL;
    while (n > 0) {
        if (n % 2LL == 1LL) {
            ans = (ans * x);
            n--;
        } else {
            x = (x * x);
            n /= 2LL;
        }
    }
    return ans;
}

bool Isprime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

/* ************************ */

void Solution() {
    int n, m;
    cin >> n >> m;
    vector<int> dsu(n + 1, 0);
    vector<int> par(n + 1, 0);
    for (int i = 1; i <= n; i++) par[i] = i;

    auto Find = [&](const auto &go, int u) -> int {
        if (par[u] == u) return u;
        return par[u] = go(go, par[u]);
    };

    auto Merge = [&](int u, int v) -> void {
        u = Find(Find, u);
        v = Find(Find, v);
        if (u == v) return;
        if (u > v)
            par[v] = u;
        else
            par[u] = v;
    };

    set<int> present;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        present.insert(a);
        present.insert(b);
        if (Find(Find, a) != Find(Find, b)) Merge(a, b);
    }

    vector<int> dis(n + 2, 1e7);
    dis[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (present.count(i)) {
            int v = Find(Find, i);
            dis[v] = min(dis[v], dis[i]);
            if (i + 1 <= n && Find(Find, i + 1) != Find(Find, i)) {
                dis[i + 1] = min(dis[i + 1], 1 + dis[i]);
            } else {
                dis[i + 1] = min(dis[i + 1], dis[i]);
            }
        } else {
            dis[i + 1] = min(dis[i + 1], 1 + dis[i]);
        }
    }
    cout << dis[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Test_case;
    cin >> Test_case;

    while (Test_case--) Solution();
}
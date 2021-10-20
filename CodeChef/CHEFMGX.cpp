#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

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

const int N = 10000000;
int lp[N + 1];
vector<int> pr;
void fill() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
o_set<ll> primes;

void Solution() {
    ll L, R, ans = 0;
    cin >> L >> R;
    if (L == 1) {
        if (R > 3) {
            L += 2, ans++;
        } else {
            ans++;
            return void(cout << ans << '\n');
        }
    }
    if (L == 2) {
        if (R > 3) {
            L++, ans++;
        } else {
            ans++;
            return void(cout << ans << '\n');
        }
    }
    if (*primes.lower_bound(L) == L + 1) L++, ans++;
    ll dist = R - L;
    ll cnt = primes.order_of_key(R + 1) - primes.order_of_key(L + 1);
    dbg(cnt);
    ans += cnt + (dist - 2 * cnt);
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    fill();
    for (auto &x : pr) primes.insert(x);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
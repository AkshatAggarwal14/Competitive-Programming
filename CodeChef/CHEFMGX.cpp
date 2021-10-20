#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 10000000;
int lp[N + 1];
vector<int> pr;
o_set<ll> primes;
void fill() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
            primes.insert(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void Solution() {
    ll L, R, ans = 0;
    cin >> L >> R;
    if (L < 3) L = 3, ans++;
    if (*primes.lower_bound(L) == L + 1) L++, ans++;
    ll cnt = primes.order_of_key(R + 1) - primes.order_of_key(L + 1);
    ans += cnt + ((R - L) - 2 * cnt);
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fill();
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}
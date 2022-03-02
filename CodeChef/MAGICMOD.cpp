#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// m1 * x + 1 = a1
// m2 * x + 2 = a2
// ...
// (m1 + m2 + ..) * x = SUM - n*(n+1)/2
// try x to be a factor of [SUM - n*(n+1)/2]
// also no two a_i can be same as then ai%x will be same, not a permutation

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (ll &A : a) cin >> A, ++cnt[A];
    for (auto &[x, y] : cnt)
        if (y > 1) return void(cout << "NO\n");
    ll sum = accumulate(all(a), 0LL);
    sum -= n * (n + 1) / 2;
    if (sum < 0) return void(cout << "NO\n");
    if (sum == 0) return void(cout << "YES " << ll(1e7 + 1) << '\n');
    vector<ll> facs;
    for (ll i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            if (i <= ll(2e7) && i > n)
                facs.push_back(i);
            if (i != sum / i) {
                if (sum / i <= ll(2e7) && sum / i > n)
                    facs.push_back(sum / i);
            }
        }
    }
    vector<ll> temp(n);
    for (ll &option : facs) {
        for (ll i = 0; i < n; ++i) temp[i] = a[i] % option;
        sort(all(temp));
        bool flag = true;
        for (ll i = 0; i < n; ++i)
            if (temp[i] != i + 1) flag = false;
        if (flag) return void(cout << "YES " << option << '\n');
    }
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}
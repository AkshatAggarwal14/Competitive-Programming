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

void Solution() {
    ll n, score;
    cin >> n >> score;
    ll pos = 0, neg = 0;
    if (score <= 0) {
        neg = -score;
    } else {
        pos = score / 3;
        if (score % 3) {
            ++pos;
            neg = 3 - score % 3;
        }
    }
    if (pos + neg > n) return void(cout << "NO\n");
    cout << "YES\n";
    cout << pos << ' ' << neg << ' ' << n - pos - neg << '\n';
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
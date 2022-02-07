#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

const ll N = 1'00'010;
array<ll, N + 1> lp;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int findPrimes(int n) {
    if (n == lp[n]) return 1;
    // cout << n << endl;
    if (n % 2 == 0 || (n - 2 == lp[n - 2])) return 2;  //goldbach
    // cout << 2 << " " << n - 2 << endl;
    return 3;
    // cout << 3 << " ";
    // n = n - 3;
    // for (int i = 0; i < n; i++) {
    //     if (isPrime(i) && isPrime(n - i)) {
    //         cout << i << " " << (n - i);
    //         break;
    //     }
    // }
}

void Solution() {
    int n;
    cin >> n;
    int m = *lower_bound(all(pr), n);
    int ans = INT_MAX;
    for (int i = 2; i <= m; ++i) {
        amin(ans, findPrimes(i) + abs((n - i)));
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    fill();
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}
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

void Solution() {
    ll n;
    cin >> n;
    if (n < 4) return void(cout << n + 1 << '\n');
    ll i = 2;
    while (n % i != 0) {
        if (i * i > n) return void(cout << 1 + n << '\n');
        i++;
    }
    cout << (n / i + n) << '\n';
}

//https://oeis.org/A338281
void Brute() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> P;
    for (ll i = n + 1; i <= n * n; ++i)
        if (i % n != 0) P.push_back({abs(gcd(n, i) - lcm(n, i)), i});
    if (P.empty()) return void(cout << "Empty!\n");
    sort(all(P));
    ll mini = P[0].first;
    cout << mini << ": ";
    for (ll i = 0; i < sz(P); ++i) {
        if (P[i].first == mini) {
            cout << P[i].second << ' ';
        }
    }
    cout << '\n';
}
/*
Empty!
5: 3 
11: 4 
10: 6 
29: 6 
15: 9 
55: 8 
20: 12 
33: 12 
25: 15 
*/

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    // Brute();
    return 0;
}
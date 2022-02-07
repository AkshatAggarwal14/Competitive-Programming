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

// 19, 28, 37, 46, 55, 64, 73, 82, 91, [100]<- false

void Solution() {
    ll n;
    cin >> n;
    auto sum = [](ll K) {
        ll s = 0;
        while (K) {
            s += K % 10;
            K /= 10;
        }
        return s;
    };
    ll st = 19;
    //check every 9th number
    while (true) {
        if (sum(st) == 10) n--;
        if (n == 0) return void(cout << st << '\n');
        st += 9;
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}
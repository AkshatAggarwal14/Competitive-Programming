#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

int costAP(const vector<int> &arr) {
    if (arr.size() < 3) return 0;
    int minCost = arr.size();
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            double delta = double(arr[j] - arr[i]) / double(j - i);
            int cost = 0;
            for (int k = 0; k < arr.size(); k++) {
                if (k == i) continue;
                if ((arr[k] + delta * (i - k)) != arr[i]) cost++;
            }
            if (cost < minCost) minCost = cost;
        }
    }
    return minCost;
}

void Solution() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &A : a) cin >> A;
    // make AP
    cout << costAP(a) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}
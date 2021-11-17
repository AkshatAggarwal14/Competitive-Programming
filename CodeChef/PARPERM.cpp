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

const ll N = 100010;
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

void Solution() {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "Yes\n";
        cout << "1\n";
        return;
    }
    if (k == n - 1) {
        cout << "Yes\n";
        for (ll i = 2; i <= n; ++i) cout << i << ' ';
        cout << '\n';
        return;
    }
    set<ll> left;
    for (ll i = 2; i <= n; ++i) left.insert(i);
    vector<ll> temp = {1};
    for (ll i = n / 2 + 1; i <= n; ++i) {
        if (lp[i] != i) continue;
        // if prime
        temp.push_back(i);
        left.erase(i);
        if (sz(temp) == n - k) {
            cout << "Yes\n";
            for (auto &x : left) cout << x << ' ';
            cout << '\n';
            return;
        }
        if (sz(temp) == k) {
            cout << "Yes\n";
            for (auto &x : temp) cout << x << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "No\n";
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
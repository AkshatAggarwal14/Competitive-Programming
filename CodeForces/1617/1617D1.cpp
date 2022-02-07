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

ll query(ll a, ll b, ll c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    ll res;
    cin >> res;
    if (res == -1) exit(0);
    return res ^ 1;  // 1 -> impostor
}

void Solution() {
    ll n;
    cin >> n;
    ll impostor = -1, crewmate = -1, prev = -1, now = -1;
    for (ll i = 1; i <= n - 2; ++i) {
        now = query(i, i + 1, i + 2);
        if (i == 1) {
            prev = now;
            continue;
        }
        if (prev == 1 && now == 0) {  // ICIC, IICC
            impostor = i - 1;
            crewmate = i + 2;
            break;
        } else if (prev == 0 && now == 1) {  // CICI, CCII
            crewmate = i - 1;
            impostor = i + 2;
            break;
        }
        prev = now;
    }
    vector<ll> ans;
    ans.push_back(impostor);
    for (ll i = 1; i <= n; ++i) {
        if (i == crewmate || i == impostor) continue;
        if (query(impostor, crewmate, i)) ans.push_back(i);
    }
    cout << "! " << sz(ans) << ' ';
    for (ll &x : ans) cout << x << ' ';
    cout << endl;
}

int main() {
    ll tc;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}
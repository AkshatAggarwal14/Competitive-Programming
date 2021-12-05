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

using pl = pair<ll, ll>;

struct cmp {
    bool operator()(const pl &a, const pl &b) {
        ll len1 = a.second - a.first + 1, len2 = b.second - b.first + 1;
        if (len1 == len2) return a.first > b.first;
        return len1 < len2;
    }
};

void Solution() {
    ll n, ctr = 0;
    cin >> n;
    priority_queue<pl, vector<pl>, cmp> pq;
    pq.push({1, n});
    vector<ll> ans(n + 1, 0);
    auto getID = [&](pl A) {
        ll len = A.second - A.first + 1;
        if (len & 1) return ((A.first + A.second) / 2);
        return ((A.first + A.second - 1) / 2);
    };
    while (!pq.empty()) {
        pl st = pq.top();
        pq.pop();
        ll i = getID(st);
        ans[i] = ++ctr;
        if (st.first <= i - 1) pq.emplace(st.first, i - 1);
        if (i + 1 <= st.second) pq.emplace(i + 1, st.second);
    }
    for (ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}

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
    return 0;
}
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
    ll n;
    cin >> n;   
    ll num;
    ll len = 0;
    stack<pair<ll, ll>> st;
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        if (st.empty() || st.top().first != num) {
            st.push({num, 1});
            ++len;
        } else {
            st.top().second++;
            len++;
            if (st.top().first == st.top().second) {
                len -= st.top().second;
                st.pop();
            }
        }
        cout << len << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}
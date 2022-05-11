#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

mt19937 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string randomString(ll length) {
    string res = "";
    for (ll i = 0; i < length; ++i) {
        ll choice = uid(0, int(alphabet.length()) - 1);
        res += alphabet[choice];
    }
    return res;
}

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> eo(2);
    for (ll &A : a) cin >> A, eo[A % 2].push_back(A);
    sort(all(eo[0]));
    sort(all(eo[1]));

    vector<ll> ans;
    // vector<array<ll, 2>> ans;
    auto simulate = [&](vector<vector<ll>> V, ll turn1, ll turn2) {
        ll alice = 0, bob = 0;
        ll turn = 0;
        while (!V[0].empty() || !V[1].empty()) {
            if (turn % 2 == 0) {
                if (sz(V[turn1])) {
                    alice += V[turn1].back();
                    V[turn1].pop_back();
                }
                turn1 ^= 1;
            } else {
                if (sz(V[turn2])) {
                    bob += V[turn2].back();
                    V[turn2].pop_back();
                }
                turn2 ^= 1;
            }
            turn ^= 1;
        }
        // if (alice >= bob) ans.push_back({alice, bob});
        if (alice >= bob) ans.push_back(alice);
    };
    simulate(eo, 0, 0);
    simulate(eo, 0, 1);
    simulate(eo, 1, 0);
    simulate(eo, 1, 1);
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    dbg(ans);
    ll id = uid(0, sz(ans) - 1);
    cout << ans[id] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}

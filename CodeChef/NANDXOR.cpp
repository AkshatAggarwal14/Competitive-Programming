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

void Solution() {
    // take 4 random indexes
    // xD how did this pass 18 test cases
    ll n;
    cin >> n;
    vector<ll> a(n);

    auto check = [&](ll i1, ll i2, ll i3, ll i4) {
        if (__builtin_popcountll(uint64_t(a[i1] ^ a[i2])) ==
            __builtin_popcountll(uint64_t(a[i3] ^ a[i4]))) {
            cout << i1 + 1 << ' ' << i2 + 1 << ' ' << i3 + 1 << ' ' << i4 + 1 << '\n';
            return true;
        }
        return false;
    };

    // 200 * n because O(200 * n) is in time limit
    for (ll &A : a) cin >> A;
    for (ll _ = 0; _ <= 200 * n; ++_) {
        ll i1 = uid(0, n - 4);
        ll i2 = uid(i1 + 1, n - 3);
        ll i3 = uid(i2 + 1, n - 2);
        ll i4 = uid(i3 + 1, n - 1);
        if (check(i1, i2, i3, i4)) return;
        if (check(i1, i3, i2, i4)) return;
        if (check(i1, i4, i2, i3)) return;
    }
    cout << "-1\n";
}

/*
    ! this works because there are only 30 bits thus, popcount repeats in 31 pairs
    thus O(64^4) atmost
*/
void PEGION_HOLE() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;

    auto check = [&](ll i1, ll i2, ll i3, ll i4) {
        if (__builtin_popcountll(uint64_t(a[i1] ^ a[i2])) ==
            __builtin_popcountll(uint64_t(a[i3] ^ a[i4]))) {
            cout << i1 + 1 << ' ' << i2 + 1 << ' ' << i3 + 1 << ' ' << i4 + 1 << '\n';
            return true;
        }
        return false;
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (check(i, j, k, l)) return;
                    if (check(i, k, j, l)) return;
                    if (check(i, l, j, k)) return;
                }
            }
        }
    }

    cout << "-1\n";
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
        // Solution();
        PEGION_HOLE();
    }
    return 0;
}
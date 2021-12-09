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

const ll N = 1000000;
array<ll, N + 1> spf;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

// make pair with count of contiguous..
vector<pair<ll, ll>> compress(const vector<ll> &t) {
    if (t.empty()) return {};
    vector<pair<ll, ll>> res;
    ll cnt = 0, last = t[0];
    for (ll i = 0; i < sz(t); ++i) {
        if (t[i] == last) {
            cnt++;
        } else {
            res.push_back({last, cnt});
            last = t[i], cnt = 1;
        }
    }
    if (cnt) res.push_back({last, cnt});
    return res;
}

// Returns a vector containing all the prime factors of n (25 --> 5, 5)
vector<ll> prime_factorisation(ll n) {
    vector<ll> ans;
    while (n != 1) {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}

// if N = p1^a*p2^b*.., Num of divisors = (a+1)(b+1)..
ll count_divisors(ll n) {
    if (n <= 2) return n;
    vector<pair<ll, ll>> compressed = compress(prime_factorisation(n));
    ll res = 1;
    for (auto &[x, y] : compressed) res *= (y + 1);
    return res;
}
// if N = p1^a*p2^b..
// Sum of divisors = (p1^0 + p1^1 + .. p1^a)*()... -> GP

void Solution() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) ans += count_divisors(i);
    cout << ans << '\n';
}

//---------------------------------------------------------------------------------
void Better1() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) ans += n / i;
    cout << ans << '\n';
    /*This works because there are N/2 multiples of 2 in [1, N] thus there are N/2 numbers whose divisor is 2, and so on..*/
}

// now task of finding sum n/i can also be done in sqrt n
void Better2() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i <= n; ++i) ans += (n / i - i + 1LL) * 2LL - 1LL;
    cout << ans << '\n';
}
// - i to avoid overcounting lower values
// + 1 to allowe squares
// x 2 so that what goes around can come around
// - 1 for the square

// clang-format off
int main() {
    fill();
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    // Solution();
    // Better1();
    Better2();
    return 0;
}
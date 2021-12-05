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

const ll N = 2'00'000;
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

// Returns a vector containing all the prime factors of n (25 --> 5, 5)
vector<ll> prime_factorisation(ll n) {
    vector<ll> ans;
    while (n != 1) {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}

void Solution() {
    // palindrome after minimum period
    // if even then 2 or 4
    // if odd then minimum odd prime divisor
    ll n;
    cin >> n;
    if (n == 2) return void(cout << "ab\n");  // 0
    if (n % 4 == 0) {
        string s = "abba";                         // 2
        for (ll i = 0; i < n / 4; ++i) cout << s;  // 2*(n/4) -> every 2 steps we get a palindrome
        return void(cout << '\n');
    }
    vector<ll> fac = prime_factorisation(n);
    for (ll &x : fac) {
        if (x & 1) {
            string s = "";
            for (ll i = 0; i < x; ++i) s += ((i & 1) ? 'a' : 'b');
            for (ll i = 0; i < (n / x); ++i) cout << s;  // every n/x steps
            return void(cout << '\n');
        }
    }
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
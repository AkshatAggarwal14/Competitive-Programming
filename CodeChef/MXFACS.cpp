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

const ll MAXN = 1e9;
const ll N = ll(sqrt(MAXN)) + 10;
vector<ll> spf(N + 1);
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) spf[i] = i, pr.push_back(i);
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

vector<pair<ll, ll>> factorise_pair(const ll &n) {
    vector<pair<ll, ll>> C;
    ll temp = n, cnt = 0;
    // if element is greater than current prime then break
    for (ll i = 0; i < sz(pr); ++i) {
        cnt = 0;
        if (temp < pr[i]) break;
        while (temp % pr[i] == 0) {
            cnt++;
            temp /= pr[i];
        }
        if (cnt) C.push_back({pr[i], cnt});
    }
    if (temp > 1) C.push_back({temp, 1});
    return C;
}

// as sieve can run upto 1e7 easily in 1 sec, we can factorise upto 1e14
vector<ll> factorise(const ll &n) {
    vector<ll> res;
    ll temp = n;
    // if element is greater than current prime then break
    for (ll i = 0; i < sz(pr); ++i) {
        if (temp < pr[i]) break;
        while (temp % pr[i] == 0) {
            res.push_back(pr[i]);
            temp /= pr[i];
        }
    }
    if (temp > 1) res.push_back(temp);
    return res;
}

/*
n = (p1 ** a1) * (p2 ** a2) ..
count_of_divisors = (a1 + 1) * (a2 + 1)..
sum_of_divisors = (1 + p1 + p1^2 + p1^3.. ) * ( ... ) ...
                = (p1^(a1 + 1) - 1)/(p1 - 1) ...
*/

ll count_of_divisors(const ll &n) {
    vector<pair<ll, ll>> C = factorise_pair(n);
    ll P = 1;
    for (auto &[x, y] : C) P *= (y + 1);
    return P;
}

ll sum_of_divisors(const ll &n) {
    vector<pair<ll, ll>> C = factorise_pair(n);
    ll P = 1;
    for (auto &[x, y] : C) {
        ll t = 1, cnt = y + 1;
        while (cnt--) t *= x;
        P *= ((t - 1) / (x - 1));
    }
    return P;
}

/*
Generate all primes <= sqrt(MAXN) using sieve
now using vector pr factorise the number and compress the result
now check all

(P/(y+1))*y gives count of divisors if we remove 1 x.
*/

void Solution() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> C = factorise_pair(n);
    ll P = count_of_divisors(n);
    ll maxi = 1, ans = n;
    for (auto &[x, y] : C)
        if (amax(maxi, (P / (y + 1)) * y)) ans = x;
    cout << ans << '\n';
}

int main() {
    fill();
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
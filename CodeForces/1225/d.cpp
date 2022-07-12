#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;

using ll = long long;
constexpr int N = 1e5;
// constexpr int N = 24;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &A : a) cin >> A;
    array<int, N + 1> spf;
    for (int i = 0; i <= N; ++i) spf[i] = -1;
    for (int i = 2; i <= N; ++i) {
        if (spf[i] != -1) continue;
        for (int j = i; j <= N; j += i) spf[j] = i;
    }
    auto get_prime_fac = [&](int num) {
        vector<pair<int, int>> res;
        while (num != 1) {
            int pr = spf[num], cnt = 0;
            while (num % pr == 0) {
                ++cnt;
                num /= pr;
            }
            cnt %= k;
            if (cnt) res.emplace_back(pr, cnt);
        }
        return res;
    };
    ll ans = 0;
    map<vector<pair<int, int>>, ll> cnt;
    for (int i = 0; i < n; ++i) {
        auto get = get_prime_fac(a[i]);
        ans += cnt[get];
        for (auto &[p, e] : get) e = k - e;
        ++cnt[get];
    }
    cout << ans << '\n';
}
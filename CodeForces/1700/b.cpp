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

string subtract(string str1, string str2) {
    string str = "";
    int n1 = int(str1.length()), n2 = int(str2.length());
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;
        str.push_back(char(sub + '0'));
    }
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else
            carry = 0;
        str.push_back(char(sub + '0'));
    }
    while (!str.empty() && str.back() == '0')
        str.pop_back();
    reverse(all(str));
    return str;
}

void test() {
    ll n;
    string s;
    cin >> n >> s;
    if (s[0] != '9') {
        for (auto &c : s) cout << char('9' - c + '0');
        cout << "\n";
        return;
    } else {
        string ans = subtract(string(n + 1, '1'), s);
        assert(sz(ans) == sz(s));
        cout << ans << '\n';
    }
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

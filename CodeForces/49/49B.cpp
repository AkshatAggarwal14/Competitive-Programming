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

string sumBaseB(string a, string b, ll base) {
    ll len_a = sz(a), len_b = sz(b);
    string sum, s;
    s = "";
    sum = "";
    ll diff = abs(len_a - len_b);
    for (ll i = 1; i <= diff; i++) s += "0";
    if (len_a < len_b)
        a = s + a;
    else
        b = s + b;
    ll curr, carry = 0;
    for (ll i = max(len_a, len_b) - 1; i > -1; i--) {
        curr = carry + (a[i] - '0') + (b[i] - '0');
        carry = curr / base;
        curr = curr % base;
        sum = (char)(curr + '0') + sum;
    }
    if (carry > 0)
        sum = (char)(carry + '0') + sum;
    return sum;
}

void test() {
    ll a, b;
    cin >> a >> b;
    string A = to_string(a), B = to_string(b);
    ll maxi = max(*max_element(all(A)), *max_element(all(B))) - '0';
    cout << sz(sumBaseB(A, B, maxi + 1)) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    std::cout.rdbuf(cout.rdbuf()), std::cin.rdbuf(cin.rdbuf());
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}

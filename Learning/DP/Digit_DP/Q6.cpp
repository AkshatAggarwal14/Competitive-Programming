// https://www.codechef.com/problems/ENCODING

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int pow10(int n) {
    int ans = 1;
    while (n--) ans *= 10;
    return ans;
}

int F(string &L) {
    int prev = 10;
    ll res = 0;
    ll n = ll(L.size());
    for (ll i = 0; i < n; ++i) {
        res += ((L[i] - '0') * pow10(n - i - 1)) % MOD;
        prev = int(L[i] - '0');
    }
    return res % MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // as we are given input in form of strings
    // Ans[L, R] =  Ans[0, R] - Ans[0, L - 1] = Ans[0, R] - Ans[0, L] + F(L)

    /**
     * Now to find Ans[0, R] ->
     *
     */
}
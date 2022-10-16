// https://www.spoj.com/problems/SUBSUMS/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> subsetsums(vector<ll> a) {
    ll n = ll(a.size());
    vector<ll> result;
    for (ll i = 0; i < (1 << n); i++) {
        ll sum = 0;
        for (ll j = 0; j < n; j++) {
            if ((i >> j) & 1) sum += a[j];
        }
        result.push_back(sum);
    }
    return result;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];
    vector<ll> left, right;
    for (ll i = 0; i < n; i++) {
        if (i <= n / 2)
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }
    vector<ll> left_sums = subsetsums(left);
    vector<ll> right_sums = subsetsums(right);
    sort(right_sums.begin(), right_sums.end());
    ll ans = 0;
    // iterate on left, binary search on right
    // reduced to sum pair problem.

    // to find count of all subsets with sum in range [a, b]
    // for some y in x, we need x + y = k, y = k - x
    // for x + y >= a && x + y <= b, y >= a - x, y <= b - x
    for (auto &x : left_sums) {
        ans += upper_bound(right_sums.begin(), right_sums.end(), b - x) -
               lower_bound(right_sums.begin(), right_sums.end(), a - x);
    }
    cout << ans;
}
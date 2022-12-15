#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    function<void(ll, ll, ll, ll)> hanoi = [&](ll i, ll from, ll to, ll helper) {
        if (i == 0) return;
        hanoi(i - 1, from, helper, to);
        cout << from << ' ' << to << '\n';
        hanoi(i - 1, helper, to, from);
    };
    hanoi(n, 1, 3, 2);
}
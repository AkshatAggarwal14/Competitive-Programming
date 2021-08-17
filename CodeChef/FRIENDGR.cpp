#include "bits/stdc++.h"
using namespace std;
#define ll long long

void Solution() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll ans = 0;
    vector<ll> pos;
    for (ll i = 0; i < n; ++i)
        if (s[i] == '1') pos.emplace_back(i + 1);
    // dbg(pos);
    ll N = pos.size();
    if (N) {
        ans++;
        pos[0]++;
    }
    for (ll i = 1; i < N; ++i) {
        if (abs(pos[i] - pos[i - 1]) < k)
            pos[i]++;
        else if (abs(pos[i] - pos[i - 1]) == k)
            continue;
        else if (pos[i] - pos[i - 1] == k + 1)
            pos[i]--;
        else {
            ans++;
            pos[i]++;
        }
    }
    // dbg(pos);
    cout << ans << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)

ll n, k, l;

void solve() {
    cin >> n >> k;
    vector<string> arr(n);
    fo(i, n) cin >> arr[i];
    unordered_map<string, ll> mp;
    string s;
    while (k--) {
        cin >> l;
        while (l--) {
            cin >> s;
            mp[s]++;
        }
    }
    fo(i, n) cout << ((mp[arr[i]]) ? "YES " : "NO ");

    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}

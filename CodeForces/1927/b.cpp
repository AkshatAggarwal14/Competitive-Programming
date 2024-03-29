#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define fo(i, n) for (i = 0; i < n; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define m_p make_pair
const ll mod = 1e9 + 7;
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll i;
    fo(i, n)
            cin >>
        arr[i];
    map<ll, set<char>> mpp;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        mpp[0].insert(ch);
    }
    string ans;
    fo(i, n) {
        char ch = *(mpp[arr[i]].begin());
        mpp[arr[i]].erase(mpp[arr[i]].find(ch));
        ans.pb(ch);
        mpp[arr[i] + 1].insert(ch);
    }
    cout << ans << "\n";
}
//---------------------------------------------------------------------------------------------
int main() {
    // BINARY SEARCH ON ANS
    // DISJOINT SET UNION
    // INVERSE MODULO
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    // t=1;
    while (t--) {
        solve();
    }
}
//---------------------------------------------------------------------------------------------```
// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

using node = pair<string, pair<ll, ll>>;
#define s first
#define cnt second.first
#define id second.second

ll win(char c1, char c2) {
    if (c1 == c2) return 0;
    if ((c1 == 'G' && c2 == 'C') || (c1 == 'C' && c2 == 'P') || (c1 == 'P' && c2 == 'G')) return 1;
    swap(c1, c2);
    if ((c1 == 'G' && c2 == 'C') || (c1 == 'C' && c2 == 'P') || (c1 == 'P' && c2 == 'G')) return 2;
    return 0;  // never reached
}

bool cmp(node& A, node& B) {
    if (A.cnt == B.cnt) return A.id < B.id;
    return A.cnt > B.cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<node> vv(2 * n);
    for (ll i = 0; i < 2 * n; ++i) {
        cin >> vv[i].s;
        vv[i].id = i + 1;
        vv[i].cnt = 0;
    }
    for (ll i = 0; i < m; ++i) {
        // each round
        sort(vv.begin(), vv.end(), cmp);  //custom sort before every round
        for (ll j = 0; j < 2 * n; j += 2) {
            ll winner = win(vv[j].s[i], vv[j + 1].s[i]);
            if (winner) vv[j - 1 + winner].cnt++;  // 1 -> vv[j], 2 -> vv[j+1]
        }
    }
    sort(vv.begin(), vv.end(), cmp);
    for (ll i = 0; i < 2 * n; ++i) cout << vv[i].second.second << '\n';

    return 0;
}
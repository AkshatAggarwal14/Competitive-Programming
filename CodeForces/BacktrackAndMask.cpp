#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

vector<vector<int>> ans;
void backtrack(vector<int> a, int sum) {
    if (sum == 0) {
        ans.push_back(a);
        return;
    }
    for (int ele = 1; ele <= sum; ++ele) {
        a.push_back(ele);
        backtrack(a, sum - ele);
        a.pop_back();
    }
}
void backtrack() {
    string s;
    cin >> s;
    int n = int(s.length());
    backtrack(vector<int>{}, n);
    dbg(ans);
    for (auto &option : ans) {
        ll j = 0, i = 0;
        string str = "";
        while (j < n) {
            while (option[i] > 0) {
                str += s[j];
                option[i] -= 1, j++;
            }
            str += ' ';
            i++;
        }
        str.pop_back();  // to remove extra space
        cout << str << '\n';
    }
}

void masking() {
    ll n;
    cin >> n;
    for (ll mask = 0; mask < (1LL << n); mask++) {
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
            }
        }
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    backtrack();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
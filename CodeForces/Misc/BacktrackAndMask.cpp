#include "Akshat.hpp"
using ll = int64_t;

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
    set<vector<ll>> res;
    for (ll mask = 0; mask < (1LL << n); mask++) {
        ll cnt = 0;
        vector<ll> temp;
        for (ll i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
                if (cnt) temp.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        if (cnt) temp.push_back(cnt);
        res.insert(temp);
    }
    dbg(res);
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    backtrack();
    return 0;
}
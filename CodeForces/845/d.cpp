#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // speed and overtake violations are independent
    int n;
    cin >> n;
    int violations = 0;
    int no_overtakes = 0;
    vector<int> limits;
    int type, x, curr;
    for (int i = 0; i < n; ++i) {
        cin >> type;
        switch (type) {
            case 1:
                cin >> x;
                curr = x;
                // remove prev larger limits
                while (!limits.empty() && limits.back() < curr)
                    limits.pop_back(), ++violations;
                break;
            case 2:
                // just overtook, so remove previous no overtakes
                violations += no_overtakes;
                no_overtakes = 0;
                break;
            case 3:
                // add to speed limits
                cin >> x;
                limits.push_back(x);
                break;
            case 4:
                // as can freely overtake now, clear no overtakes
                no_overtakes = 0;
                break;
            case 5:
                // as no limit anymore, remove all previous limits
                limits.clear();
                break;
            case 6:
                ++no_overtakes;
                break;
        }
        // new limits added and thus can effect if "curr" speed can be achieved
        while (!limits.empty() && limits.back() < curr)
            limits.pop_back(), ++violations;
    }
    cout << violations << '\n';
}
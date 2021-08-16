//**********************master._.mind**********************
//-----------------Author: Akshat Aggarwal-----------------
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string base, need;
    getline(cin, base);
    getline(cin, need);
    map<char, ll> counts;
    for (char c : base) {
        if (isalpha(c)) {
            counts[c] += 1;
        }
    }
    bool ok = true;
    for (char c : need) {
        if (isalpha(c)) {
            auto it = counts.find(c);
            if (it == counts.end()) {
                ok = false;
                break;
            }
            if (it->second == 1) {
                counts.erase(it);
            } else {
                it->second -= 1;
            }
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    // freopen("input.txt", "r", stdin);
    // string s1, s2;
    // getline(cin, s1);
    // getline(cin, s2);
    // ll count1[58] = {}, count2[58] = {};  // count a,b,c,...z, A,B,C,...Z
    // for (ll i = 0; i < s1.length(); i++)
    //     if (s1[i] != ' ')
    //         count1[s1[i] - 65]++;

    // for (ll i = 0; i < s2.length(); i++)
    //     if (s2[i] != ' ')
    //         count2[s2[i] - 65]++;

    // // for (ll i = 0; i < 58; i++) {
    // //     cout << (char)(i + 65) << ": " << count1[i] << ", " << count2[i] << "\n";
    // // }

    // for (ll i = 0; i < 58; i++) {
    //     if (count1[i] < count2[i]) {
    //         cout << "NO\n";
    //         return 0;
    //     }
    // }

    // cout << "YES\n";

    return 0;
}  //todo main

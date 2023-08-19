#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// https://www.youtube.com/watch?v=06QIlUBLTz4 and https://cp-algorithms.com/string/manacher.html
// TC: O(n)
vector<int> manacher(const string &s) {
    if (s.empty()) return {};

    string t = "@";
    for (auto &ch : s) {
        t += '#';
        t += ch;
    }
    t += "#$";

    int n = int(t.size());
    vector<int> p(n, 0);
    int mirror_index = 0, right_border = 0;
    for (int i = 1; i <= n - 2; ++i) {
        int opposite_index = mirror_index - (i - mirror_index);

        // kickstart but cannot go past right border
        if (i < right_border)
            p[i] = min(p[opposite_index], right_border - i);

        while (t[i + p[i] + 1] == t[i - p[i] - 1])
            ++p[i];

        if (i + p[i] > right_border) {
            // update border and mirror
            mirror_index = i;
            right_border = i + p[i];
        }
    }

    return vector<int>(begin(p) + 2, end(p) - 2);
}

int main() {
    string s;
    cin >> s;
    auto lps = manacher(s);
    int id = int(distance(lps.begin(), max_element(lps.begin(), lps.end())));
    int start = (id + 1) / 2 - lps[id] / 2;

    cout << s.substr(start, lps[id]) << '\n';
}
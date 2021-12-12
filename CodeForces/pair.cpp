#include <bits/stdc++.h>
using namespace std;

int main() {
    // A pair container -> 2 data elements -> 2 units in 1 single entity/container
    // To access the elements, we use variable name followed by dot operator followed by the keyword first or second.

    pair<int, double> p1(1, 0.5), p2;
    p2 = make_pair(1, 0.4);  // p2 = {1, 0.4}
    cout << p2.first << ' ' << p2.second;

    // mostly used like vector of pairs
    vector<pair<int, int>> v;
    return 0;
}
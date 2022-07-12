#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n), pos(n);
    int x = 0;
    for (int &P : p) cin >> P, --P, pos[P] = x++;
    
    cout << '\n';
}
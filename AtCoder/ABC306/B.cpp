#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long ans = 0, a = 0, t = 1;
    for (int i = 0; i < 64; ++i) {
        cin >> a;
        ans += t * a;
        t *= 2;
    }
    cout << ans << '\n';
}
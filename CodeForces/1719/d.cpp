#include <bits/stdc++.h>
using namespace std;

#include <Akshat.hpp>

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int j = 0;
    while (j < n) {
        if (a[j] < 1 || a[j] > n) {
            j++;
            continue;
        } else {
            swap(a[j], a[a[j] - 1]);
            if (a[j] == (j + 1)) {
                j++;
            }
        }
        dbg(a);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != (i + 1)) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}
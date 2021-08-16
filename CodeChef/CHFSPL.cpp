#include "bits/stdc++.h"
using namespace std;
#define ll long long

void Solution() {
    ll arr[3];
    for (ll i = 0; i < 3; ++i) cin >> arr[i];
    sort(arr, arr + 3);
    cout << arr[2] + arr[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}
#include "bits/stdc++.h"
using namespace std;

int bulbSwitch(int n) {
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * i <= n; j++)
            arr[i * j]++;
    }
    for (int i = 1; i <= n; i++) arr[i] %= 2;
    int ans = accumulate(arr.begin(), arr.end(), 0);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << bulbSwitch(n);
}
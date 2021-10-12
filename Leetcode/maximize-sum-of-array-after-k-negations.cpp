#include <bits/stdc++.h>

#include <Akshat.hpp>
using namespace std;

int largestSumAfterKNegations(vector<int>& v, int k) {
    sort(v.begin(), v.end());
    int n = v.size();
    for (int i = 0; i < n && k > 0 && v[i] < 0; ++i) {
        v[i] *= -1;
        k--;
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    if (k == 0) return sum;
    if (k % 2) {
        sort(v.begin(), v.end());
        return sum - 2 * v[0];
    } else
        return sum;
}

int main() {
    vector<int> a = {2, -3, -1, 5, -4};
    int k = 2;
    cout << largestSumAfterKNegations(a, k);
    return 0;
}
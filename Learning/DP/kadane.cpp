#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // local_max[i] = maximum sum from all subarrays ending at i
    // local_max[i] = max(a[i], a[i] + local_max[i - 1]);
    // local_max[i] = a[i] + max(0, local_max[i - 1]);
    int max_ending_here = 0;
    int max_so_far = 0;
    int _start = 0;
    int start = 0;
    int end = -1;
    for (int i = 0; i < int(a.size()); i++) {
        max_ending_here += a[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;  // break segment
            _start = i + 1;       // start at next index
        }
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            start = _start;
            end = i;
        }
    }
    cout << start << ' ' << end << ' ' << max_so_far << '\n';
}
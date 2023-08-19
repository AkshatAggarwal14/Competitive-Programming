#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    deque<int> dq;

    auto insert = [&dq](int new_element) {
        while (!dq.empty() && dq.back() < new_element)
            dq.pop_back();
        dq.push_back(new_element);
    };

    auto remove = [&dq](int remove_element) {
        if (!dq.empty() && dq.front() == remove_element)
            dq.pop_front();
    };

    while (q--) {
        int k;
        cin >> k;
        dq.clear();
        for (int i = 0; i < k; ++i) {
            insert(arr[i]);
        }
        int ans = dq.front();
        for (int i = k; i < n; ++i) {
            insert(arr[i]);
            remove(arr[i - k]);
            ans = min(ans, dq.front());
        }
        cout << ans << '\n';
    }
}
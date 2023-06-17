#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // maintain 2 multisets - 1 of top k elements, 1 of leftover n-k elements
    // this should perform three functions, add, erase and balance
    int n, k, q;
    cin >> n >> k >> q;

    multiset<int> left, right;
    vector<int> vals(n);
    vector<string> res;
    long long int rsum = 0;

    for (int i = 0; i < n - k; ++i)
        left.insert(0);

    for (int i = 0; i < k; ++i)
        right.insert(0);

    for (int i = 0; i < q; ++i) {
        int index, value;
        cin >> index >> value, --index;
        int oldval = vals[index];
        vals[index] = value;

        int rightMin = right.empty() ? INT_MAX : *right.begin();

        if (oldval < rightMin) {
            left.erase(left.lower_bound(oldval));
        } else if (oldval >= rightMin) {
            right.erase(right.lower_bound(oldval));
            rsum -= oldval;
        }

        if (vals[index] < rightMin) {
            left.insert(vals[index]);
        } else if (vals[index] >= rightMin) {
            right.insert(vals[index]);
            rsum += vals[index];
        }

        while (left.size() > size_t(n - k)) {
            int l = *left.rbegin();
            left.erase(left.lower_bound(l));
            right.insert(l);
            rsum += l;
        }

        while (right.size() > size_t(k)) {
            int r = *right.begin();
            right.erase(right.lower_bound(r));
            rsum -= r;
            left.insert(r);
        }

        cout << rsum << "\n";
    }
}
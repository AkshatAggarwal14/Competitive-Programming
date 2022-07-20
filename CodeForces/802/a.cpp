#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;
using ll = long long;

constexpr int INF = 1000;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &A : a) cin >> A;
    // Optimal Page replacement algorithm
    set<int> have;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (have.count(a[i])) continue;
        if (int(have.size()) == k) {
            // have to delete
            int max_far = -1, book_id = -1;
            for (auto &book : have) {
                int id = -1, far = INF;
                for (int j = i + 1; j < n; ++j) {
                    if (a[j] == book) {
                        id = j;
                        far = j - i;
                        break;
                    }
                }
                // take farthest one out or the one that has no future occurence
                if (far > max_far) max_far = far, book_id = a[id];
                if (id == -1) {
                    book_id = book;
                    break;
                }
            }
            have.erase(book_id);
        }
        assert(int(have.size()) < k);
        have.insert(a[i]);
        ++ans;
    }
    cout << ans << '\n';
}
#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> int { return int(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

bool isPalindrome(vector<int> v) {
    for (int i = 0; i < sz(v); ++i)
        if (v[i] != v[sz(v) - 1 - i]) return false;
    return true;
}

void Solution() {
    int n;
    cin >> n;
    vector<int> a(n), others;
    for (int &x : a) cin >> x;
    bool flag = true;
    // deleting 1st or last unequal element for palindrome
    int st = 0, en = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[n - 1 - i]) {
            st = a[i], en = a[n - 1 - i];
            flag = false;
            break;
        }
    }
    if (flag) return void(cout << "YES\n");
    // delete all occurences
    for (int i = 0; i < n; i++)
        if (a[i] != st) others.push_back(a[i]);
    if (isPalindrome(others)) return void(cout << "YES\n");
    others.clear();
    for (int i = 0; i < n; i++)
        if (a[i] != en) others.push_back(a[i]);
    if (isPalindrome(others)) return void(cout << "YES\n");
    others.clear();
    cout << "NO\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}
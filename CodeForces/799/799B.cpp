#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include "bits/stdc++.h"
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
#define sz(x) ((int)(x).size())
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

void Solution() {
    int n;
    cin >> n;
    vi p(n), a(n), b(n);
    map<pi, set<int>> S;
    fo(i, n) cin >> p[i];
    fo(i, n) cin >> a[i];
    fo(i, n) cin >> b[i];
    fo(i, n) {
        S[{a[i], b[i]}].insert(p[i]);
    }
    int m;
    cin >> m;
    fo(i, m) {
        int temp;
        cin >> temp;
        pi P = {-1, -1};
        int mini = INT_MAX;
        //! these are only possibilities
        vpi T = {{1, temp}, {2, temp}, {3, temp}, {temp, 1}, {temp, 2}, {temp, 3}};
        for (pi pr : T) {
            if (S.count(pr)) {
                if (sz(S[pr]) != 0) {
                    int val = *S[pr].begin();
                    if (val < mini) {
                        mini = val;
                        P = pr;
                    }
                }
            }
        }
        if (P == make_pair(-1, -1))
            cout << -1 << " ";
        else {
            cout << mini << " ";
            S[P].erase(mini);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    Solution();
    cerr << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

/*
    ? Stuff to look for ->
    * stay organised
    * int overflows, array bounds, etc.
    * special cases (n=1)?
    * do something instead of nothing
    * modulo of negative numbers is not a%b, it is a%b + abs(b)
    * When using a set, lower_bound(all(set),l) is slower than set.lower_bound(l) because of random iterators
    * string .append() or += is O1, but s = s + s is On (as it creates a copy first), use wisely
    * DONT GET STUCK ON ONE APPROACH
    * use __lg(n) instead of log2(n), int: 32 - __builtin_clz(n), ll: 63 - __builtin_clzll(n), https://codeforces.com/blog/entry/45966
    * string.rfind() finds first occurence from end
    * (a & b) + (a | b) = a + b
*/
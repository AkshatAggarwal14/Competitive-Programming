/*
    Given 2 strings A and B, find if B is an anagram (scrambled string) of A.
    A: "great"
    B: "rgeat"

    ? Solve using dividing A into Binary tree without empty child, and then swapping childs of non leaf nodes [zero or more swaps]
    TODO: can also solve in nlogn by sorting and comparing
    great -> gr -> g
                -> r
          -> eat -> e
                 -> at -> a
                       -> t

    allowed breaks:
    [g|reat, gr|eat, gre|at, grea|t], [i, j] = [1, n - 1]

    ? 2 cases: either we can swap, OR not swap
    gr|eat <-> eat|gr
    todo: here k = 2,
    ? check if(solve(a.substr(0, 2), b.substr(n - 2, 2)) && solve(a.substr(n - 2, 2), b.substr(0, 2)))
    ! check A's left with B's right recursively -> subproblem
    ! check A's right with B's left recursively -> subproblem
    gr|eat <-> gr|eat
    todo: here k = 2,
    ? check if(solve(a.substr(0, 2), b.substr(0, 2)) && solve(a.substr(n - 2, 2), b.substr(n - 2, 2)))
    ! check left with left and right with right
*/

#include "Akshat.hpp"
const int INF = INT_MAX;

int32_t main() {
    string a, b;
    cin >> a >> b;
    // TODO: memoize using unordered_set<string> st; st.insert(A + " " + B);
    function<bool(string, string)> check = [&](string A, string B) {
        dbg(A, B);
        if (A.size() != B.size()) return false;
        if (A == B) return true;
        int n = int(A.size());
        for (int k = 1; k <= n - 1; ++k) {
            bool condition1 =
                (check(A.substr(0, k), B.substr(n - k, k)) && check(A.substr(k, n - k), B.substr(0, n - k)));
            if (condition1) return true;
            bool condition2 =
                (check(A.substr(0, k), B.substr(0, k)) && check(A.substr(k, n - k), B.substr(k, n - k)));
            if (condition2) return true;
        }
        return false;
    };
    cout << (check(a, b) ? "Yes" : "No");
    return 0;
}

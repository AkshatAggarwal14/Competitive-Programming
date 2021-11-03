#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

// clang-format off
// ---------------------------<Debugging Template>------------------------
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
#define db(val) "[\033[34mLine " << __LINE__ << ": \033[39m" << #val " = " << "\033[33m" << (val) << "\033[39m] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifndef ONLINE_JUDGE
#define dbg cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#define DB() debug_block CONCAT(dbbl, __LINE__)
int __db_level = 0;
struct debug_block {
    debug_block() {
        dbg << "{" << '\n';
        ++__db_level;
    }
    ~debug_block() {
        --__db_level;
        dbg << "}" << '\n';
    }
};
#else
#define dbg \
    if (0) cerr
#define DB(...)
#endif

template <class U, class V>
print_op(pair<U, V>) { return out << "(" << u.first << ", " << u.second << ")"; }

template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it) out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}

template <size_t i, class T>
ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr (i == tuple_size<T>::value)
        return out << ")";
    else
        return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}

template <class... U>
print_op(tuple<U...>) { return print_tuple_utils<0, tuple<U...>>(out, u); }
// --------------------------</Debugging Template>------------------------
// clang-format on

void Solution() {
    // code here
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
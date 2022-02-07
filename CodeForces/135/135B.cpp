#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

struct pt {
    ll x, y;
    pt() : x(0), y(0) {}
    pt(ll X, ll Y) : x(X), y(Y) {}
    bool operator<(const pt &other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

// square of distance
ll dist(const pt &p1, const pt &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// tests if angle abc is a right angle
bool isOrthogonal(const pt &a, const pt &b, const pt &c) {
    // dot product == 0
    // ba dot bc = 0
    return ((b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0);
}

bool isRectangle(const pt &p1, const pt &p2, const pt &p3, const pt &p4) {
    // all angles 90 degrees
    if (isOrthogonal(p1, p2, p3) && isOrthogonal(p2, p3, p4) &&
        isOrthogonal(p3, p4, p1)) return true;
    if (isOrthogonal(p2, p3, p1) && isOrthogonal(p3, p1, p4) &&
        isOrthogonal(p1, p4, p2)) return true;
    if (isOrthogonal(p3, p1, p2) && isOrthogonal(p1, p2, p4) &&
        isOrthogonal(p2, p4, p3)) return true;
    return false;
}

bool isSquare(const pt &p1, const pt &p2, const pt &p3, const pt &p4) {
    // orthogonal and equal distance
    if (isOrthogonal(p1, p2, p3) && isOrthogonal(p2, p3, p4) &&
        isOrthogonal(p3, p4, p1)) {  // 1 2 3 4
        if (dist(p1, p2) == dist(p2, p3) && dist(p2, p3) == dist(p3, p4) &&
            dist(p3, p4) == dist(p4, p1)) return true;
    }
    if (isOrthogonal(p2, p3, p1) && isOrthogonal(p3, p1, p4) &&
        isOrthogonal(p1, p4, p2)) {  // 2 3 1 4
        if (dist(p2, p3) == dist(p3, p1) && dist(p3, p1) == dist(p1, p4) &&
            dist(p1, p4) == dist(p4, p2)) return true;
    }
    if (isOrthogonal(p3, p1, p2) && isOrthogonal(p1, p2, p4) &&
        isOrthogonal(p2, p4, p3)) {  // 3 1 2 4
        if (dist(p3, p1) == dist(p1, p2) && dist(p1, p2) == dist(p2, p4) &&
            dist(p2, p4) == dist(p4, p3)) return true;
    }
    return false;
}

string to_string(const pt &P) {
    return "{" + to_string(P.x) + ", " + to_string(P.y) + "}";
}

void Solution() {
    vector<pt> point(8);
    vector<ll> id(8);
    iota(all(id), 0);
    for (auto &[x, y] : point) cin >> x >> y;
    do {
        if (isSquare(point[id[0]], point[id[1]], point[id[2]], point[id[3]]) &&
            isRectangle(point[id[4]], point[id[5]], point[id[6]], point[id[7]])) {
            cout << "YES\n";
            for (ll i = 0; i < 4; ++i) cout << id[i] + 1 << ' ';
            cout << '\n';
            for (ll i = 4; i < 8; ++i) cout << id[i] + 1 << ' ';
            return;
        }
    } while (next_permutation(all(id)));
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}
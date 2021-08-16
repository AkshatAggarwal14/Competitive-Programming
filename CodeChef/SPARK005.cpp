#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template <class T, class T1>
int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template <class T, class T1>
int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

int n, x, p, k;
int a[MAXN];

void read() {
    cin >> n >> x >> p >> k;
    assert(x >= 0 && x <= (int)1e9);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    p--, k--;
}

bool no_x() {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return false;
    }

    return true;
}

void solve() {
    sort(a, a + n);

    int add = 0;
    if (no_x()) {
        add++;
        a[k] = x;
        sort(a, a + n);
    }

    if (a[p] == x) {
        cout << add << endl;
        return;
    }

    // binary search -> loop

    int position_x = -1;
    for (int dx = 0; dx < n; dx++) {
        if (k >= dx && a[k - dx] == x) {
            position_x = k - dx;
            break;
        }

        if (k + dx < n && a[k + dx] == x) {
            position_x = k + dx;
            break;
        }
    }

    if (position_x <= k && position_x <= p && p <= k) {
        cout << add + p - position_x << endl;
    } else if (position_x >= k && k <= p && p <= position_x) {
        cout << add + position_x - p << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        read();
        solve();
    }

    return 0;
}
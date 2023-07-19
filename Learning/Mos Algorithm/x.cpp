#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// member functions :
// 1. order_of_key(k) : number of elements strictly lesser than k
// 2. find_by_order(k) : k-th element in the set
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

using i64 = long long;
const i64 Mod = 1000000007;
const i64 MOD = 998244353;
const i64 Inf = 1E18;
const int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
const int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

// FOR unordered_map<int,int,custom_hash> TO AVOID FALTU TLE'S COZ OF ANTIHASHES.
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
T roundup(T a, T b) {
    return (a / b + ((a ^ b) > 0 && a % b));
}

template <typename T>
T choose(T n, T r) {
    if (n < r) return 0LL;
    T res = 1;
    for (T e = 0; e < r; e++) {
        res = res * (n - e);
        res = res / (e + 1);
    }
    return res;
}

template <typename T>
bool expotwo(T n) {
    T val = (n & (n - 1));
    if (val == 0LL) return true;
    return false;
}

template <typename T>
T modexpo(T b, T e, T mod) {
    T ans = 1;
    while (e) {
        if (e & 1) ans = ((ans % mod) * (b % mod)) % mod;
        b = ((b % mod) * (b % mod)) % mod;
        e >>= 1;
    }
    return ans;
}

template <typename T>
T expo(T b, T e) {
    T ans = 1;
    while (e) {
        if (e & 1) ans = ans * b;
        b = b * b;
        e >>= 1;
    }
    return ans;
}

template <typename T>
bool eprime(T n) {
    if (n < 2) return false;
    for (T e = 2; e * e <= n; e++) {
        if (n % e == 0) return false;
    }
    return true;
}

template <typename T>
bool eparity(T x, T y) {
    return !((x & 1) ^ (y & 1));
};

template <typename T>
void amax(T &a, T b) {
    a = max(a, b);
}

template <typename T>
void amin(T &a, T b) {
    a = min(a, b);
}

template <typename T>
void add(T &a, T b, T M) {
    a = ((a % M) + (b % M)) % M;
}

template <typename T>
void mul(T &a, T b, T M) {
    a = ((a % M) * (b % M)) % M;
}

template <typename T>
void sub(T &a, T b, T M) {
    a = (a - b + M) % M;
}

/* ------------------------------------------ lessgo -------------------------------------------------*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// bakchodi
char getChar() {
    static char buf[1 << 20];
    static int pos = 0;
    static int size = 0;
    if (pos == size) {
        size = (int)fread(buf, 1, 1 << 20, stdin);
        pos = 0;
    }
    if (pos == size) {
        return EOF;
    }
    return buf[pos++];
}

template <typename T>
inline void read(T &v) {
    char c = '?';
    while (!(c == '-' || ('0' <= c && c <= '9'))) c = getChar();
    bool positive = true;
    if (c == '-') {
        positive = false;
        c = getChar();
    }
    v = 0;
    while ('0' <= c && c <= '9') {
        (v *= 10) += (c - '0');
        c = getChar();
    }
    if (!positive) v = -v;
}

void putChar(char c) {
    static char buf[1 << 20];
    static int size = 0;
    if (size == 1 << 20 || c == -1) {
        fwrite(buf, 1, size, stdout);
        size = 0;
    }
    if (c != -1) {
        buf[size++] = c;
    }
}

inline void writeln(int v) {
    static int stack[15];
    int size = 0;
    do {
        stack[size++] = v % 10;
        v /= 10;
    } while (v > 0);
    while (size--) {
        putChar(char(stack[size] + '0'));
    }
    putChar('\n');
}

int BLOCK_SIZE;
vector<int> v, cnt, decompress;
map<int, int> compress;
int ans;

void insert(int x) {
    if (cnt[v[x]] > 0) ans ^= decompress[x];
    cnt[v[x]]++;
}

void remove(int x) {
    if (cnt[v[x]] > 1) ans ^= decompress[x];
    cnt[v[x]]--;
}

void Solution() {
    int n;
    read(n);
    BLOCK_SIZE = sqrt(n) + 1;
    v = vector<int>(n);
    cnt = vector<int>(n + 5);
    for (int i = 0; i < n; i++) read(v[i]), compress[v[i]]++;
    int y = 0;
    for (auto &x : compress) x.second = y++;
    for (auto &x : v) decompress.emplace_back(x);
    for (auto &x : v) x = compress[x];
    int q;
    read(q);
    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        read(l);
        read(r);
        queries[i][0] = l - 1;
        queries[i][1] = r - 1;
        queries[i][2] = i;
    }
    ans = 0;

    sort(queries.begin(), queries.end(), [&](const array<int, 3> &a, const array<int, 3> &b) {
        if (a[0] / BLOCK_SIZE != b[0] / BLOCK_SIZE)
            return a < b;
        return (a[0] / BLOCK_SIZE & 1) ? (a[1] < b[1]) : (a[1] > b[1]);
    });

    vector<int> res(q);
    int cur_l = 0, cur_r = -1;
    for (auto &x : queries) {
        while (cur_l > x[0]) {
            cur_l--;
            insert(cur_l);
        }
        while (cur_r < x[1]) {
            cur_r++;
            insert(cur_r);
        }
        while (cur_l < x[0]) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > x[1]) {
            remove(cur_r);
            cur_r--;
        }
        res[x[2]] = ans;
    }
    for (auto &x : res) writeln(x);
    putChar(-1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution();
}
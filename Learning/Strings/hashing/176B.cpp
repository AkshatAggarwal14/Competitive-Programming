// https://cp-algorithms.com/string/string-hashing.html
// https://leetcode.com/problems/string-transformation/

#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll MOD = 1e9 + 7;  // 998244353;

struct Matrix {
    static const ll M = MOD;
    static const ll SQMOD = M * M;
    static ll const N = 10;
    ll mat[N][N];
    ll n, m;
    Matrix(ll _n = N, ll _m = N, ll val = 0) : n(_n), m(_m) {
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = val;
    }
    Matrix(const vector<vector<ll>> &&other) {
        n = ll(other.size());
        m = ll(other[0].size());
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                mat[i][j] = other[i][j];
    }
    Matrix &operator=(const vector<vector<ll>> &&other) {
        return *this = Matrix(forward<decltype(other)>(other));
    }
    ll *operator[](ll r) { return mat[r]; }
    const ll *operator[](ll r) const { return mat[r]; }
    static Matrix unit(ll n) {
        Matrix res(n, n);
        for (ll i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }
    Matrix &operator+=(const Matrix &rhs) {
        assert(n == rhs.n && m == rhs.m);
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j) {
                mat[i][j] += rhs[i][j];
                if (mat[i][j] >= M) mat[i][j] -= M;
            }
        return *this;
    }
    Matrix operator+(const Matrix &rhs) const {
        Matrix lhs(*this);
        return lhs += rhs;
    }
    friend Matrix operator*(const Matrix &A, const Matrix &B) {
        assert(A.m == B.n);
        Matrix res(A.n, B.m);
        for (ll i = 0; i < res.n; i++)
            for (ll j = 0; j < res.m; j++) {
                ll sum = 0LL;
                for (ll k = 0; k < A.m; k++) {
                    sum += A[i][k] * B[k][j];
                    if (sum >= SQMOD) sum -= SQMOD;
                }
                res[i][j] = (sum % M);
            }
        return res;
    }
    friend Matrix power(Matrix base, long long ex) {
        assert(base.n == base.m);
        Matrix res = Matrix::unit(base.n);
        while (ex > 0) {
            if (ex & 1) res = res * base;
            base = base * base;
            ex >>= 1;
        }
        return res;
    }
    friend string to_string(const Matrix &a) {
        string res = "\n";
        for (ll i = 0; i < a.n; ++i) {
            res += '{';
            for (ll j = 0; j < a.m; ++j) {
                res += std::to_string(a.mat[i][j]);
                if (j != a.m - 1) res += ", ";
            }
            res += "}\n";
        }
        res.append("\n");
        return res;
    }
    Matrix &operator*=(const Matrix &rhs) { return *this = *this * rhs; }
};

const ll p = 31;

class Solution {
   public:
    int numberOfWays(string s, string t, long long k) {
        int n = int(s.size());

        /*
            int match = 0, mismatch = 0;
            for (int i = 0; i < n; ++i) {
                rotate(s.begin(), s.begin() + n - 1, s.end());
                match += (s == t);
            }
            mismatch = n - match;
        */

        int match = 0, mismatch = 0;

        vector<ll> p_pow(n + 1, 1);
        vector<ll> pre_hash(n + 1, 0);
        ll t_hash = 0;
        for (int i = 0; i < n; ++i) {
            p_pow[i + 1] = (p_pow[i] * p) % MOD;
            pre_hash[i + 1] = (pre_hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
            (t_hash += (t[i] - 'a' + 1) * p_pow[i]) %= MOD;
        }

        for (int i = 0; i < n; ++i) {
            // [i+1 ..n-1] + p * [0...i]
            ll second_half = pre_hash[i + 1];
            ll first_half = 0;
            first_half = ((pre_hash[n] - pre_hash[i + 1]) % MOD + MOD) % MOD;

            ll total = (first_half % MOD + (second_half * p_pow[n]) % MOD) % MOD;

            t_hash *= p;
            t_hash %= MOD;
            if (total == t_hash)
                ++match;
        }

        mismatch = n - match;

        /*
            vector<ll> dpA(k + 1, 0), dpB(k + 1, 0);

            dpA[0] = (s == t);
            dpB[0] = (s != t);

            for (int i = 1; i <= k; ++i) {
                dpA[i] = (dpA[i - 1] * (match - 1) + dpB[i - 1] * match) % MOD;
                dpB[i] = (dpB[i - 1] * (mismatch - 1) + dpA[i - 1] * mismatch) % MOD;
            }

            cout << dpA[k] << '\n';
        */

        // [dpA(i) dpB(i)] = [dpA(i-1) dpB(i-1)][match-1 mismatch  ]
        //                                      [match   mismatch-1]
        // [M(k)] = [M(0)] * T^k

        Matrix Base({{(s == t), (s != t)}});
        Matrix Transform({{match - 1, mismatch},
                          {match, mismatch - 1}});

        return int((Base * power(Transform, k))[0][0] % MOD);
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    Solution st;
    string s, t;
    ll k;
    cin >> s >> t >> k;

    cout << st.numberOfWays(s, t, k) << '\n';
    return 0;
}

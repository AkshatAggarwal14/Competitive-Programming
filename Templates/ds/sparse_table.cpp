#include <bits/stdc++.h>
using namespace std;

template <class T, class U = function<T(const T &, const T &)>, class V = function<T()>>
class Sparse_Table {
    int N, K;
    vector<int> LOG;
    vector<vector<T>> st;
    U op;
    V id;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP, const V &ID)
        : N(int(arr.size())), K(__lg(N)), LOG(N + 1), st(N, vector<T>(K + 1)), op(OP), id(ID) {
        LOG[1] = 0;
        for (int i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (int i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T slow_query(int L, int R) {
        T res = id();
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                res = op(res, st[L][j]);
                L += (1 << j);
            }
        }
        return res;
    }
    T query(int L, int R) {
        if (L > R) return id();
        int j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};
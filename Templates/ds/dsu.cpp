#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int N;
    vector<int> par, siz;
    int components;
    DSU(int n) : N(n), par(N), siz(N, 1), components(N) {
        for (int i = 0; i < N; i++) par[i] = i;
    }
    int root(int X) {
        if (par[X] != X) par[X] = root(par[X]);
        return par[X];
    }
    bool same(int X, int Y) { return root(X) == root(Y); }
    void unite(int X, int Y) {
        X = root(X), Y = root(Y);
        if (X == Y) return;
        if (siz[Y] < siz[X]) swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
        --components;
    }
    int get_size(int X) { return siz[root(X)]; }
};
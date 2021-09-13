#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
using str = string;
template <class T>
using v = vector<T>;
using vl = v<ll>;
using vvl = v<vl>;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

// vl primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
// vl ops;
vl ops = {6, 10, 14, 22, 26, 34, 38, 46, 58, 62, 74, 82, 86, 94, 106, 118, 122, 134, 142, 146, 158, 166, 178, 194, 6, 15, 21, 33, 39, 51, 57, 69, 87, 93, 111, 123, 129, 141, 159, 177, 183, 10, 15, 35, 55, 65, 85, 95, 115, 145, 155, 185, 14, 21, 35, 77, 91, 119, 133, 161, 22, 33, 55, 77, 143, 187, 26, 39, 65, 91, 143, 34, 51, 85, 119, 187, 38, 57, 95, 133, 46, 69, 115, 161, 58, 87, 145, 62, 93, 155, 74, 111, 185, 82, 123, 86, 129, 94, 141, 106, 159, 118, 177, 122, 183, 134, 142, 146, 158, 166, 178, 194};
// void fill() {
//     fo(i, sz(primes)) {
//         fo(j, sz(primes)) {
//             if (primes[i] * primes[j] <= 200) {
//                 if (primes[i] != primes[j])
//                     ops.emplace_back(primes[i] * primes[j]);
//             }
//         }
//     }
// }

void Solution(ll _i) {
    // cout << "Case #" << _i << ": ";
    // dbg(ops);
    ll n;
    cin >> n;
    for (ll i = 1; i < n; ++i) {
        if (find(all(ops), i) != ops.end()) {
            ll rem = n - i;
            if (find(all(ops), rem) != ops.end()) {
                dbg(i, rem);
                return void(cout << "YES\n");
            }
        }
    }
    cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    // fill();
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) Solution(i);
    return 0;
}
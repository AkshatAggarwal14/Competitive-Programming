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

ll n, rem;
str s;
void trim(str &str) {
    str.erase(0, min(str.find_first_not_of('0'), str.size() - 1));
}

void ins1(ll num, v<ll> cnt, v<str> &options) {
    str res = "";
    cnt[num]--;
    fo(i, n) {
        if (cnt[s[i] - '0']-- > 0)
            res += s[i];
    }
    // reverse(all(res));
    trim(res);
    options.emplace_back(res);
}

void ins2(ll I, ll J, v<ll> cnt, v<str> &options) {
    str res = "";
    cnt[I]--;
    cnt[J]--;
    fo(i, n) {
        if (cnt[s[i] - '0']-- > 0)
            res += s[i];
    }
    // reverse(all(res));
    trim(res);
    options.emplace_back(res);
}

void Solution(ll _i) {
    // cout << "Case #" << _i << ": ";
    str res = "";
    cin >> s;
    n = sz(s);
    vl cnt(10, 0);
    ll sum = 0;
    v<str> options;
    fo(i, n) {
        ++cnt[s[i] - '0'];
        sum += (s[i] - '0');
    }
    ll rem = sum % 3;
    if (rem == 0) {
        cout << s << '\n';
        return;
    }
    // just remove one ele
    fo(i, 10) {
        if (rem == i % 3) {
            if (cnt[i] >= 1) {
                ins1(i, cnt, options);
            }
        }
    }

    fo(i, 10) {
        fo(j, 10) {
            if (rem == (i + j) % 3) {
                if ((i != j && cnt[i] && cnt[j]) || (i == j && cnt[i] >= 2)) {
                    ins2(i, j, cnt, options);
                }
            }
        }
    }

    sort(all(options));
    (options).erase(unique(all(options)), (options).end());
    sort(all(options), [&](str A, str B) {
        if (sz(A) > sz(B)) return true;
        if (sz(A) == sz(B)) {
            if (A > B) return true;
        }
        return false;
    });
    if (sz(options) == 0 || options[0] == "") {
        cout << -1 << '\n';
    } else
        cout << options[0] << '\n';
    dbg(options, rem);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) Solution(i);
    return 0;
}
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2/0000000000150a0d

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> int { return int(container.size()); };
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

const ll N = 1001;
const ll K = 1001;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int _testcases = 1;
    cin >> _testcases;
    for (int _tt = 1; _tt <= _testcases; ++_tt) {
        cout << "Case #" << _tt << ": ";

        /* starting idea: dp[i][j] -> time taken to observe j dogs of first i colors - [0..i]

        ? Observations:
            1. A person will never repeat same T-shirt again in future
                - This is because we will go to rightmost optimal point for a given color in only one move away from home.
                - longest optimal trip is made only once, otherwise we repeat time for smaller prefix twice
            2. We wont change the last t-shirt thus round trip only for (trips - 1) times, in last trip we end at the dogs instead of house.
            3. We only move until the last position of dog of a given color shirt.
            4. Order of round trips doesnt matter as in a round trip, we ignore all other color dogs.

        ? Store positions of dogs for each color
        ? p[i][j] -> position of jth dog of ith color
        (c1 c2 c3.. cS, K) ->   1. (c2 c3.. cS, K) {dont observe anything with color 1 shirt}
                                2. if not last -> (c2 c3.. cS, K - j) + 2 * p[1][j] {Observe j dogs of this color}
                                3. if last -> p[1][j]
        ? boolean variable to know if already selected a one way trip

        (c1 c2 c3.. cS, K, B) -> B represents whether i have fixed last t shirt or not

        ll dp[N][K][B];
        - dp[i][x][0]: minimum number of time to observe x dogs using tshirts of color[i..S], can use tshirt for one way trip
        - dp[i][x][1]: minimum number of time to observe x dogs using tshirts of color[i..S], given all trips are round trips
        - ans: dp[n][k][0]
        - dp[i][x][1]: {2 * p[i][j] + dp[i + 1][x - j][1]} Select minimum for all positions of col[i], i.e. j
        - dp[i][x][0]:  1. round trip: 2 * p[i][j] + dp[i + 1][x - j][0] {can still use one way trip}
                        2. one - way trip used: p[i][j] + dp[i + 1][x - j][1]
         */
        ll n, k;
        cin >> n >> k;
        vector<ll> pos(n), col(n);
        for (auto &i : pos) cin >> i;
        for (auto &i : col) cin >> i;

        vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(K, vector<ll>(2, -1)));
        vector<ll> pos_col[N];
        for (ll i = 0; i < n; ++i)
            pos_col[col[i]].push_back(pos[i]);  // put all positions of i colored dog in pos_dog[i]

        for (ll i = 0; i < N; ++i) sort(pos_col[i].begin(), pos_col[i].end());

        function<ll(ll, ll, bool)> dfs = [&](ll i, ll x, bool last_fix) {
            if (x <= 0) return 0LL;
            if (i == 1001) return INF;  // {have tried all tshirts still not observed k dogs}
            ll &ans = dp[i][x][last_fix];
            if (ans != -1) return ans;

            ans = dfs(i + 1, x, last_fix);  // didnt use color
            for (ll j = 0; j < int(pos_col[i].size()); ++j) {
                if (!last_fix) {
                    ans = min(ans, pos_col[i][j] + dfs(i + 1, x - (j + 1), 1));
                }
                ans = min(ans, 2 * pos_col[i][j] + dfs(i + 1, x - (j + 1), last_fix));
            }
            return ans;
        };
        cout << dfs(1, k, 0) << '\n';
    }

    return 0;
}

#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ld = long double;

const int N = 305;
ld dp[N][N][N];

/*
    As die shows numbers with equal probability, we can shuffle, thus state only depends on frequency of dishes with 1/2/3 sushies

    cnt1 = count of dishes with 1 sushi
    cnt2 = count of dishes with 2 sushi
    cnt3 = count of dishes with 3 sushi
    cnt0 = count of dishes with no sushies = n-cnt1-cnt2-cnt3

    dp[cnt1][cnt2][cnt3] = Expected number of sushi eats required for cnt1 dishes with 1 sushi, cnt2 dishes with 2 sushies, cnt3 dishes with 3 sushies:

    dp[0][0][0] = 0
    dp[x][y][z] = 1 + p0 * dp[x][y][z] + p1 * dp[x-1][y][z] + p2 * dp[x+1][y-1][z] + p3 * dp[x][y+1][z-1]

    p0 = probability of a dish with 0 sushies = (N - (x + y + z)) / N

    -> 1 means 1 move needed for current turn
    -> p0 * dp[x][y][z] means probability of choosing 0 sushi dish * expected number of sushi eats to eat leftover dishes after a 0 sushi dish
    -> p1 * dp[x-1][y][z] means probability of choosing 1 sushi dish * expected number of sushi eats to eat leftover dishes after a 1 sushi dish
    -> p2 * dp[x+1][y-1][z] means probability of choosing 1 sushi dish * expected number of sushi eats to eat leftover dishes after a 1 sushi dish => number of 1 sushi dishes increase by one and 2 sushi dish decrease by 1 when you eat a sushi from a 2 sushi dish

    ! => dp[x][y][z] = (1 + p1 * dp[x-1][y][z] + p2 * dp[x+1][y-1][z] + p3 * dp[x][y+1][z-1]) / (1 - p0)
    ! => dp[x][y][z] = (1 + p1 * dp[x-1][y][z] + p2 * dp[x+1][y-1][z] + p3 * dp[x][y+1][z-1]) / (1 - p0)
    ! => dp[x][y][z] = (1 + (x/N) * dp[x-1][y][z] + (y/N) * dp[x+1][y-1][z] + (z/N) * dp[x][y+1][z-1]) / (x + y + z) / N
    ! => dp[x][y][z] = (N + x * dp[x-1][y][z] + y * dp[x+1][y-1][z] + z * dp[x][y+1][z-1]) / (x + y + z)

    Now, dp[.][.][z] depends on dp[.][.][z] and dp[.][.][z-1] (So we move from small to large z)

    dp[.][y][z] depend on dp[.][y][z] + dp[.][y-1][z] + dp[.][y+1][z-1]
    Now as z-1 is calculated before z, we only need to worry about first two terms (So we move from small to large y)

    dp[x][y][z] depends on dp[x-1][y][z] (So we move from small to large x)
*/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int cnt[4] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ++cnt[num];
    }

    for (int z = 0; z <= n; ++z) {
        for (int y = 0; y <= n; ++y) {
            for (int x = 0; x <= n; ++x) {
                if (x == 0 && y == 0 && z == 0) {
                    dp[x][y][z] = 0;
                } else {
                    dp[x][y][z] = n;
                    if (x > 0) {
                        dp[x][y][z] += dp[x - 1][y][z] * ld(x);
                    }
                    if (y > 0) {
                        dp[x][y][z] += dp[x + 1][y - 1][z] * ld(y);
                    }
                    if (z > 0) {
                        dp[x][y][z] += dp[x][y + 1][z - 1] * ld(z);
                    }

                    dp[x][y][z] /= ld(x + y + z);
                }
            }
        }
    }

    cout << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]] << '\n';

    return 0;
}

//****************master._.mind****************
//-----------Author: Akshat Aggarwal-----------
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define ub() upper_bound()
#define lb() lower_bound()
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ps(x, y) fixed << setprecision(y) << x
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
#define ln "\n"
#define sz(x) ((ll)(x).size())
#define fast_io()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-12;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
//ll divisorCount(ll);

void solve()
{

    ll n, m, i, j;
    cin >> n >> m;
    char mat[n][m];
    fo(i, n) fo(j, m) cin >> mat[i][j];
    char mat1[n][m], mat2[n][m], dots[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i % 2 == 0)
                mat1[i][j] = (j % 2 == 0) ? 'R' : 'W';
            else
                mat1[i][j] = (j % 2 == 0) ? 'W' : 'R';
            dots[i][j] = '.';
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i % 2 == 0)
                mat2[i][j] = (j % 2 == 0) ? 'W' : 'R';
            else
                mat2[i][j] = (j % 2 == 0) ? 'R' : 'W';
        }
    }
    ll flag1 = 1, flag2 = 1, flag3 = 1;
    fo(i, n)
    {
        fo(j, m)
        {
            if (mat[i][j] != '.')
            {
                if (mat[i][j] != mat1[i][j])
                {
                    flag1 = 0;
                    break;
                }
            }
        }
    }
    fo(i, n)
    {
        fo(j, m)
        {
            if (mat[i][j] != '.')
            {
                if (mat[i][j] != mat2[i][j])
                {
                    flag2 = 0;
                    break;
                }
            }
        }
    }
    fo(i, n)
    {
        fo(j, m)
        {
            if (mat[i][j] != dots[i][j])
            {
                flag3 = 0;
                break;
            }
        }
    }

    if (flag1 == 1 && flag2 == 0)
    {
        cout << "YES\n";
        fo(i, n)
        {
            fo(j, m) cout << mat1[i][j];
            cout << ln;
        }
    }
    else if (flag2 == 1 && flag1 == 0)
    {
        cout << "YES\n";
        fo(i, n)
        {
            fo(j, m) cout << mat2[i][j];
            cout << ln;
        }
    }
    else if (flag3 == 1)
    {
        cout << "YES\n";
        fo(i, n)
        {
            fo(j, m) cout << mat1[i][j];
            cout << ln;
        }
    }
    else
        cout << "NO\n";
    return;
}

int main()
{
    fast_io();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        // cout << "\n";
    }
    return 0;
}

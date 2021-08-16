//****************master._.mind****************
//-----------Author: Akshat Aggarwal-----------
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define rall(x) (x).rbegin(), (x).rend()
#define ps(x, y) fixed << setprecision(y) << x
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
#define ln "\n"
#define sz(x) ((ll)(x).size())
#define cn cout << "\n"
#define cy cout << "YES"
#define cno cout << "NO"
#define re return
#define fast_io()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
//cin.tie(NULL) is used to read all input before displaying any output
const ll mod = 1e9 + 7; //1000000007
const ll mod2 = 998244353;
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

// Returns a vector containing all primes less than n using seive of eratosthenes
vl primes_less_than(ll n)
{
    vl ans(0);
    if (n <= 2)
        return ans;
    map<ll, bool> is_prime;
    fo(i, n) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;

    for (ll i = 2; i < sqrt(n); i++)
        if (is_prime[i])
            for (ll j = i * i; j < n; j += i)
                is_prime[j] = false;

    fo(i, n) if (is_prime[i] == true) ans.pb(i);
    return ans;
}

//Returns a vector containing all primes between L and R (both, inclusive) using seive of eratosthenes
vl primes_in_range(ll L, ll R) //!Using seive of eratosthenes
{
    vl all_primes = primes_less_than(R + 1);
    vl ans;
    fo(i, sz(all_primes)) if (all_primes[i] >= L && all_primes[i] <= R)
        ans.pb(all_primes[i]);

    return ans;
}

void solve()
{
    // ll n;
    // cin >> n;
    // vl ans = primes_less_than(n);
    ll a, b;
    cin >> a >> b;
    vl ans = primes_in_range(a, b);

    cout << "[";
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << (i != ans.size() - 1 ? ", " : "");
    }
    cout << "]";

    re;
}

int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    clock_t start, end;
    start = clock();

    ll testcases = 1;
    //cin >> testcases;
    while (testcases--)
    {
        solve();
        cn;
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "Time taken:" << ln << ps(time_taken, 6) << " sec\n";
    re 0;
}

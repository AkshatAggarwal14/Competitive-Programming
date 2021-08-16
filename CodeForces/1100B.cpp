//**********************master._.mind**********************
//-----------------Author: Akshat Aggarwal-----------------
//If you don't understand the code below... dont worry, i didn't either
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double
#define ull unsigned long long
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
#define sz(x) ((ll)(x).size())
#define ln '\n'
#define cy cout << "YES"
#define cno cout << "NO"
#define cn cout << '\n'
#define re return
//cin.tie(NULL) is used to read all input before displaying any output
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const double eps = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;

//divisor_count(ll)
//prime_facorisation(n)
//primes_less_than(n)

class Task {
   public:
    void Perform() {
        Read();
        Solve();
    }

   private:
    ll n, m;
    vl arr;

    void Read() {
        cin >> n >> m;
        arr.resize(m);
        fo(i, m) cin >> arr[i];
    }

    /**
     * 2 3 1 2 2 2 3 2 2 3 1
     * 1 1 1 2 3 4 2 5 6 3 2 <--brr (iterates and finds count of each element as we move through)
     * 1 2 3 1 1 1 2 1 1 2 3 <--ans (iterates and finds count of each element as we move through)
     * so number of 3's is the answer
    */

    void Solve() {
        vl brr(m);  //stores count of each element as we move across arr
        map<ll, ll> cnt;
        fo(i, m) {
            cnt[arr[i]]++;
            brr[i] = cnt[arr[i]];
        }
        map<ll, ll> ans;
        fo(i, m) {
            ans[brr[i]]++;
            if (ans[brr[i]] == n)
                cout << 1;  // output 1 only when count of an element is == n
            else
                cout << 0;
        }
        cn;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Task t;
        t.Perform();
    }
    return 0;
}
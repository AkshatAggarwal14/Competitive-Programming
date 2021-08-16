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
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
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
    ll n;
    string s;

    void Read() {
        cin >> n >> s;
    }

    void Solve() {
        //!m1
        ll sit = 0, std = 0;
        fo(i, n) if (s[i] == 'x') sit++;
        else std++;

        ll cnt = abs(sit - std) / 2;

        char ch = 'x';
        if (sit > std) ch = 'X';
        cout << cnt << ln;

        fo(i, n) if (cnt and s[i] != ch) {
            s[i] = ch;
            cnt--;
        }

        cout << s << ln;

        //!m2
        /*
        ll x = 0, X = 0, i, j;
        char chi, chj;
        fo(i, n)(s[i] == 'x' ? x++ : X++);
        if (x < X) {
            i = x;
            chi = 'x';
            j = X;
            chj = 'X';
        } else if (x > X) {
            i = X;
            chi = 'X';
            j = x;
            chj = 'x';
        } else {
            cout << 0 << ln << s << ln;
            re;
        }
        deb2(i, j);
        deb2(chi, chj);
        cout << abs(i - j) / 2 << ln;
        for (ll k = 0; k < n; k++) {
            if (s[k] == chi)
                continue;
            else {
                s[k] = chi;
                i++;
                j--;
            }
            if (i >= j) break;
        }
        cout << s << ln;
        */
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
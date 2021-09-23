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
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const double eps = 1e-12;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

//* --------pre defined functions--------
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

//divisor_count(ll)
//prime_facorisation(n)
//primes_less_than(n)

/*
                 ""
              /     \
            4        7
          /   \     / \ 
        44    47   74  77
       / \   / \  / \  / \

The idea is to fill the required number from end. We know can observe that the last digit is 4 if n is odd and last digit is 7 if n is even. After filling last digit, we move to parent node in tree. If n is odd, then parent node corresponds to (n-1/2. Else parent node corresponds to (n-2)/2. 
*/

ll NthLuckyNumber(ll n) {
    string res = "";
    while (n >= 1) {
        // If n is odd, append 4 and
        // move to parent
        if (n & 1) {
            res = res + "4";
            n = (n - 1) / 2;
        }

        // If n is even, append 7 and
        // move to parent
        else {
            res = res + "7";
            n = (n - 2) / 2;
        }
    }

    // Reverse res and return.
    reverse(res.begin(), res.end());
    // converting string to number using a stringstream
    stringstream ok(res);
    ll ret = 0;
    ok >> ret;
    return ret;
}

vl lucky;
void fillLukcy() {
    ll i = 1;
    while (true) {
        if (NthLuckyNumber(i - 1) > mod)
            re;
        lucky.pb(NthLuckyNumber(i));
        i++;
    }
    re;
}

void solve() {
    //*********************CODE STARTS HERE*********************

    //! M1 find all "lucky numbers" until the range.
    //! M2 as we can observe in the series: 4,7,44,47,74,77... the last digit is alternating

    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    //* Instead of just adding directly which gives TLE, multiply count of terms from l to b[i] with b[i]
    // for (ll i = 0; i < lucky.size(); i++)
    // {
    //     if (l > r)
    //         break;
    //     if (l <= lucky[i])
    //     {
    //         l++;
    //         ans += lucky[i];
    //         i--;
    //     }
    // }
    // cout << ans; //:' TLE AT TEST 15

    for (int i = 0; i < lucky.size(); i++) {
        if (l > r)
            break;
        if (l <= lucky[i]) {
            if (r >= lucky[i]) {
                int cnt = lucky[i] - l + 1;  //count of numbers between l and lucky[i]
                ans += lucky[i] * cnt;
                l = lucky[i] + 1;  //start from after the count is completed
            } else {
                ans += lucky[i];  // add greater element for one element at a time
                l++;              // adding 1 to l when r<lucky[i] and
                                  //for example when l is 2 and 3 so lucky[i] is 4 so we add 4 for 2 and 4 for 3 but not for 4 so we go through them one by one when r<lucky[i]
                                  //! instead we could have counted terms where r<lucky[i] and then multiply by lucky[i]
                i--;              //to nullify i++ from for loop which takes us to next one.
            }
        }
    }
    cout << ans;

    //**********************CODE ENDS HERE**********************
    re;
}  //todo solve

int main() {
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    clock_t start, end;
    start = clock();
    fillLukcy();
    ll testcases = 1;
    //todo testcases
    //cin >> testcases;
    while (testcases--) {
        solve();
        cn;
    }

    //* -----for time calc-----
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "\nTime taken:" << ln << ps(time_taken, 6) << " sec\n";
    re 0;
}  //todo main

//* ------function definitions------
template <class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
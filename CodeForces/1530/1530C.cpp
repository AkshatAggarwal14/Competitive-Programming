//**********************master._.mind**********************
//-----------------Author: Akshat Aggarwal-----------------
//If you don't understand the code below... dont worry, i didn't either
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define ll long long
#define ld long double
#define ull unsigned long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define ln '\n'
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << "[" << #x << "]: " << x << ln
#define deb2(x, y) cout << "[" << #x << "]: " << x << ", [" << #y << "]: " << y << ln
#define pb push_back
#define eb emplace_back
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
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define sz(x) ((ll)(x).size())
const ll mod = 1e9 + 7;  //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const double eps = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(char ch) {
    string s(1, ch);
    return '\'' + s + '\'';
}

string to_string(const char *s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "{" + to_string(p.ff) + ", " + to_string(p.ss) + "}";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << to_string(H) << ln;
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class Task {
   public:
    void Perform() {
        Read();
        Solve();
    }

   private:
    ll n;
    vl a, b;

    void Read() {
        cin >> n;
        a.resize(n);
        b.resize(n);
        fo(i, n) cin >> a[i];
        fo(i, n) cin >> b[i];
    }

    void Solve() {
        vl pre_a(n + 1);
        vl pre_b(n + 1);
        sort(all(a), greater<ll>());
        sort(all(b), greater<ll>());

        pre_a[1] = a[0];
        pre_b[1] = b[0];
        rep(i, 2, n + 1) {
            pre_a[i] = pre_a[i - 1] + a[i - 1];
            pre_b[i] = pre_b[i - 1] + b[i - 1];
        }

        ll low = 0, high = 1e9, mid, siz, a_rem, b_rem, sa, sb;
        while (low < high) {
            mid = (low + high) / 2;
            siz = (n + mid) - (n + mid) / 4;  //n+mid=k

            a_rem = max(siz - mid, 0LL);
            b_rem = min(siz, n);

            // min score we need to add is mid*100
            sa = pre_a[a_rem] + mid * 100;
            sb = pre_b[b_rem];

            if (sa < sb) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        cout << low << ln;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    auto start = chrono::high_resolution_clock::now();

    int tc = 1;
    cin >> tc;
    while (tc--) {
        Task t;
        t.Perform();
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-6;
    cerr << ps(time_taken, 6) << " ms" << ln;
    return 0;
}
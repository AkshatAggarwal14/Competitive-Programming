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
    ll n, x;
    vl a;

    void Read() {
        cin >> n >> x;
        a.resize(n);
        fo(i, n) cin >> a[i];
    }

    void Solve() {
        ll sum = accumulate(a.begin(), a.end(), 0LL);
        if (sum == x) {  //the explosion cant be prevented
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            if (x == a[i]) {
                //i+1 will always be less than n because otherwise, the total sum would be x
                swap(a[i], a[i + 1]);
            }
            cout << a[i] << ' ';
            x -= a[i];
        }
        cout << ln;
        return;
    }

    //!m2
    /*
    ll n, x;
    deque<ll> dq;

    void Read() {
        cin >> n >> x;
        dq.resize(n);
        fo(i, n) cin >> dq[i];
    }
    void Solve() {
        sort(all(dq));
        fo(i, n) {
            if (check(dq, x)) {
                cout << "YES\n";
                fo(i, n) cout << dq[i] << " ";
                cout << '\n';
                return;
            } else {
                dq.eb(dq[0]);
                dq.pop_front();
            }
        }
        cout << "NO\n";
    }

    // check if sum of dq[i] is equal to x
    bool check(deque<ll> dq, ll x) {
        ll sum = 0;
        debug(dq);
        for (auto i : dq) {
            sum += i;
            if (sum == x)
                return false;
        }
        return true;
    }
    */
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
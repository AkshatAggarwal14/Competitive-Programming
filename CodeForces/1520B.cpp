/*	ॐ	*/
// Akshat Aggarwal
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for (ll i = 0; i < n; i++)
#define rep(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
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

void solve()
{

    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i = i * 10 + 1)
        for (ll d = 1; d <= 9; d++)
            if (i * d <= n)
                ans++;
    cout << ans << endl;

    // ll n;
    // cin >> n;

    // ll temp = 0, ans = 0;
    // ll digs = floor(log10(n)) + 1;

    // fo(i, digs)
    // {
    //     temp = temp * 10 + 1;
    //     // For each multiple of temp in range 1 to 9, 11,22,33,44,55..99
    //     rep(j, 1, 10) if (temp * j <= n)
    //         ans++; //no one repeats as all different 1,2,3..9; 11,22,..99; 111,222,..999;
    // }

    // cout << ans;
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
        cout << "\n";
    }
    return 0;
}

/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> v{1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99,111,222,333,444,555,666,777,888,999,
    1111,2222,3333,4444,5555,6666,7777,8888,9999,11111,22222,33333,44444,55555,66666,77777,87888,99999,
    111111,222222,333333,444444,555555,666666,777777,888888,999999,
    1111111,2222222,3333333,4444444,5555555,6666666,7777777,8888888,9999999,
    11111111,22222222,33333333,44444444,55555555,66666666,77777777,88888888,99999999,
    111111111,222222222,333333333,444444444,555555555,666666666,777777777,888888888,999999999,
};


int main() {
	int t; cin>>t;
	
	while(t--){
        ll n; cin>>n;
        cout<<upper_bound(v.begin(), v.end(), n)-v.begin()<<endl;
	}
	
	return 0;
}
*/
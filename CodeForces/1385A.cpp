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
#define cn cout << "\n"
#define cy cout << "YES"
#define cno cout << "NO"
#define re return
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

/**
 * x= max(a,b)
 * y= max(b,c)
 * z= max(a,c)
 * 
 * Thus if a is max
 * x=a, y=max(b,c)<=a=x, z=a
 * 
 * Similarly if b is max
 * x=b, y=b, z=max(a,c)<=b=x
 * 
 * if c is max
 * x=max(a,b)<=c=y, y=c, z=c
 **/

void solve()
{
    ll num[2];
    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    if (num[1] == num[2])
    {
        cy; //YES
        cn;
        if (num[0] == num[1])
            cout << num[0] << " " << num[0] << " " << num[0];
        //as all equal
        else
            cout << 1 << " " << num[0] << " " << num[2];
        // the smaller number differs from 2 larger that are equal
    }
    else
        cno; //NO
    re;
}

int main()
{
    fast_io();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cn;
    }
    re 0;
}

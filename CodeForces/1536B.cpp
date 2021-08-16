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

    set<string> ourset;
    ll n;
    cin >> n;
    string str, st;
    cin >> str;
    ll flag = 0;

    // one char
    fo(i, n)
    {
        st = "";
        st += str[i];
        ourset.insert(st);
    }

    // two char
    fo(i, n - 1)
    {
        st = "";
        st += str[i];
        st += str[i + 1];
        ourset.insert(st);
    }

    //three char
    fo(i, n - 2)
    {
        st = "";
        st += str[i];
        st += str[i + 1];
        st += str[i + 2];
        ourset.insert(st);
    }

    //one char
    for (char i = 'a'; i <= 'z'; i++)
    {
        st = "";
        st += i;
        if (!ourset.count(st) > 0)
        {
            cout << st << endl;
            flag = 1;
            return;
        }
    }

    //two char
    for (char i = 'a'; i <= 'z'; i++)
    {
        st = "";
        st += i;
        for (char j = 'a'; j <= 'z'; j++)
        {
            string st1 = st;
            st1 += j;
            if (!ourset.count(st1) > 0)
            {
                cout << st1 << endl;
                flag = 1;
                return;
            }
        }
    }

    //three char
    for (char i = 'a'; i <= 'z'; i++)
    {
        st = "";
        st += i;
        for (char j = 'a'; j <= 'z'; j++)
        {
            string st1 = st;
            st1 += j;
            for (char k = 'a'; k <= 'z'; k++)
            {
                string st2 = st1;
                st2 += k;
                if (!ourset.count(st2) > 0)
                {
                    cout << st2 << endl;
                    flag = 1;
                    return;
                }
            }
        }
    }

    return;
}

/*
Make a set, insert elements separately,  then 2 at a time thn 3 at a time,
Chck lexographically in set .
First chck a to z, then aa to zz, thn aaa to zzz.. 
Print the first element which was not in our set.
*/

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
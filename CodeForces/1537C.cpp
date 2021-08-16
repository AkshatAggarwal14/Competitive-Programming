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
    ll n;
    cin >> n;
    ll arr[n], brr[n];
    fo(i, n)
    {
        cin >> arr[i];
        brr[i] = arr[i];
    }

    sort(brr, brr + n, greater<ll>());
    //find the largest numbers with minimum difference
    //1 2 3 3 4 5 6 6
    //6 1 2 3 3 4 5 6 <- difficulty = 6
    //3 4 5 6 6 1 2 3 <- difficulty = 5

    //1 2 3 4 5 6 9
    //6 1 2 3 4 5 9 <- difficulty = 6
    ll mindiff = INT_MAX, minindex;
    for (ll i = 1; i < n; i++)
    {
        ll diff = brr[i - 1] - brr[i];
        if (diff < mindiff)
        {
            mindiff = diff;
            minindex = i;
        }
    }
    // deb2(brr[minindex - 1], brr[minindex]);
    //todo: brr[minindex] is first element, brr[minindex-1] is last element
    // cout << minindex; //so elements with mindiff and largest are brr[minindex-1] && brr[minindex]
    sort(arr, arr + n);

    //todo: first element
    cout << brr[minindex] << " ";

    ll countbrrminindex = count(arr, arr + n, brr[minindex]), countbrrminindex1 = count(arr, arr + n, brr[minindex - 1]);

    if (brr[minindex] == brr[minindex - 1])
        countbrrminindex -= 2;
    else
        countbrrminindex -= 1, countbrrminindex1 -= 1;

    //todo: remaining elements equal to brr[minidex]
    while (countbrrminindex--)
        cout << brr[minindex] << " ";

    //todo: now for all increasing elements
    fo(i, n)
    {
        if (arr[i] > brr[minindex] && arr[i] != brr[minindex - 1])
            cout << arr[i] << " ";
    }

    //todo: now elements from 1 to brr[minindex]
    fo(i, n)
    {
        if (arr[i] < brr[minindex])
            cout << arr[i] << " ";
    }

    //todo: now elements that are equal to last element
    if (brr[minindex] != brr[minindex - 1])
    {
        while (countbrrminindex1--)
            cout << brr[minindex - 1] << " ";
    }

    //todo: last element
    cout << brr[minindex - 1];
    re;
}

int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    clock_t start, end;
    start = clock();

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cn;
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "Time taken:" << ln << ps(time_taken, 6) << " sec\n";
    re 0;
}
/*
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,0,n){
        cin >> h[i];
    }
    sort(all(h));

    int mn = INF;

    int pos;

    rep(i,1,n){
        amin(mn,h[i] - h[i-1]);
        if(h[i] - h[i-1] == mn) pos = i;
    }

    vector<int> ans;
    ans.pb(h[pos-1]);
    rep(i,pos+1,n){
        if(i == pos || i == pos - 1) continue;
        ans.pb(h[i]);
    }
    rep(i,0,pos){
        if(i == pos || i == pos - 1) continue;
        ans.pb(h[i]);
    }
    ans.pb(h[pos]);
    for(int x:ans){
        cout << x << " ";
    }
    */
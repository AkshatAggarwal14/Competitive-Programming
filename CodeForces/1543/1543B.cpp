//**********************master._.mind**********************
//-----------------Author: Akshat Aggarwal-----------------
//If you don't understand the code below... dont worry, i didn't either
#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll> vl;

//* Global vars
ll n;

void solve() {
    //*********************CODE STARTS HERE*********************

    cin >> n;
    vl arr(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];
    ll n1 = sum % n;  //number of 1s left without a place
    cout << n1 * (n - n1) << '\n';

    //**********************CODE ENDS HERE**********************
    return;
}  //todo solve

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    ll tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}  //todo main

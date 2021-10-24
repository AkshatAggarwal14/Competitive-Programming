#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    ll n, ans, half;
    cin >> n;
    if (n % 2 != 0) //IF odd then answer = 0
    {
        cout << 0 << "\n";
        return;
    }
    half = n / 2;                              //else we divide it by 2 and find all possible pairs as sides of rectangle
    cout << half / 2 - (half + 1) % 2 << "\n"; //make cases and then try to understand this
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, ans, half;
    cin >> n;
    if (n % 2 != 0) //IF odd then answer = 0
    {
        cout << 0 << "\n";
        return 0;
    }
    half = n / 2;                              //else we divide it by 2 and find all possible pairs as sides of rectangle
    cout << half / 2 - (half + 1) % 2 << "\n"; //make cases and then try to understand this
    return 0;
}
*/
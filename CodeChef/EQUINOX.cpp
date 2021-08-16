//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll N, A, B, p1 = 0, p2 = 0;
    cin >> N >> A >> B;
    char s[100][N];
    for (ll i = 0; i < N; i++)
    {
        cin >> s[i];
        char c = s[i][0];
        // cout << c << "\nHello\n";
        if (c == 'E' || c == 'Q' || c == 'U' || c == 'I' || c == 'N' || c == 'O' || c == 'X')
            p1 += A;
        else
            p2 += B;
    }
    if (N >= 1 && N <= 100 && A >= 1 && A <= 1e9 && B >= 1 && B <= 1e9)
    {
        if (p1 > p2)
            cout << "SARTHAK\n";
        else if (p1 < p2)
            cout << "ANURADHA\n";
        else if (p1 == p2)
            cout << "DRAW\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    if (t >= 1 && t <= 100)
        while (t--)
            solve();
    return 0;
}
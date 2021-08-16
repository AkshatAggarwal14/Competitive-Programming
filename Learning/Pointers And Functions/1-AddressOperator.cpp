#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define repn(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve()
{
    int x = 10;
    cout << &x << endl;

    float y = 10.5;
    cout << &y << endl;

    char ch = 'A';
    cout << &ch << endl; // character variables get printed (NOT ADDRESS)
    //! This is Explicit typecasting from char*(by default) to void* <-- we dont know the data type now
    cout << (void *)&ch << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
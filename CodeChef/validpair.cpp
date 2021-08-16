#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= 1 && a <= 10 && b >= 1 && b <= 10 && c >= 1 && c <= 10)
    {
        if (a == b == c || a == b || b == c || a == c)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    float t, L;
    int n, p, q;
    cin >> p;
    cin >> q;
    t = log(p * 60) - log(60);
    L = (25 * t) / q;
    n = L + 1;
    if (abs(L - n) < 0.0000000005)
        n = n - 1;
    cout << n << endl;
    return 0;
}
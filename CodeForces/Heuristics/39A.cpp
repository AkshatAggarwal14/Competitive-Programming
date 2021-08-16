#include <iostream>
using namespace std;

int main()
{
    long int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, ans;
        cin >> n >> m;
        ans = (n % m == 0) ? (n / m) : (n / m + 1);
        cout << ans << "\n";
    }
    return 0;
}
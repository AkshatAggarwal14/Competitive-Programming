//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    if (t % 2 == 0 && t != 2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
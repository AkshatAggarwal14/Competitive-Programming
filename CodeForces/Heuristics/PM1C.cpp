#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int t, m;
    cin >> t;
    m = t;
    ll a[t];
    for (ll i = 0; i < t; i++)
    {
        cin >> a[i];
        a[i] = (a[i] - 1) / 2;
    }
    for (ll i = 0; i < m; i++)
    {
        cout << a[i] << endl;
    }
    /**int t;
    cin >> t;
    while(t--){
        ll x;
        cin>>x;
        cout<<(x-1)/2<<endl;
    }*/
    return 0;
}
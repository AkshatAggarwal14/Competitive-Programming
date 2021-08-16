//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repeq(i, a, b) for (ll i = a; i <= b; i++)
#define repn(i, n) for (ll i = 0; i < n; i++)

typedef long long ll;

void rvereseArray(ll arr[], ll start, ll end)
{
    ll temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void solve()
{
    ll g, p;
    cin >> g >> p;
    vector<ll> x(10, 0);
    for (ll i = 0; i < 10; i++)
        cin >> x[i];

    ll dayMin = 1;
    ll dayMax = 1;
    ll num = p;

    ll sum = 0;
    for (ll j = 9; j >= 0; j--)
    {
        if (j + 1 != g)
            sum += x[j];
        else
        {
            ll days = sum / p;
            ll left = sum % p;
            dayMin = days + 1;
            if (left == 0)
            {
                if (p >= x[j])
                {
                    dayMax = dayMin;
                    break;
                }
                else
                {
                    ll leftPop;
                    leftPop = x[j] - (p);
                    dayMax = dayMin + leftPop / p;
                    if (leftPop % p)
                        dayMax++;
                }
            }
            else
            {
                ll leftPop;
                if (x[j] > p - left)
                    leftPop = x[j] - (p - left);
                else
                {
                    dayMax = dayMin;
                    break;
                }

                dayMax = dayMin + leftPop / p;
                if (leftPop % p)
                    dayMax++;
            }
            break;
        }
    }

    cout << dayMin << " " << dayMax << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
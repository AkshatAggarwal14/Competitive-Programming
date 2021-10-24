//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(ll *a, ll *b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void segregateEvenOdd(ll arr[], ll size)
{
    ll left = 0, right = size - 1;
    while (left < right)
    {
        /* Increment left index while we see 0 at left */
        while (arr[left] % 2 == 0 && left < right)
            left++;

        /* Decrement right index while we see 1 at right */
        while (arr[right] % 2 == 1 && left < right)
            right--;

        if (left < right)
        {
            /* Swap arr[left] and arr[right]*/
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    segregateEvenOdd(arr, n);

    for (ll i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << "\n";
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
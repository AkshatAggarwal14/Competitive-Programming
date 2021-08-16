#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    ll freq[k] = {0};
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i];
        freq[arr[i] % k]++; //counting remainders which will nC2 to give number of pairs
    }
    ll sum = 0;
    for (ll i = 0; i < k; ++i)
        if (freq[i] != 0)
            sum += freq[i] * (freq[i] - 1); //2 * nC2
    cout << sum;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;ll ll;
ll main()
{
    ll n, k, i, j;
    cin >> n >> k;
    ll arr[n], ans = 0, count;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] %= k;
    }
    unordered_map<ll, ll> mp;
    for (i = 0; i < n; i++)
        mp[arr[i]]++;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        count = it->second;
        ans += (count * (count - 1)) / 2;
    }
    cout << 2 * ans;
}
*/

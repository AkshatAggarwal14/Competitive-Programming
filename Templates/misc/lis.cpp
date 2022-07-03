ll LIS(vector<ll> &arr) {
    vector<ll> dp;
    ll n = ll(arr.size());
    for (ll i = 0; i < n; i++) {
        // upper_bound for Longest Non Decreasing Subsequence
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) {
            dp.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }
    return ll(dp.size());
}

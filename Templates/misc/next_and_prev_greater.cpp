vector<ll> next_greater(vector<ll> &a) {
    ll n = ll(a.size());
    vector<ll> res(n, n);
    stack<ll> stk;
    for (ll i = n - 1; i >= 0; --i) {
        while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
        if (!stk.empty()) res[i] = stk.top();
        stk.push(i);
    }
    return res;
}

vector<ll> prev_greater(vector<ll> &a) {
    ll n = ll(a.size());
    vector<ll> res(n, -1);
    stack<ll> stk;
    for (ll i = 0; i < n; ++i) {
        while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
        if (!stk.empty()) res[i] = stk.top();
        stk.push(i);
    }
    return res;
}
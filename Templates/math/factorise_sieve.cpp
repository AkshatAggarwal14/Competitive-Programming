const ll MAXN = 1e14;
const ll N = ll(sqrt(MAXN)) + 10;
vector<ll> spf(N + 1);
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) spf[i] = i, pr.push_back(i);
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

// as sieve can run upto 1e7 easily in 1 sec, we can factorise upto 1e14
vector<ll> factorise(const ll &n) {
    vector<ll> res;
    ll temp = n;
    // if element is greater than current prime then break
    for (ll i = 0; i < ll(pr.size()); ++i) {
        if (temp < pr[i]) break;
        while (temp % pr[i] == 0) {
            res.push_back(pr[i]);
            temp /= pr[i];
        }
    }
    if (temp > 1) res.push_back(temp);
    return res;
}

vector<pair<ll, ll>> factorise_pair(const ll &n) {
    vector<pair<ll, ll>> C;
    ll temp = n, cnt = 0;
    // if element is greater than current prime then break
    for (ll i = 0; i < ll(pr.size()); ++i) {
        cnt = 0;
        if (temp < pr[i]) break;
        while (temp % pr[i] == 0) {
            cnt++;
            temp /= pr[i];
        }
        if (cnt) C.push_back({pr[i], cnt});
    }
    if (temp > 1) C.push_back({temp, 1});
    return C;
}

/*
n = (p1 ** a1) * (p2 ** a2) ..
count_of_divisors = (a1 + 1) * (a2 + 1)..
sum_of_divisors = (1 + p1 + p1^2 + p1^3.. ) * ( ... ) ...
                = (p1^(a1 + 1) - 1)/(p1 - 1) ...
*/

// Returns the number of divisors of n
ll count_of_divisors(const ll &n) {
    vector<pair<ll, ll>> C = factorise_pair(n);
    ll P = 1;
    for (auto &[x, y] : C) P *= (y + 1);
    return P;
}

// Returns the sum of divisors of n
ll sum_of_divisors(const ll &n) {
    vector<pair<ll, ll>> C = factorise_pair(n);
    ll P = 1;
    for (auto &[x, y] : C) {
        ll t = 1, cnt = y + 1;
        while (cnt--) t *= x;
        P *= ((t - 1) / (x - 1));
    }
    return P;
}

// O(1) if n <= N and O(sz(pr)) if n >= N && n <= MAXN
bool isPrime(const ll &n) {
    assert(n <= MAXN);
    if (n <= N) return (spf[n] == n);
    if (binary_search(pr.begin(), pr.end(), n)) return true;
    for (ll i = 0; i < ll(pr.size()); ++i)
        if (n % pr[i] == 0) return false;
    return true;
}

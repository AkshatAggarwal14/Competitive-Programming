#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_CH = 26;

bool checkCorrectOrNot(string s)
{
    ll count1[MAX_CH] = {0}, count2[MAX_CH] = {0};
    ll n = s.length();
    if (n == 1)
        return true;

    for (ll i = 0, j = n - 1; i < j; i++, j--)
    {
        count1[s[i] - 'a']++;
        count2[s[j] - 'a']++;
    }

    for (ll i = 0; i < MAX_CH; i++)
        if (count1[i] != count2[i])
            return false;

    return true;
}

int main()
{
    ll n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (checkCorrectOrNot(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

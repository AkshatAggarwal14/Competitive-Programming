//*use cout<<"\n" instead of endl as endl is slower
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int s1 = s[1] + s[0] - '1' - '1';
    int s2 = s[3] + s[4] - '1' - '1';
    int s3 = s[5] + s[4] - '1' - '1';
    int s4 = s[7] + s[8] - '1' - '1';
    if (s1 % 2 == 0 && s2 % 2 == 0 && s3 % 2 == 0 && s4 % 2 == 0 && s[2] != 'A' && s[2] != 'E' && s[2] != 'I' && s[2] != 'O' && s[2] != 'U' && s[2] != 'Y')
        cout << "valid";
    else
        cout << "invalid";
    return 0;
}
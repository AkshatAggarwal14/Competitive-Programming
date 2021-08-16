#include <iostream>
using namespace std;
typedef long long ll;
//check if number or string
bool check_number(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
int main()
{
    string s;
    cin >> s;
    if (check_number(s) == false)
        cout << "Illegal ISBN";
    else
    {
        ll len = s.length();
        if (len != 10)
            cout << "Illegal ISBN";
        else
        {
            ll sum = 0;
            for (int i = 0; i < 10; i++)
            {
                sum += (i + 1) * (s[i] - '1');
            }
            if (sum % 11 == 0)
            {
                cout << "Legal ISBN";
            }
            else
            {
                cout << "Illegal ISBN";
            }
        }
    }
    return 0;
}
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    string s;
    int ctr, t, s_len, c[1000];
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> s_len;
        cin >> s;
        ctr = 0;
        if (s_len == s.length())
        {
            for (int i = 0; i < s.length(); i++)
                for (int j = i; j < s.length(); j++)
                    for (int k = 0; k <= 4; k++)
                        if (s.substr(i, k) + s.substr(j, 4 - k) == "love")
                        {
                            if (s.substr(i + k, j - i - k).length() + 4 == s.length())
                            {
                                ctr++;
                            }
                        }

            if (ctr != 0)
                c[q] = 1;
            else
                c[q] = 0;
        }
    }
    for (int q = 0; q < t; q++)
    {
        if (c[q] == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
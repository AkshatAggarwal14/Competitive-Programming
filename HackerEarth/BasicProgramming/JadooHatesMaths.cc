#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int num = stoi(s);
    while (num++)
    {
        if (num % 3 == 0 || to_string(num).find('3') < to_string(num).length())
            continue;
        else
            break;
    }
    cout << num;
    return 0;
}
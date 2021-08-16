#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (; n; n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a = a + b + c;
        if (a >= 2)
        {
            sum++;
        }
    }
    cout << sum;
}
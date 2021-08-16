#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll a[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    for (int i = 2; i >= 0; i--)
    {
        cout << a[3] - a[i] << " ";
    }
    return 0;
}
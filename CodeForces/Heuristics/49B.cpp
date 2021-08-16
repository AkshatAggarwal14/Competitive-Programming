#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        cout << sum / (i + 1) << " ";
    }
    return 0;
}
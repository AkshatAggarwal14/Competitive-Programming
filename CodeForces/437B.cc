#include <iostream>
using namespace std;

int main()
{
    int sum, limit, x, i = 0;

    cin >> sum >> limit;
    int arr[limit];
    while (sum != 0 && limit != 0)
    {
        x = ((-limit) & limit);
        if (sum >= x)
        {
            arr[i] = limit;
            i++;
            sum = sum - x;
        }
        limit--;
    }
    if (sum > 0)
        cout << -1;
    else
    {
        cout << i << endl;
        for (int j = 0; j < i; j++)
            cout << arr[j] << " ";
    }
    return 0;
}
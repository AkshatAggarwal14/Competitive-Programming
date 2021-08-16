#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, x = 0, y = 0, z = 0;
    string n;
    cin >> t;
    int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        string ans = "";
        int total = 0;
        for (int j = n.length(); j > 0; j--)
        {
            int z = n[j - 1] - '0';
            total += arr[z]; //finding total number of matches in the goven number
        }
        for (x = 0;; x++)
            if ((total - 3 * x) % 2 == 0) //as 3x matches are used to make x sevens
                break;
        int left = (total - 3 * x) / 2; //matches used to make 1s
        while (x--)
            ans.append("7");
        while (left--)
            ans.append("1");
        cout << ans << endl;
    }
}
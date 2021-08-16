// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string magicalString(string S)
    {
        char lower_case[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        string ans = "";
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] >= 'a' && S[i] <= 'z')
                ans += lower_case[S[i] - 97];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.magicalString(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
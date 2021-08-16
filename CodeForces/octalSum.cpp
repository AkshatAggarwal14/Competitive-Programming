#include <iostream>
using namespace std;
#define abs(x) ((x) > 0 ? (x) : -(x))

int main() {
    cout << "Enter base of numbers (2-10): ";
    int base;
    cin >> base;
    cout << "Enter the two numbers: ";
    string s1, s2;
    cin >> s1 >> s2;

    string temp((int)abs(s1.size() - s2.size()), '0');
    if (s1.size() > s2.size())
        s2 = temp + s2;
    else if (s1.size() < s2.size())
        s1 = temp + s1;
    int sum = 0, carry = 0;
    int n = s1.size();
    string ans = "";
    for (int i = n - 1; i >= 0; i--) {
        sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        if (sum >= base) {
            carry = 1;
        } else {
            carry = 0;
        }
        ans = to_string(sum % base) + ans;
    }
    if (carry == 1)
        ans = "1" + ans;
    cout << "Sum of " << s1 << " and " << s2 << " in base " << base << " is " << ans;

    return 0;
}
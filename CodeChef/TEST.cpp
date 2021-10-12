#include <iostream>
using namespace std;

int main() {
    while (true) {
        int t;
        if (t == 42) {
            cin >> t;
            break;
        }
        cin >> t;
        if (t == 42)
            continue;
        cout << t << "\n";
    }
    return 0;
}
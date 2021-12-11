#include <bits/stdc++.h>
using namespace std;

int main() {
    // A pair container is a simple container consisting of two data elements or objects.
    // Pair is used to combine together two values which may be different in type. Pair provides a way to store two heterogeneous objects as a single unit.
    // To access the elements, we use variable name followed by dot operator followed by the keyword first or second.

    pair<int, double> p1(1, 0.5), p2;
    p2 = make_pair(1, 0.4);
    cout << p2.first << ' ' << p2.second;
    return 0;
}
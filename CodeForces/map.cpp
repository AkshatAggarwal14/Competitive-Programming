#include <bits/stdc++.h>
using namespace std;

int main() {
    // Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value.

    map<int, string> mp;  //? declare map
    // {key, value} pair, and all keys are unique
    // The objects in a map are of type ‘pair’ by default in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.

    //? insert in map
    mp.insert(make_pair(1, "one"));  // {{1, "one"}}
    mp[2] = "two";
    mp[3] = "three";

    //? erase
    mp.erase(2);

    //? printing map
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << (*itr).first << ": " << (*itr).second << '\n';
    }
    cout << '\n';
    return 0;
}
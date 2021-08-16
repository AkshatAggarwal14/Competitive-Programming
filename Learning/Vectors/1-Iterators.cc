// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";

    cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";

    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << " ";

    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << " ";

    return 0;
}
/* begin() returns an iterator to beginning while cbegin() returns a const_iterator to beginning.

*    The basic difference between these two is
*    iterator(i.e begin()) lets you change the value of the object it is pointing to and const_iterator will not let you change the value of the object.

*    For example :

*    This IS allowed.The vector values change to{0, 10, 20, 30, 40} :

*    vector<int> v{10, 20, 30, 40, 50};
*vector<int>::iterator it;

*for (it = v.begin(); it != v.end(); it++)
{
    *it = *it - 10; //!Here *it is a pointer
}
*This is NOT allowed.It will throw an error :

    for (it = v.cbegin(); it != v.cend(); it++)
{
    *it = *it - 10;
}
*/
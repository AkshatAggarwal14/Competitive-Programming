// C++ program to illustrate the
// capacity function in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Size : " << g1.size();
    cout << "\nCapacity : " << g1.capacity();
    cout << "\nMax_Size : " << g1.max_size();

    // resizes the vector size to 4
    g1.resize(4);

    // prints the vector size after resize()
    cout << "\nSize : " << g1.size();

    // checks if the vector is empty or not
    if (g1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    // Shrinks the vector
    g1.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";

    return 0;
}
/*
Size is number of elements present in a vector

Capacity is the amount of space that the vector is currently using.

Let's understand it with a very simple example:

using namespace std;

int main(){
  vector<int > vec;
  vec.push_back(1); 
  vec.push_back(1); 
  vec.push_back(1); 
  cout<<"size of vector"<<vec.size()<<endl;
  cout<<"capacity of vector"<<vec.capacity()<<endl;
  return 0;
}
currently size is 3 and capacity is 4.

Now if we push back one more element,

using namespace std;
  int main(){
  vector<int> vec;
  vec.push_back(1); 
  vec.push_back(1); 
  vec.push_back(1); 
  vec.push_back(1);
  cout<<"size of vector"<<vec.size()<<endl;
  cout<<"capacity of vector"<<vec.capacity()<<endl;
  return 0;
}
now size is: 4 capacity is 4

now if we try to insert one more element in vector then size will become 5 but capacity will become 8.

it happens based on the datatype of vector, as here in this case vector in of type int, as we know size of int is 4 bytes so compiler will allocate 4 block of memory ..and when we try to add 5th element , vector::capacity() is doubled what we have currently.

same keep on..for example : if we try to insert 9th element then size of vector will be 9 and capacity will b 16..
*/
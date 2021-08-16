#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// splits a std::string into vector<string> at a delimiter
vector<string> split(string x, char delim = ' ')
{
    x += delim; //includes a delimiter at the end so last word is also read
    vector<string> splitted;
    string temp = "";
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == delim)
        {
            splitted.push_back(temp); //store words in "splitted" vector
            temp = "";
            i++;
        }
        temp += x[i];
    }
    return splitted;
}

// checks if a string is capitalized
bool isCapitalized(string x)
{
    return isupper(x[0]);
}

// capitalizes a string
string capitalize(string x)
{
    x[0] = toupper(x[0]);
    return x;
}

// lowercases a whole string
string lowercase(string x)
{
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    return x;
}

// reverses a collection. [T] should be iterable.
template <typename T>
T reverse(T x)
{
    reverse(x.begin(), x.end());
    return x;
}

int main()
{
    string raw;
    getline(cin, raw);
    vector<string> words = reverse(split(raw));
    for (string word : words)
    {
        string outputWord = reverse(lowercase(word));
        if (isCapitalized(word))
            outputWord = capitalize(outputWord);
        cout << outputWord << ' ';
    }
    return 0;
}
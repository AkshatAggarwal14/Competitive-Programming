#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
using namespace std;

int main() {
    // Create and open a text file
    ofstream file_ptr_name("filename.txt");
    ofstream gg("gg.txt");
    // just open
    ifstream fin("inp.txt");

    file_ptr_name << "Files can be tricky, but it is fun enough!";
    gg << "1\n";
    int n;
    fin >> n;

    gg << n;

    gg.close();
    fin.close();

    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Done...";
}
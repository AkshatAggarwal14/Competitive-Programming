#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// your code goes here
	int withdraw;
	float balance;
	cin >> withdraw >> balance;
	if((withdraw%5==0) && (balance>=(withdraw+0.5))) {
	    balance -= (withdraw + 0.5);
	}

    cout <<fixed<< setprecision(2) << balance << endl;

	return 0;
}
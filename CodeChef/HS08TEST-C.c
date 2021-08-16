#include <stdio.h>

int main()
{
	// your code goes here
	int withdraw;
	float balance;
	scanf("%d%f", &withdraw, &balance);
	if ((withdraw % 5 == 0) && (balance >= (withdraw + 0.5)))
	{
		balance -= (withdraw + 0.5);
	}
	char s[20];
	sprintf(s, "%.2f", balance);
	sscanf(s, "%f", &balance);
	printf("%.2f", balance);
	return 0;
}
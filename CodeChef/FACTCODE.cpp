#include <stdio.h>
int main()

{
    int num, fact = 1, temp;
    scanf("%d", &num);
    temp = num;
    while (temp != 0) {
        fact = fact * temp;
        --temp;
    }
    printf("%d", fact);
    return 0;
}
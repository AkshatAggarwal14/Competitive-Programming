#include <stdio.h>
int main() {
    char firstname[20], lastname[20];
    int birthyear;
    scanf("%s", firstname);
    scanf("%s", lastname);
    scanf("%d", &birthyear);
    printf("Your name is %s %s and you are born in the year %d\n", firstname, lastname, birthyear);
    return 0;
}
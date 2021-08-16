#include <stdio.h>
int main(void)
{
    double a, b, c;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    printf("%d", a + b - c < 1e-9 && a + b - c > -1e-9);

    return 0;
}
#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter m: ");
    scanf("%d", &m);
    if (m > n)
    {
        printf("Cannot reverse %d numbers when array is only of %d numbers. Try Again.", m, n);
        return 0;
    }
    int *arr = new int[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("arr[%d] = ", i);
        scanf("%d", (arr + i));
    }
    printf("Array after reversing first %d values: ", m);
    for (int i = m - 1; i >= 0; --i)
        printf("%d ", *(arr + i));
    for (int i = m; i < n; ++i)
        printf("%d ", *(arr + i));
    return 0;
}
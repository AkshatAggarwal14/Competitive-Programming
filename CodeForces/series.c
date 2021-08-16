//series= x - x^3/3! + x^5/5! +... 
#include<stdio.h>

double SeriesSum(int x,int n){
    double sum = x;
    double term = x;

    for(int i=1;i<n;i++){
        term *= (-1) * (x) * (x) / (double)((2 * i) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

int main(){
    int x;
    printf("Enter number (x): ");
    scanf("%d", &x);
    int n;
    printf("Enter number of terms (n): ");
    scanf("%d", &n);
    printf("Sum of series x-x^3/3!+x^5/5!+.. upto n terms is: %.5lf",SeriesSum(x,n));
    return 0;
}
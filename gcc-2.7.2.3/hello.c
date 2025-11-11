#include<stdio.h>

int main(){
    int a, b;
    int add;  // Move this declaration up
    printf("Enter Both Numbers ");
    scanf("%d %d", &a, &b);
    add = a + b;
    printf("Sum : %d", add);
    return 0;
}


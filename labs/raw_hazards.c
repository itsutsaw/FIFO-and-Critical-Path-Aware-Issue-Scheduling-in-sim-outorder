#include <stdio.h>

#define N 200000

volatile int A[N];   // volatile prevents over-optimization

int main() {
    int i;       // declare loop variables here
    int acc = 0;
    int sum = 0;
    int x;

    // Initialize array
    for (i = 0; i < N; i++) {
        A[i] = i;
    }

    // 1) Dependent ALU chain (RAW hazards)
    for (i = 0; i < N; i++) {
        acc = acc + 1;
        acc = acc + 2;
        acc = acc + 3;
    }

    // 2) Load → use hazard
    for (i = 0; i < N; i++) {
        x = A[i];   // load
        sum += x;   // immediate use → RAW hazard
    }

    printf("acc=%d sum=%d\n", acc, sum);
    return 0;
}


#include <stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) return 0ULL;
    unsigned long long acc = 1ULL;
    while (n > 1) {
        acc = acc * (unsigned long long)n;
        n = n -1;
    }
    return acc;
}

int main(void) {
    int n;
    printf("Ingrese un enetro n >= 0: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    if (n < 0) {
        fprintf(stderr, "n debe ser >= 0.\n");
        return 1;
    }
    unsigned long long f = factorial(n);
    printf("%d! = %llu\n", n, f);
    return 0;
}
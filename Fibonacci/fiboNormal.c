#include <stdio.h>


long long fib_recursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_recursivo(n - 1) + fib_recursivo(n - 2);
}


int main() {
    int n = 40;
    printf("Fibonacci(%d) = %lld\n", n, fib_recursivo(n));
    return 0;
}
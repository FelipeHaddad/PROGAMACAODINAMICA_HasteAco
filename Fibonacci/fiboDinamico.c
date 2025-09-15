#include <stdio.h>
#include <stdlib.h> // Para malloc
#include <string.h> // Para memset

// Nosso array "cache" para guardar os resultados
long long memo[100]; // Usando um array global para simplificar

long long fib_dinamico(int n) {
    // 2. Consultar o cache: Se o valor já foi calculado, retorne-o.
    if (memo[n] != -1) {
        return memo[n];
    }

    // Se n for um caso base, armazene e retorne.
    if (n <= 1) {
        memo[n] = n;
        return n;
    }

    // 3. Calcular e armazenar o resultado no cache antes de retornar.
    memo[n] = fib_dinamico(n - 1) + fib_dinamico(n - 2);
    
    return memo[n];
}

int main() {
    int n = 40;

    // 1. Inicializar o cache com -1 (indicando "não calculado")
    memset(memo, -1, sizeof(memo));

    printf("Fibonacci(%d) = %lld\n", n, fib_dinamico(n));
    return 0;
}
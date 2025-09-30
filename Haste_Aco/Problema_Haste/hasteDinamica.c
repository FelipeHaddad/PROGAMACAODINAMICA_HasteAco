#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int corteHasteRecursivo(int preco[], int n) {
    if(memo[n-1] != -1){
        return memo[n-1];
    }

    if (n == 1) {memo[n-1] = preco[0]; return memo[n-1];}

    int valorMax = preco[n - 1];

    for (int i = 1; i < n; i++) {
        int valor = corteHasteRecursivo(preco, i) + corteHasteRecursivo(preco, n - i);
        if (valor > valorMax) {
            valorMax = valor;
        }
    }
    memo[n - 1] = valorMax;
    return valorMax;

}

int main() {
    int preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 7;

    memset(memo,-1,100)

    int resultado = corteHasteRecursivo(preco, n);

    printf("\nValor maximo obtido com a haste de comprimento %d = %d\n", n, resultado);

    return 0;
}
#include <stdio.h>
#include <stdlib.h> // Para malloc
#include <string.h> // Para memset
#include <limits.h>

int memo[9];

int corteHasteDinamico(int preco[], int n) {
    if (memo[n - 1] != -1) {
        return memo[n-1];
    }

    if (n == 1) { memo[0] = 1; return preco[0];}

    int valorMax = preco[n - 1];

    for (int i = 1; i < n; i++) {
        int valor = corteHasteDinamico(preco, i) + corteHasteDinamico(preco, n - i);
        printf("Valor calculado: %d\n", valor);
        if (valor > valorMax) {
            valorMax = valor;
        }
    }
    memo[n-1] = valorMax;
    return valorMax;

}

int main() {
    int preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n;

    memset(memo, -1, sizeof(memo));

    do {
        printf("Digite o tamanho da haste (1 a 10): ");
        scanf("%d", &n);

        if (n < 1 || n > 10) {
            printf("Valor invalido! O tamanho deve estar entre 1 e 10.\n");
        }
    } while (n < 1 || n > 10);

    int resultado = corteHasteDinamico(preco, n);

    for (int i = 0; i <= 10; i++){
        printf("\nMemo[%d] = %d", i, memo[i]);
    }

    printf("\nValor maximo obtido com a haste de comprimento %d = %d\n", n, resultado);

    return 0;
}
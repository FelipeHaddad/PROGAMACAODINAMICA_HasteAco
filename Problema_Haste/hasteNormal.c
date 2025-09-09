#include <stdio.h>
#include <limits.h>

int corteHasteRecursivo(int preco[], int n) {
    if (n == 0) return 0;

    int max_valor = INT_MIN;

    for (int i = 1; i <= n; i++) {
        int valor = preco[i - 1] + corteHasteRecursivo(preco, n - i);
        if (valor > max_valor) {
            max_valor = valor;
        }
    }

    return max_valor;
}

int main() {
    int preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n;

    do {
        printf("Digite o tamanho da haste (1 a 10): ");
        scanf("%d", &n);

        if (n < 1 || n > 10) {
            printf("Valor invalido! O tamanho deve estar entre 1 e 10.\n");
        }
    } while (n < 1 || n > 10);

    int resultado = corteHasteRecursivo(preco, n);

    printf("\nValor maximo obtido com a haste de comprimento %d = %d\n", n, resultado);

    return 0;
}

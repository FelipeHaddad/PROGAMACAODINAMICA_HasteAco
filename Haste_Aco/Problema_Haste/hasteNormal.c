#include <stdio.h>
#include <limits.h>

int corteHasteRecursivo(int preco[], int n) {
    printf("Chamada do valor %d\n", n);
    if (n == 1) { printf("Valor Maximo: %d\n", preco[0]); return preco[0];}

    int valorMax = preco[n - 1];
    printf("Valor Maximo: %d\n", valorMax);

    for (int i = 1; i < n; i++) {
        int valor = corteHasteRecursivo(preco, i) + corteHasteRecursivo(preco, n - i);
        printf("Valor calculado: %d\n", valor);
        if (valor > valorMax) {
            valorMax = valor;
        }
    }
    return valorMax;

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
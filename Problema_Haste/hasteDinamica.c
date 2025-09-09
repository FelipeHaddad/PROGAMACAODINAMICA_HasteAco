#include <stdio.h>
#include <limits.h>

int corteHaste(int preco[], int n, int memo[], int corteEscolhido[]) {
    if (n == 0) return 0;

    if (memo[n] >= 0) return memo[n];

    int max_valor = INT_MIN;
    int melhorCorte = 0;

    for (int i = 1; i <= n; i++) {
        int valor = preco[i - 1] + corteHaste(preco, n - i, memo, corteEscolhido);
        if (valor > max_valor) {
            max_valor = valor;
            melhorCorte = i;
        }
    }

    memo[n] = max_valor;
    corteEscolhido[n] = melhorCorte;
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

    int memo[n + 1];
    int corteEscolhido[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
        corteEscolhido[i] = 0;
    }

    int resultado = corteHaste(preco, n, memo, corteEscolhido);

    printf("\nValor maximo obtido com a haste de comprimento %d = %d\n", n, resultado);

    int restante = n;
    int contagem[n + 1];
    for (int i = 0; i <= n; i++) contagem[i] = 0;

    printf("Cortes realizados: ");
    while (restante > 0) {
        int corte = corteEscolhido[restante];
        printf("%d ", corte);
        contagem[corte]++;
        restante -= corte;
    }

    printf("\n\nResumo dos cortes:\n");
    for (int i = 1; i <= n; i++) {
        if (contagem[i] > 0) {
            printf("Tamanho %d -> %d pecas\n", i, contagem[i]);
        }
    }

    return 0;
}

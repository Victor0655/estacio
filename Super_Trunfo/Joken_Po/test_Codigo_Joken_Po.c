#include <stdio.h>
#include <string.h>

int pertenceACadeia(const char *str, const char *cadeia[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(str, cadeia[i]) == 0) {
            return 1; // A string pertence à cadeia
        }
    }
    return 0; // A string não pertence à cadeia
}

int main() {
    const char *cadeia[] = {"pedra", "papel", "tesoura"};
    int tamanho = sizeof(cadeia) / sizeof(cadeia[0]);

    char entrada[50];
    printf("Digite uma string: ");
    scanf("%49s", entrada);

    if (pertenceACadeia(entrada, cadeia, tamanho)) {
        printf("A string '%s' pertence à cadeia.\n", entrada);
    } else {
        printf("A string '%s' não pertence à cadeia.\n", entrada);
    }

    return 0;
}
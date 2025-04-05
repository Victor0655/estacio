#include <stdio.h>

int main() {
    printf("Bem-vindo ao jogo de calcular\n");
    printf("Escolha uma operação:\n1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n");
    printf("Digite sua escolha: ");
    int operacao;
    scanf("%d", &operacao);
    if (operacao < 1 || operacao > 4) {
        printf("Operação inválida\n");
        return 0;
    }
    printf("Digite o primeiro número: ");
    float num1;
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    float num2;
    scanf("%f", &num2);
    float resultado;
    switch (operacao) {
        case 1:
            resultado = num1 + num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 4:
            if (num2 == 0) {
                printf("Divisão por zero não é permitida\n");
                return 0;
            }
            resultado = num1 / num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 5:
            resultado = num1 * num1;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 6:
            resultado = num1 / num1;
            printf("Resultado: %.2f\n", resultado);
            break;
        default:
            printf("Operação inválida\n");
            return 0;


    }
    printf("Deseja continuar jogando? (sim/não): ");
}
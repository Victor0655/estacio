#include <stdio.h>

int main() {
    char nome_cidade_1[30], nome_cidade_2[30]; // Definindo o tamanho máximo do nome da cidade
    int populacao_1, populacao_2  , pontos_turisticos_1, pontos_turisticos_2; //criando as variaveis de população e pontos turisticos para as 2cidades
    float area_1, area_2  , pib_1, pib_2; //criando as variaveis de area e pib para as 2 cidades
    float densidade_populacional_1, densidade_populacional_2 
    , pib_per_capita_1, pib_per_capita_2 , super_poder_1, super_poder_2;//criando as variaveis de pib per capita, densidade populacional e super poder para as 2 cidades
    int atributo_comparar , quant_atri_comp , pontos_1, pontos_2; //criando as variaveis de pontos para cada cidade e as variavesl de quantos atributos seram comparados e o atributo a ser comparado



    printf("digite o nome da primeira cidade\n");
    scanf("%s", &nome_cidade_1);
    printf("digite o tamanho da população da primeira cidade\n");
    scanf("%d", &populacao_1);
    printf("digite a área da primeira cidade\n");
    scanf("%f", &area_1);
    printf("digite o pib da primeira cidade\n");
    scanf("%f", &pib_1);
    printf("digite quantos pontos turisticos tem na primeira cidade\n");
    scanf("%d", &pontos_turisticos_1);
    printf("digite o nome da segunda cidade\n");
    scanf("%s", &nome_cidade_2);
    printf("digite o tamanho da população da segunda cidade\n");
    scanf("%d", &populacao_2);
    printf("digite a área da segunda cidade\n");
    scanf("%f", &area_2);
    printf("digite o pib da segunda cidade\n");
    scanf("%f", &pib_2);
    printf("digite quantos pontos turisticos tem na segunda cidade\n");
    scanf("%d", &pontos_turisticos_2);

    densidade_populacional_1 = populacao_1 / area_1;
    pib_per_capita_1 = pib_1 / populacao_1;
    densidade_populacional_2 = populacao_2 / area_2;
    pib_per_capita_2 = pib_2 / populacao_2;          //calculo da densidade populacional e do pib per capita das 2 cidades
    super_poder_1 = pib_per_capita_1 + pontos_turisticos_1 + area_1 + populacao_1 + pib_1 + (densidade_populacional_1*-1);
    super_poder_2 = pib_per_capita_2 + pontos_turisticos_2 + area_2 + populacao_2 + pib_2 + (densidade_populacional_2*-1); //calculo do super poder das 2 cidades

    //imprimindo os dados das cidades
    printf("o nome da primeira é cidade %s o nome da sua segunda é cidade %s \n" , nome_cidade_1, nome_cidade_2);
    printf("a população da cidade %s é de %d a população da cidade %s é de %d\n", nome_cidade_1 , populacao_1 , nome_cidade_2 , populacao_2);
    printf("a área da cidade %s é de %f a área da cidade %s é de %f\n", nome_cidade_1 , area_1 , nome_cidade_2 , area_2);
    printf("o pib da cidade %s é de %f o pib da cidade %s é de %f\n", nome_cidade_1 , pib_1 , nome_cidade_2 , pib_2);
    printf("na cidade %s tem %d pontos turisticos e na cidade %s tem %d pontos turisticos\n", nome_cidade_1, pontos_turisticos_1 , nome_cidade_2, pontos_turisticos_2);
    printf("a densidade da cidade %s é de %f e a densidade da cidade %s é de %f\n", nome_cidade_1, densidade_populacional_1 , nome_cidade_2, densidade_populacional_2);
    printf("o pib per capita da cidade %s é de %f e o pib per capita da cidade %s é de %f\n", nome_cidade_1, pib_per_capita_1 , nome_cidade_2, pib_per_capita_2);
    printf("o super poder da cidade %s é de %f e o super poder da cidade %s é de %f\n", nome_cidade_1, super_poder_1 , nome_cidade_2, super_poder_2);
    //recebendo o número de atributos a serem comparados e se é valido
    printf("quantos atributos seram para comparados: ");
    scanf("%d", &quant_atri_comp);
    if (quant_atri_comp > 7 || quant_atri_comp < 1) {
        printf("não é possivel comparar mais de 7 atributos\n");
        return 0;
    } 
    //executando, recebendo e mostrando os atributos a serem comparados
    for (int i = 0; i < quant_atri_comp; i++) {
        printf("qual atributo vai ser comparado?\n população, área, pib, pontos turisticos\ndensidade populacional, pib per capita, super poder\n");
        printf("digite por número do atributo que você quer comparar\n");
        printf("1 - população\n2 - área\n3 - pib\n4 - pontos turisticos\n5 - densidade populacional\n6 - pib per capita\n7 - super poder\n");
        scanf("%d", &atributo_comparar);
        switch (atributo_comparar) {
            case 1:
                printf("população foi escolhida\n");
                if (populacao_1 > populacao_2) {
                    printf("a cidade %s é mais populosa que a cidade %s a cidade %s venceu\n", nome_cidade_1, nome_cidade_2 , nome_cidade_1);
                } else if (populacao_1 < populacao_2) {
                    printf("a cidade %s é mais populosa que a cidade %s a cidade %s venceu\n", nome_cidade_2, nome_cidade_1 , nome_cidade_2);
                } else {
                    printf("as cidades %s e %s são igualmente populosas\n", nome_cidade_1, nome_cidade_2);
                }
                break;
            case 2:
                printf("área foi escolhida\n");
                if (area_1 > area_2) {
                    printf("a cidade %s é maior que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_1, nome_cidade_2 , nome_cidade_1);
                    pontos_1 ++;
                } else if (area_1 < area_2) {
                    printf("a cidade %s é maior que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_2, nome_cidade_1 , nome_cidade_2);
                    pontos_2 ++;
                } else {
                    printf("as cidades %s e %s são igualmente grandes\n", nome_cidade_1, nome_cidade_2);
                }
                break;
            case 3:
                printf("pib foii escolhido\n");
                if (pib_1 > pib_2) {
                    printf("a cidade %s é mais rica que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_1, nome_cidade_2 , nome_cidade_1);
                    pontos_1 ++;
                } else if (pib_1 < pib_2
                ) {
                    printf("a cidade %s é mais rica que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_2, nome_cidade_1 , nome_cidade_2);
                    pontos_2 ++;
                } else {
                    printf("as cidades %s e %s são igualmente ricas\n", nome_cidade_1, nome_cidade_2);
                }
                break;
            case 4:
                printf("pontos turisticos\n");
                if (pontos_turisticos_1 > pontos_turisticos_2) {
                    printf("a cidade %s tem mais pontos turisticos que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_1, nome_cidade_2 , nome_cidade_1);
                    pontos_1 ++;
                } else if (pontos_turisticos_1 < pontos_turisticos_2) {
                    printf("a cidade %s tem mais pontos turisticos que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_2, nome_cidade_1 , nome_cidade_2);
                    pontos_2 ++;
                } else {
                    printf("as cidades %s e %s tem o mesmo número de pontos turisticos\n", nome_cidade_1, nome_cidade_2);
                }
                break;
            case 5:
                printf("densidade populacional\n");
                if(densidade_populacional_1 < densidade_populacional_2) {
                    printf("a cidade %s é mais densa que a cidade %s\ncidade %s venceu\n"
                        , nome_cidade_1, nome_cidade_2 , nome_cidade_2);
                    pontos_2 ++;
                } else if (densidade_populacional_1 > densidade_populacional_2) {
                    printf("a cidade %s é mais densa que a cidade %s\ncidade %s venceu"
                        , nome_cidade_2, nome_cidade_1 , nome_cidade_1);
                    pontos_1 ++;
                } else {
                    printf("as cidades %s e %s são igualmente densas\n", nome_cidade_1, nome_cidade_2);
                }
                break;
            case 6:
                printf("pib per capita\n");
                if (pib_per_capita_1 > pib_per_capita_2) {
                    printf("a cidade %s é mais rica por habitante que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_1, nome_cidade_2 , nome_cidade_1);
                    pontos_1 ++;
                } else if (pib_per_capita_1 < pib_per_capita_2) {
                    printf("a cidade %s é mais rica por habitante que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_2, nome_cidade_1 , nome_cidade_2);
                    pontos_2 ++;
                } else {
                    printf("as cidades %s e %s são igualmente ricas por habitante\n"
                        , nome_cidade_1, nome_cidade_2);
                }
                break;
            case 7:
                printf("super poder\n");
                if (super_poder_1 > super_poder_2) {
                    printf("a cidade %s é mais poderosa que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_1, nome_cidade_2 , nome_cidade_1);
                    pontos_1 ++;
                } else if (super_poder_1 < super_poder_2) {
                    printf("a cidade %s é mais poderosa que a cidade %s a cidade %s venceu\n"
                        , nome_cidade_2, nome_cidade_1 , nome_cidade_2);
                    pontos_2 ++;
                } else {
                    printf("as cidades %s e %s são igualmente poderosas\n", nome_cidade_1, nome_cidade_2);
                }
                break;
            default:
                printf("opção inválida\nperdeu a chance de comparar as cidades\n");
                break;
            //informando o resultado da comparação
            if (pontos_1 > pontos_2) {
                printf("a cidade %s venceu\n", nome_cidade_1);
                printf("por %d a mais que a cidade %s\n" , pontos_1 - pontos_2 , nome_cidade_2);
            } else if (pontos_1 < pontos_2) {
                printf("a cidade %s venceu ", nome_cidade_2);
                printf("por %d a mais que a cidade %s\n" , pontos_2 - pontos_1 , nome_cidade_1);
            } else {
                printf("as cidades %s e %s empataram\n", nome_cidade_1, nome_cidade_2);
            }
        }   
    }
}
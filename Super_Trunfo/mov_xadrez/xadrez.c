#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
criar um void para mover cada peça

*/
void Letra_M (char palavra[]){ //torna a primeira letra maiuscula se for minuscula
    if (palavra[0] >= 'a' && palavra[0] <= 'z'){
        palavra[0] = palavra[0] -32;
    }
}
int Test_Pala(char *palavra, char *palavras[], int tamanho) { // testa se uma string pertence a um array de strings (precisa do tamanho da array)
    int etapa = 1;
    switch (etapa){
    case 1:
        for (int i = 0; i < tamanho; i++) {
        if (strcmp(palavra, palavras[i]) == 0) {
            return 1; // Retorna 1 se a string pertence ao array
        }
    } 
    default:
    printf("não pertence\n");
    return 0; // Retorna 0 se a string não pertence ao array
    }
}
int Test_Peca(char *palavra, char *palavras[], int tamanho) {// retorna o valor que uma string ocupa uma array
    int etapa = 1;
    switch (etapa){
    case 1:
        for (int i = 0; i < tamanho; i++) {
        if (strcmp(palavra, palavras[i]) == 0) {
            return i; // Retorna o numero da peça
        }
    } 
    default:
    printf("não pertence\n");
    return 0; // Retorna 0 se a string não pertence ao array
    }
}
int Test_Mov(char *direcao,char *movimentos[], int peca_mover, int mov) { // testa se o movimento das peças a seguir sao validos
    //"Peão", "Torre", "Bispo", "Cavalo", "Rainha", "Rei"
    int mover_cav_1, mover_cav_2, resul_cav_1 , resul_cav_2 ;
    char direcao_cav_1[10];
    char direcao_cav_2[10];
    char mov_inicial[10];
    char peca_em_posi[10];
    if (mov <= 0 || mov >= 8 ||
        (peca_mover == 0 && (mov >= 3 || (mov != 1 && direcao[2] == movimentos[4][2]) || (direcao[2] != movimentos[4][2] && direcao[2] != movimentos[0][2])))||
        (peca_mover == 1 &&  direcao[2] == movimentos[4][2])||
        (peca_mover == 2 &&  direcao[2] != movimentos[4][2])||
        (peca_mover == 3 && (mov > 3|| direcao[2] != movimentos[4][2]))||
        (peca_mover == 5 && mov > 1)){ 
        printf("Você escolheu andar %d casas para %s isso é invalido\n", mov ,direcao);
        return 0;
    }
    switch (peca_mover){
        case 0 ://  peao
            if (mov == 2 && direcao[2] == movimentos[0][2] ){      //teste de validação
                printf("Você escolheu andar %d casas com o peão ", mov);
                printf("esse movimento só é valido caso seja o primeiro movimento do peão em questão esse é o caso?\n");
                scanf("%s", &*mov_inicial);
                Letra_M(mov_inicial);
            }else if (mov == 1 && direcao[2] == movimentos[4][2]){
                printf("andar para %s só é valido caso tenha uma peça nessa posição essa é a ocasião?\n", direcao);
                scanf("%s", &*peca_em_posi);
                Letra_M(peca_em_posi);
            }
            if (mov_inicial[0] == 'S' || peca_em_posi[0] == 'S' || (mov == 1 && direcao[2] == movimentos[0][2])){ //confirmação
                printf("Você escolheu andar %d na direção %s casas isso é valido\n", mov, direcao);
            }else{
                printf("Você escolheu andar %d na direção %s casas isso é invalido nessa ocasião\n", mov, direcao);
                return 0;
            }
            break;
        case 1:     //    torre printf("Você escolheu andar %d casas isso é valido\n", mov);
            break;
        case 2:     //   bispo printf("Você escolheu andar %d casas isso é valido\n", mov);
            break;
        
        case 3:     //    cavalo
        for (int i = 0; i <2; i++){         //escolha da direção
                printf("escolha uma direção para andar diagonalmente:\n");
                if (i ==0){                 //teste direção 1
                    scanf("%s", &*direcao_cav_1);
                    Letra_M(direcao_cav_1);
                    resul_cav_1 = Test_Pala(direcao_cav_1, movimentos, 4);  // incrementar a retiraçao da diagonal
                    if (resul_cav_1 == 0){  //confirmação da direção
                        printf("Você escolheu andar para %s isso é invalido\n", direcao_cav_1);
                        return 0;
                    }else{
                        printf("quanto para a direção %s\n", direcao_cav_1);
                        scanf("%d", &mover_cav_1);
                        if(mover_cav_1 > 2 || mover_cav_1 < 1){ //teste de validação do quanto mover
                            printf("Você escolheu andar %d casas isso é invalido\n", mover_cav_1);
                            return 0;
                        }else if (mover_cav_1 <= 2){
                            printf("Você escolheu andar para %s %d casas isso é valido\n", direcao_cav_1, mover_cav_1);
                        }
                    }
                }
                if (i == 1){
                    scanf("%s", &*direcao_cav_2);
                    Letra_M(direcao_cav_2);
                    resul_cav_2 = Test_Pala(direcao_cav_2, movimentos, 4);
                    printf("resul_cav_2: %d\n", resul_cav_2);
                    if ((direcao_cav_1[0] == 'B' && direcao_cav_2[0] == 'C') || (direcao_cav_1[0] == 'C' && direcao_cav_2[0] == 'B') 
                    ||  (direcao_cav_1[0] == 'E' && direcao_cav_2[0] == 'D') || (direcao_cav_1[0] == 'D' && direcao_cav_2[0] == 'E') 
                    ||   direcao_cav_1[0] == direcao_cav_2[0] || resul_cav_2 == 0){  //confirmação da direção
                        printf("Você escolheu andar para %s isso é invalido\n", direcao_cav_2);
                        return 0;
                    }
                    printf("quanto para a direção %s\n", direcao_cav_2);
                    scanf("%d", &mover_cav_2);
                    if(mover_cav_2 > 2 || mover_cav_2 < 1 || mover_cav_1 + mover_cav_2 >=4){     //teste de validação do quanto mover
                        printf("Você escolheu andar %d casas isso é invalido\n", mover_cav_2 + mover_cav_1);
                        return 0;
                    }else if (mover_cav_2 + mover_cav_1 == 3){
                        printf("Você escolheu andar para %s %d casas isso é valido\n", direcao_cav_2, mover_cav_2);
                    }
                }
            }
            printf("Você escolheu andar para %s e %s andando %d e %d casas isso é valido\n"
                , direcao_cav_1, direcao_cav_2, mover_cav_1 , mover_cav_2);
            break;
        case 4://    rainha printf("Você escolheu andar %d casas isso é valido\n", mov);
            break;
        case 5://    rei printf("Você escolheu andar %d casas isso é valido\n", mov);
            break;
        default:
            break;
       return 1;
    }
}



int main() { //xadrez
    char saida[10];
    int confirmacao = 0;
    char *mov_inicial;
    printf("bem vindo ao jogo de xadrez\n");
    while (confirmacao == 0) {   

        int mover, mover_cav_1, mover_cav_2, resul_cav_1 , resul_cav_2 ;
        int peca_mover;
        char peca[10];
        
        char movimento[10];
        char direcao_cav_1[10];
        char direcao_cav_2[10];
        char cor[10];
        char *pecas[] = {"Peão", "Torre", "Bispo", "Cavalo", "Rainha", "Rei"};
        char *movimentos[] = {"Cima", "Baixo", "Esquerda", "Direita", "Diagonal"};
        char *cores[] = {"Branco", "Preto"};

        printf("Escolha uma peça:\n");
        for(int i = 0; i < 6; i++) {
            printf("%s\n", pecas[i]);
        }
        printf("Digite sua escolha: ");
        scanf("%s", &*peca);
        printf("Escolha uma direção:\n");
        for(int i = 0; i < 5; i++) {
            printf("%s\n", movimentos[i]);
        }
        printf("Digite sua escolha: ");
        scanf("%s", &movimento);
        printf("Escolha uma cor:\n");
        for (int i = 0; i < 2; i++) {
            printf("%s\n", cores[i]);
        }
        printf("Digite sua escolha: ");
        scanf("%s", &*cor);
        
        Letra_M(peca);
        Letra_M(movimento);
        Letra_M(cor);
        if(Test_Pala(peca, pecas, sizeof(pecas)/sizeof(pecas[0]))&&
           Test_Pala(movimento, movimentos, sizeof(movimentos)/sizeof(movimentos[0]))&&
           Test_Pala(cor, cores, sizeof(cores)/sizeof(cores[0]))){
            printf("Você escolheu: %s da cor %s para %s\n", peca, cor , movimento);
        }else{
            printf("Você escolheu %s, %s ou %s que é uma opção inválida.\n", peca,cor, movimento);
            return 0;
        }
        printf("Quantas casas deseja andar?");
        scanf("%d", &mover);
        peca_mover = Test_Peca(peca, pecas, sizeof(pecas)/sizeof(pecas[0]));
        if(Test_Mov(movimento, movimentos, peca_mover, mover) == 0){
            return 0;
        }else{
            printf("Você escolheu andar %d casas para %s com %s %s que é uma opção válida.\n", mover, movimento, peca, cor);   
        }
        //comentar a ação
        for (int i = 0; i < mover; i++){
            printf("Você moveu a peça %s %s para a %s\n", peca, cor , movimento);
        }
        
        printf("Deseja continuar jogando? (sim/não): ");
        scanf("%s", &saida);
        Letra_M(saida);
        if (saida[0] == 'N'){
            printf("Você escolheu não continuar jogando.\n");
            confirmacao = 1;
        }else if (saida[0] == 'S'){
            printf("Você escolheu continuar jogando.\n");
            confirmacao = 0;
        }else{
            printf("Opção inválida, encerrando o jogo.\n");
            confirmacao = 0;
        }
    }
    printf("Fim do jogo!\n");

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main() {
    char *saida;
    int confirmacao = 0;
    printf("bem vindo ao jogo de Joken Po\n");
    while (confirmacao == 0) {        
        srand(time(NULL)); 
        
        int escolha_pessoa, escolha_computador = rand() % 3 ;
        char escolha[10];
        char *opcoes[] = {"Pedra", "Papel", "Tesoura"};

        printf("Escolha uma opção:\nPedra\nPapel\nTesoura\n");
        printf("Digite sua escolha: ");
        scanf("%s", &*escolha);
        escolha[0] = escolha[0] -32;
        for (int i = 0; i < 3; i++) {
            if (strcmp(escolha, opcoes[i]) == 0) {
                printf("Você escolheu: %s \n", opcoes[i]);
                break;
            }else {
                printf("Opção inválida, encerrando o jogo.\n");
                return 0; // A string não pertence à cadeia
            }
        }
        printf("Computador escolheu: %s\n", opcoes[escolha_computador]);
    
        
            
        if (escolha[2] == opcoes[0][2]){
            printf("Você escolheu: %s - Computador escolheu %s\n", opcoes[0] , opcoes[escolha_computador]);
            escolha_pessoa = *opcoes[0] - 'P';
        }
        else if (escolha[2] == opcoes[1][2]){
            printf("Você escolheu: %s - Computador escolheu %s\n", opcoes[1] , opcoes[escolha_computador]);
            escolha_pessoa =  *opcoes[1] / 'P' ;
        }
        else if (escolha[2] == opcoes[2][2]){
            printf("Você escolheu: %s - Computador escolheu %s\n", opcoes[2] , opcoes[escolha_computador]);
            escolha_pessoa = *opcoes[2] / 'T' +1;
        }else  {
            return 0;
        }
        
        if (escolha_pessoa == escolha_computador){
            printf("Empate!\n");
        }else if ((escolha_pessoa > escolha_computador)||(escolha_pessoa == 0 && escolha_computador == 2)){
            printf("Você ganhou!\n");
        }else{
            printf("Você perdeu!\n");
        }
        printf("Deseja continuar jogando? (sim/não): ");
        scanf("%s", &*saida);
        if (saida[0] == 'n'){
            printf("Você escolheu não continuar jogando.\n");
            confirmacao = 1;
        }else if (saida[0] == 's'){
            printf("Você escolheu continuar jogando.\n");
            confirmacao = 0;
        }else{
            printf("Opção inválida, encerrando o jogo.\n");
            confirmacao = 1;
        }
        

    }
    printf("Fim do jogo!\n");
}
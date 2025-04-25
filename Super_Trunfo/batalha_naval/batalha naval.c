#include <stdio.h>
#include <stdlib.h>

#define Linha 10
#define Coluna 10
#define meio 4



int main(){

    int tipo_navio, navio, tamanho_navio, x, y;//cria variaveis para o tipo de navio, o numero do navio, o tamanho do navio e as coordenadas x e y
    int mar[10][10] ; // 
    for (int i = 0; i < Linha; i++){ // inicializa o mar com 0
        for (int j = 0; j < Coluna; j++){
            mar[i][j] = 0;
        }
    }
    char *coordenadas[11] = {"A","B","C","D","E","F","G","H","I","J"}; // cria um vetor de strings com as coordenadas do mar
    //imprime as coordenadas do mar
    printf("bem vindo a batalha naval\n_ ");
    for (int i =0 ; i < Linha; i++){
        printf("%d ", i);
    }

    //imprime o mar e as coordenadas em letras
    printf("|\n");
    for (int i = 0; i < Linha; i++){
        printf("%s ", coordenadas[i]);
        for (int j = 0; j < Coluna; j++){
            printf("%d ", mar[i][j]);
        }
        printf("|\n");

    }
    //recebe as coordenadas do barco, o tipo de barco, o tamanho do barco e o numero pro barco
    printf("escolha a direçao do barco\n1 - horizontal\n2 - vertical\n3 - diagonal /\n4 - diagonal\n5 -formato triangular\n6 - em cruz\n7 - em formato de losangulo escolha uma opção: ");
    scanf("%d", &tipo_navio);
    printf("escolha o tamanho do barco(n pode ser menor que 0 nem maior que 10): ");
    scanf("%d", &tamanho_navio);
    printf("escolha a coordenada x do barco: ");
    scanf("%d", &x);
    printf("escolha a coordenada y do barco: ");
    scanf("%d", &y);
    printf("escolha o o numero que será barco(entre 1 e 9): ");
    scanf("%d", &navio);

    printf("mostrando as coordenadas do barco\n");

    if(tipo_navio > 7 || tipo_navio <= 0 || x >= 10 || y >= 10 || x <0 || y < 0){// checa as coordenadas do barco e se o barco é maior que 0 e menor que 10
        printf("não é possivel por um barco nesse lugar\n");
        return 0;
    }
    if (tipo_navio == 1){       //testa o que é necessario para o barco em formato de horizontal e coloca o barco
        if(x < 10  && y <= 10 -tamanho_navio && x >=0 && y >=0 && tamanho_navio < 9 && tamanho_navio > 0){
            for (int i = 0; i < tamanho_navio; i++){
                if (mar[x][y+i] == navio){
                    printf("ja tem um barco colocado no lugar\n");
                    break;
                }else{
                    mar[x][y+i] = navio;
                }
            }
        }else{
            printf("coordenadas incooretas \n");
        }
    }
    if (tipo_navio == 2){       //testa o que é necessario para o barco em formato de vertical e coloca o barco
        if( x <= 10 - tamanho_navio && y < 10 && x >=0 && y >=0 && tamanho_navio < 9 && tamanho_navio > 0){
            for (int i = 0; i < tamanho_navio; i++){
                if (mar[x+i][y] == navio){
                    printf("ja tem um barco colocado no lugar\n");
                    break;
                }else{
                    mar[x+i][y] = navio;
                }
            }
        }else{
            printf("coordenadas incooretas \n");
        }
    }
    if (tipo_navio == 3){       //testa o que é necessario para o barco em formato de diagonal e coloca o barco
        if(x == y && x < 10 && y < 10 && x >=0 && y >=0 && tamanho_navio < 9 && tamanho_navio > 0){
            for (int i = 0; i < tamanho_navio; i++){
                if (mar[x+i][y+i] == navio){
                    printf("ja tem um barco colocado no lugar\n");
                    break;
                }else{
                    mar[x+i][y+i] = navio;
                }
            }
        }else{
            printf("coordenadas incooretas \n");
        }
    }
    if (tipo_navio == 4){     //testa o que é necessario para o barco em formato de diagonal e coloca o barco
        if(x + y == 9 && x < 10 && y < 10 && x >=0 && y >=0 &&tamanho_navio < 9 && tamanho_navio > 0){
            for (int i = 0; i < tamanho_navio; i++){
                if (mar[x+i][y-i] == navio){
                    printf("ja tem um barco colocado no lugar\n");
                    break;
                }else{
                    mar[x+i][y-i] = navio;
                }  
            }
        }else{
            printf("coordenadas incooretas \n");
        }
    }
    if(tipo_navio == 5){         //testa o que é necessario para o barco em formato de triangulo e coloca o barco
        if(x < 11 - tamanho_navio && y <= 5-tamanho_navio && x >=0 && y >= -7+tamanho_navio && tamanho_navio < 9 && tamanho_navio > 0){
            for (int i = 0; i < tamanho_navio; i++) {
                for (int j = meio - i; j <= meio + i; j++) {
                    if (j >= 0 && j < Coluna) { 
                        if (mar[x+i][y+j] == navio){
                            printf("ja tem um barco colocado no lugar\n");
                            break;
                        }else{
                        mar[x+i][y+j] = navio; 
                        }
                    }
                }
            } 
        }else{
            printf("coordenadas incooretas \n");
            return 0;
        }
    }
    if (tipo_navio == 6){       //testa o que é necessario para o barco em formato de cruz e coloca o barco
        if(x < 10 && y < 10 && x >=0 && y >=0 && tamanho_navio < 9 && tamanho_navio > 0){
            for (int i = 1; i < 3; i++){
                for (int j = -2; j <= 2; j++){
                    if (i < 2 && mar[x+i][y+j] == navio){
                        printf("ja tem um barco colocado no lugar\n");
                        break;
                    }else if(i < 2){
                        mar[x+i][y+j] = navio;
                    }if (i == 2 && mar[x+i][y+j] == navio){
                        printf("ja tem um barco colocado no lugar\n");
                        break;
                    }else if(i == 2){
                        j=0;
                        mar[x+i][y+j] = navio;
                        break;
                    }
                }
                
            }
            if (mar[x][y] == navio || mar[x][y] == navio){
                printf("ja tem um barco colocado no lugar\n");
                
            }else{
                mar[x][y] = navio;
                mar[x][y] = navio;
                printf("colocando 1 barco\n");
            }  
        }else{
            printf("coordenadas incooretas \n");
        }
    }
    if (tipo_navio == 7){      //testa o que é necessario para o barco em formato de losangulo e coloca o barco
        y=y-4;
        if(x < 11 - tamanho_navio && y <= 5-tamanho_navio && x >=0 && y >= -7+tamanho_navio && tamanho_navio < 9 && tamanho_navio > 0){
            for (int i = 0; i < tamanho_navio; i++) {
                for (int j = meio - i; j <= meio + i; j++) {
                    if (j >= 0 && j < Coluna) { 
                        if (mar[x+i][y+j] == navio){
                            printf("ja tem um barco colocado no lugar\n");
                            break;
                        }else{
                        mar[x+i][y+j] = navio; 
                        }
                    }
                }
            }
            for (int i = tamanho_navio ; i < tamanho_navio+5; i++) { // Parte inferior
                for (int j = i - tamanho_navio-1; j < tamanho_navio + tamanho_navio - (i - tamanho_navio); j++) {
                    if (mar[x+i][y+(5-tamanho_navio)+j] == navio){
                        printf("ja tem um barco colocado no lugar\n");
                        break;
                    }else{
                    mar[x+i][y+(5-tamanho_navio)+j] = navio;
                    }
                }
            }
        }else{
            printf("coordenadas incooretas \n");
            return 0;
        }
    

    }
    printf("_ ");
    for (int i =0 ; i < Linha; i++){
        printf("%d ", i);
    }

    printf("|\n");
    for (int i = 0; i < Linha; i++){
        printf("%s ", coordenadas[i]);
        for (int j = 0; j < Coluna; j++){
            if (11==i && 11==j){
                printf("1 ");
            }else {
                printf("%d ", mar[i][j]);
            }
        }   
        printf("|\n");
    }


}
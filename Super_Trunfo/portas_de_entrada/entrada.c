#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // biblioteca para usar booleanos

int main(){
    //porta OR || porta AND && porta NOT !
    bool a = 1; // 1 = true, 0 = false
    bool b = 0;
    bool c = 1;
    bool d = 0;
    if((a && b && c)||(!(c||d) || !a) ){
        printf("sua expressão é verdadeira (do dever la)\n");
    }
    if(a || b){// porta OR com a e b
        printf("a ou b é verdadeiro\n");
    }
    if(a && b){// porta AND com a e b
        printf("a e b são verdadeiros\n");
    }
    if(a && !b){// porta AND com a e b negado
        printf("a é verdadeiro b é falso\n");
    }
    if(!a && !b){// porta NAND com a e b 
        printf("a e b são falsos\n");
    }
    if(a && b && c && d){// porta AND com a, b, c e d
        printf("a, b, c e d são verdadeiros\n");
    }
    if((a && b) || (!c && !d)){// porta OR com porta AND a e b e porta NAND com c e d 
        printf("ou a e b sao verdadeiros ou c é verdadeiro e d é falso\n");
    }
    if((a && b) || (c && d)){// porta OR com porta AND a e b e porta AND com c e d
        printf("ou a e b sao verdadeiros ou c e d são falsos\n");
    }
}
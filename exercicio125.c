//guilmour
#include<stdio.h>
#include <stdlib.h>

typedef struct{

    int concusro;
    char data;
    char numeros[6];
    double valor;

}Mega;

void exercicio124(){

    int i;
    int aposta[6];

    for(i=0; i<6; i++){

        printf("Digite o %do numero da sua aposta: ", i+1);
        scanf("%d", &aposta[i]);
        if(aposta[i] > 60 || aposta[i]<1 ){
            printf("Por favor, digite numeros entre 1 e 60.\n");
            i--;
        }
    }

    printf("\nSua aposta foi: ");
    for(i=0; i<6; i++){
        printf("%d,", aposta[i]);

    }






    printf("\n");
}


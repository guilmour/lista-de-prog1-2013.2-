//guilmour.com
#include <stdio.h>
#include <stdlib.h>

void exercicio75(){
    printf("Exercicio 75:\n");
    FILE *file;
    file = fopen("75.txt", "r");

    char menu[100000];
    while(fgets(menu, 100000, file) != NULL){
    printf("%s", menu);
    }
    printf("\n\n");
    fclose(file);

    int distancia[5][5], i=0, k=0;

    //inicia todas as arrays com zero
    for(i=0; i<5; i++){
        for(k=0; k<5; k++){
            distancia[i][k] = 0;
            //printf("%d ",distancia[i][k]);
        }
        //printf("\n");
    }
    //atribui as distancias das cidades
    for(i =0; i<5; i++){
        for(k=0; k<5; k++){
            if(i == k){
                distancia[i][k] = 0;
                printf("Digite a distancia entre %d e %d: %d\n", i+1, k+1, distancia[i][k]);
            }

            else if(distancia[i][k] == 0 && distancia[k][i] > 0){
                distancia[i][k] = distancia[k][i];
                printf("Digite a distancia entre %d e %d: %d\n", i+1, k+1, distancia[i][k]);
            }

            else{
            printf("Digite a distancia entre %d e %d: ", i+1, k+1);
            scanf("%d", &distancia[i][k]);

            }
        }
    }

    for(i=0; i<5; i++){
        for(k=0; k<5; k++){
            printf("%3d ",distancia[i][k]);
        }
        printf("\n");
    }



    int trajeto[7], soma=0;
    printf("Digite o trajeto para que seja calculado as distancias.:\n");

    for(i=0; i<7; i++){
        scanf("%d", &trajeto[i]);
        if(trajeto[i] > 5 || trajeto[i] < 1 ){
        printf("Por favor, digite numeros entre 1 e 5.\n");
        i--;
        }
    }



    for(i=0; i<6; i++){
        printf("%d + ", distancia[trajeto[i]-1][trajeto[i+1]-1]);

        soma = soma + distancia[trajeto[i]-1][trajeto[i+1]-1];
    }
    printf(" = %d km", soma);

}



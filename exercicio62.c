//guilmour.com
#include <stdio.h>
#include <stdlib.h>

void minMaxMedio (int* vetor, int tam, int* min, int* max, double* medio);

void exercicio62()
{
    int vetor[10], tam=10, min=0, max=0, i=0;
    double medio=0;
    FILE *file;
    file = fopen("62.txt", "r");

    char menu[100000];
    while(fgets(menu, 100000, file) != NULL){
    printf("%s", menu);
    }
    printf("\n\n");
    fclose(file);

    for(i=0; i<tam; i++){
    printf("Digite o numero da posicao %d do vetor: ", i+1);
    scanf("%d", &vetor[i]);
    }

    /*
    for(i=0; i<tam; i++){
    printf("%d", vetor[i]);
    }
    */

    minMaxMedio(&vetor, tam, &min, &max, &medio);

    printf("\nO valor maximo eh: %d", max);
    printf("\nO valor minimo eh: %d", min);
    printf("\nO valor medio eh: %.2lf", medio);


}
void minMaxMedio (int *vetor, int tam, int *min, int *max, double *medio){
    int i=0, soma=0;

    /* percorre e procura o maximo */
    for(i=0; i<tam; i++){
    if(vetor[i] > *max)
    *max = vetor[i];
    }
    //printf("\n maximo: %d", *max);

    //percorre e procura o minimo
    *min = vetor[i];
    for(i=0; i<tam; i++){
    if(vetor[i] < *min || vetor[i] == 0 && *min > 0)
    *min = vetor[i];
    }
    //printf("\n minimo: %d", *min);


    //soma e tira a maedia
    for(i=0; i<tam; i++){

    soma = soma + vetor[i];
    }
    //printf("\n soma: %d", soma);
    *medio = (double)soma/(double)tam;

    //printf("\n media: %lf", *medio);
    //printf("\n media: %lf", (double)soma);

}












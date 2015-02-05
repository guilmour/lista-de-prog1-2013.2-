/** ESSA VERSÃO CRIA VALORES RANDOMICOS PARA OS SORTEIOS **/

//guilmour.com
#include<stdio.h>
#include <stdlib.h>
#define TAM 1628 //1628
typedef struct{

    int concurso;
    int data[3];
    int numeros_sorteio[6];
    int numeros_crescente[6];
    double premio;

}Mega;

void exercicio124(){
    Mega mega[TAM];
    int i, j, k, l, maior=0, aux=0, menor=0, flag=0, cont=0;
    int aposta[6], aposta_ordenada[6];
    //srand((unsigned)time(NULL));

    /* PEGA AS APOSTAS DO USUARIO*/
    for(i=0; i<6; i++){

        printf("Digite o %do numero da sua aposta: ", i+1);
        scanf("%d", &aposta[i]);
        if(aposta[i] > 60 || aposta[i]<1 ){
            printf("Por favor, digite numeros entre 1 e 60.\n");
            i--;
        }
    }

    /* ATRIBUI NUMERAÇÃO PARA OS CONCURSOS, NUMERO DE APOSTAS, DATA, E TOTAL DO PREMIO */
    for(i=0; i<TAM; i++){

        mega[i].concurso = i;

        mega[i].premio = ((rand()%102));

        for(k=0; k<6; k++){
            mega[i].numeros_sorteio[k] = rand() % 60;

            if(mega[i].numeros_sorteio[k] == mega[i].numeros_sorteio[k-1] ){
                k--;
            }
        }
    }


    printf("\n");

    /* Copia todos os numeros sorteados para outro vetor que fara a ORDEM CRESCENTE dos numeros*/
    for(i=0; i<TAM; i++){
        for(k=0; k<6; k++){

            mega[i].numeros_crescente[k] = mega[i].numeros_sorteio[k];

        }
    }

    /* Copia a aposta para o vetor aposta_ordenada */
    for(i=0; i<TAM; i++){
        for(k=0; k<6; k++){

            aposta_ordenada[k] = aposta[k];

        }
    }

    /* Imprime todos os jogos POR ORDEM DE SORTEIO */
    printf("ORDEM DE SORTEIO: \n");
    for(i=0; i<TAM; i++){

        printf("%d - ", mega[i].concurso+1);

        for(k=0; k<6; k++){

            printf("%2d ", mega[i].numeros_sorteio[k]);
        }

        printf("- R$%.0lfM", mega[i].premio);

        printf("\n");
    }


    /* Coloca todos os jogos em ORDEM CRESCENTE */
    for(i=0; i<TAM; i++){

        for(k=0; k<6; k++){

            /* Procura o Maior Valor da Aposta */
            for(j=0; j<6; j++){
                if(mega[i].numeros_crescente[j] > maior){
                maior = mega[i].numeros_crescente[j];
                }
            }
            aux = maior;

            /* Procura o Menor Valor da Aposta*/
            for(j=0; j<6; j++){
                if(mega[i].numeros_crescente[j] < aux){
                aux = mega[i].numeros_crescente[j];
                menor = aux;
                }
            }
        }
        //printf("\nO menor valor eh: %d", menor);
        //printf("\nO maior valor eh: %d", maior);

        flag = 0;

        for(k=0; k<6; k++){
            aux = maior;

            /* ORDENA OS VALORES DE FORMA CRESCENTE*/
            for(j= 0; j<6; j++){

                if(mega[i].numeros_sorteio[j] < aux && flag == 0){

                    aux = mega[i].numeros_sorteio[j];

                }

                else if(mega[i].numeros_sorteio[j] < aux && flag == 1 && mega[i].numeros_sorteio[j] > mega[i].numeros_crescente[k-1]){

                    aux = mega[i].numeros_sorteio[j];

                }
            }

            mega[i].numeros_crescente[k] = aux;
            /* Este FLAG diz ao compilador que ja passamos do primeiro elemento do vetor*/
            flag = 1;

        }
        maior = 0;

    }

    /* imprime todos os jogos POR ORDEM CRESCENTE
    printf("\nORDEM CRESCENTE: \n");

    for(i=0; i<TAM; i++){
       printf("%d - ", mega[i].concurso+1);
        for(k=0; k<6; k++){

            printf("%2d ", mega[i].numeros_crescente[k]);
        }

        printf("\n");

    }
    */

    flag = 0;
    /* COLOCA O JOGO DELE TAMBÉM EM ORDEM CRESCENTE*/
    for(k=0; k<6; k++){
            aux = 61;


            for(j= 0; j<6; j++){

                if(aposta[j] < aux && flag == 0){

                    aux = aposta[j];

                }

                else if(aposta[j] < aux && flag == 1 && aposta[j] > aposta_ordenada[k-1]){

                    aux = aposta[j];

                }
            }

            aposta_ordenada[k] = aux;
            /* Este FLAG diz ao compilador que ja passamos do primeiro elemento do vetor*/
            flag = 1;

    }
    flag = 0;

    /* iMPRIME APOSTA POR ORDEM QUE FOI INSERIDA*/
    printf("\nSua aposta foi: \n ");
    for(i=0; i<6; i++){
        printf("%2d ", aposta[i]);
    }
    printf("\n");
    /* iMPRIME APOSTA POR ORDEM CRESCENTE*/
    printf("\nSua aposta com ordem Crescente:\n ");
    for(i=0; i<6; i++){
        printf("%2d ", aposta_ordenada[i]);
    }
    printf("\n");

    //printf("\nVerificando se seu jogo ja foi sorteado: ");
    for(i=0; i<TAM; i++){

        for(k=0; k<=6; k++){

            if(aposta_ordenada[k] == mega[i].numeros_crescente[k]){
                cont = cont + 1;
            }

            else if(cont == 6){
                printf("\nSua aposta ja foi sorteada no:\nConcurso: \t%d, \nData: \t\t%d \nPremio: \tR$%.1lf. Milhoes\n", mega[i].concurso+1, mega[i].data, mega[i].premio);
                //system("PAUSE");
                cont = 0;
                flag = 1;
            }
        }
        cont = 0;
    }

    if(flag == 0 ){
        printf("\n---------- SUA APOSTA NUNCA FOI SORTEADA D: ----------\n");
    }
}


/** ESSA VERSAO USA ARQUIVOS COM VALORES FORNECIDOS PELA PR�PRIA CAIXA ECONOMICA **/
//guilmour.com
#include<stdio.h>
#include <stdlib.h>
#define TAM 1628 //1628

//oi
typedef struct{
    int concurso;
    char data[10];
    int numeros[6];
    double premio;
}Mega;

void exercicio124_2(){
    Mega mega[TAM];
    int i, j, k, aux=0, flag=0, cont=0, menor=0, aux2=0;
    int aposta[6], aposta_ordenada[6];
    int top10[10][2];
    int top60[60][2];
    double aux_lf=0.00;
    printf( "Exercicio 124: A CEF disponibiliza um arquivo online com todos os resultados da\n"
            "mega-sena, organizados na forma de uma tabela. Considerando que temos este\n"
            "arquivo na forma de texto, fazer um programa que efetue as seguintes operacoes:\n\n"
            "a. Receba um jogo do usuario (6 numeros, de 1 a 60) e verifique se aquele jogo\n"
            "ja foi sorteado e quando foi sorteado.\n\n"
            "b. Calcule e mostre quais os 10 numeros mais sorteados de todos os tempos\n\n"
            "c. Mostre qual o maior premio e o menor premio totais ja rateados\n\n******************\n\n");

    /*********** CONCURSOS *************/
    FILE *fp;
    fopen("concursos.txt", "r");

    if((fp = fopen("concursos.txt", "r")) == NULL){
        printf("Arquivo n�o pode ser aberto!\n");
        exit(1);
    }

    for(i=0; i<TAM; i++){
        fscanf(fp, "%d", &mega[i].concurso);
    }
    /*
    for(i=0; i<TAM; i++){
        printf("%d\n", mega[i].concurso);
    }
    */
    /*********** FIM CONCURSOS *************/

    /*********** DATAS *************/
    fopen("datas.txt", "r");

    if((fp = fopen("datas.txt", "r")) == NULL){
        printf("Arquivo n�o pode ser aberto!\n");
        exit(1);
    }

    for(i=0; i<TAM; i++){
        fscanf(fp, "%s", &mega[i].data);
    }
    /*********** FIM DATAS *************/


    /*********** PREMIOS *************/
    fopen("premios.txt", "r");

    if((fp = fopen("premios.txt", "r")) == NULL){
        printf("Arquivo nao pode ser aberto!\n");
        exit(1);
    }

    for(i=0; i<TAM; i++){
        fscanf(fp, "%lf", &mega[i].premio);
    }
    /*
    for(i=0; i<TAM; i++){
        printf("%.2lf\n", mega[i].premio);
    }
    */
    /*********** FIM PREMIOS *************/


    /*********** NUMEROS SORTEADOS *************/
    /* Faz o Vetor Receber os Numeros dos Arquivos Textos*/
    fopen("sorteios.txt", "r");

    if((fp = fopen("sorteios.txt", "r")) == NULL){
        printf("Arquivo nao pode ser aberto!\n");
        exit(1);
    }

    for(i=0; i<TAM; i++){
        for(k=0; k<6; k++){
            fscanf(fp, "%d", &mega[i].numeros[k]);
        }
    }
    /* Imrpime esses vetores *//*
    for(i=0; i<TAM; i++){
        for(k=0; k<6; k++){
            printf("%2d ", mega[i].numeros[k]);
        }
        printf("\n");
    }*/
    /*********** FIM NUMEROS SORTEADOS *************/

    /*********** RECEBE APOSTAS DO USUARIO *************/

    for(i=0; i<6; i++){

        printf("Digite o %do numero da sua aposta: ", i+1);
        scanf("%d", &aposta[i]);

        // Esse if testa se o n�mero � maior que 60 ou menor que 1 e aponta o erro //
        if(aposta[i] > 60 || aposta[i] < 1 ){
            printf("Por favor, digite numeros entre 1 e 60.\n");
            i--;
        }

        // Esse if testa se o n�mero j� foi digitado antes //
        else if(aposta[i]==aposta[i-1] || aposta[i]==aposta[i-2] ||
                aposta[i]==aposta[i-3] || aposta[i]==aposta[i-4] ||
                aposta[i]==aposta[i-5] || aposta[i]==aposta[i-6]){
            printf("Numero Repetido! Digite novamente:\n");
            i--;
        }
    }

    /*********** FIM RECEBE APOSTAS DO USUARIO *************/


    /*********** ORDENA A APOSTA RECEBIDA DE FORMA CRESCENTE *************/
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

    /* iMPRIME APOSTA POR ORDEM CRESCENTE*//*
    printf("\nSua aposta com ordem Crescente:\n ");
    for(i=0; i<6; i++){
        printf("%2d ", aposta_ordenada[i]);
    }
    printf("\n");
    */
    /*********** FIM ORDENA A APOSTA RECEBIDA DE FORMA CRESCENTE *************/

    /*********** IMPRIME A A APOSTA DO USUARIO *************/
    //system("CLS");
    /* Ordem de Insercao*/
    printf("\nSua aposta foi:\n");
    for(i=0; i<6; i++){
        printf("%2d ", aposta[i]);
    }
    printf("\n");

    /* Ordem Crescente*/
    printf("\nSua aposta com ordem Crescente:\n");
    for(i=0; i<6; i++){
        printf("%2d ", aposta_ordenada[i]);
    }
    printf("\n");
    /*********** FIM IMPRIME A A APOSTA DO USUARIO *************/


    /*********** ESSA APOSTA J� FOI SORTEADA? *************/
    for(i=0; i<TAM; i++){

        for(k=0; k<=6; k++){

            if(aposta_ordenada[k] == mega[i].numeros[k]){
                cont = cont + 1;
            }

            else if(cont == 6){
                printf("\nSua aposta ja foi sorteada no:\nConcurso: \t%d \nData: \t\t%s \nPremio: \tR$%.1lf \n", mega[i].concurso, mega[i].data, mega[i].premio);
                //system("PAUSE");
                cont = 0;
                flag = 1;
            }
        }
        cont = 0;
    }

    if(flag == 0 ){
        printf("\n---------- SUA APOSTA NUNCA FOI SORTEADA D: ----------\n"
                "!- Voce pode pegar alguma aposta no arquivo sorteios.txt e testar -!\n");
    }
    /*********** FIM ESSA APOSTA J� FOI SORTEADA? *************/


    /*********** TOP 10 N�MEROS MAIS SORTEADOS DE TODOS OS TEMPOS *************/
    /* Inicia top60[i][1](numeros de 1 at� 60) e top60[i][1](quantas vezes foram sorteados) com 0*/
    for(i=0; i<60; i++){
        //for(k=0; k<1; k++){
        top60[i][0] = i+1;
        //}
        top60[i][1] = 0;
    }
    /*
    for(i=0; i<60; i++){
        //for(k=0; k<1; k++){
            printf("%d ", top60[i][1]);
            printf("~%d ", top60[i][2]);
        //}
        printf("\n");
    }

    /* Compara quantas vezes o [i]n�mero aparece em todos os jogos*/
    for(i=0; i<60; i++){
        for(k=0; k<TAM; k++){
            for(j=0; j<6; j++){
                if(top60[i][0] == mega[k].numeros[j]){
                    top60[i][1] = top60[i][1] + 1;
                    break;
                }
            }
        }
    }
    /* */
    flag = 0;
    for(i=0; i<10; i++){
        for(k=0; k<2; k++){
            top10[i][k] = 0;
        }
    }

    /* faz top10 receber os dez maiores numeros de top60 */
    for(i=0; i<10; i++){

      aux = top10[i][1];

        for(k=0; k<60; k++){

            if((top60[k][1] >= aux) && top60[k][0] != top10[i-1][0]
                                    && top60[k][0] != top10[i-2][0]
                                    && top60[k][0] != top10[i-3][0]
                                    && top60[k][0] != top10[i-4][0]
                                    && top60[k][0] != top10[i-5][0]
                                    && top60[k][0] != top10[i-6][0]
                                    && top60[k][0] != top10[i-7][0]
                                    && top60[k][0] != top10[i-8][0]
                                    && top60[k][0] != top10[i-9][0]){

                aux = top60[k][1];
                aux2 = top60[k][0];
            }
        }

        top10[i][1] = aux;
        top10[i][0] = aux2;
    }
    printf("\nOs 10 numeros mais sorteados de todos os tempos sao:\n");
    for(i=0; i<10; i++){
        printf("%2do - \t%2d sorteado %d vezes\n", i+1, top10[i][0], top10[i][1]);
    }

    /* printf("\nO numero %d ja apareceu %d vezes.", top60[59][0], top60[59][1]);*/

    /*********** TOP 10 N�MEROS MAIS SORTEADOS DE TODOS OS TEMPOS *************/




    /*********** MAIOR E MENOR PREMIOS JA RATEADOS *************/
    /* Menor*/
    aux_lf= 666666666666.66;

    for(i=0; i<TAM; i++){

        if(mega[i].premio < aux_lf && mega[i].premio != 0.00 ){

            aux_lf = mega[i].premio;
        }
    }
    printf("\nO menor premio ja sorteado foi: R$%d,%.2lf", (((int)aux_lf)/1000), ((aux_lf) - ((((int)aux_lf)/1000)*1000)));

    /* Maior */
    aux_lf = 0.00;

    for(i=0; i<TAM; i++){

        if(mega[i].premio > aux_lf ){

            aux_lf = mega[i].premio;
        }
    }
    printf("\nO maior premio ja sorteado foi: R$%d,%d,%.2lf\n",(((int)aux_lf)/1000000),
                                                             ((int)((aux_lf) - ((((int)aux_lf)/1000000)*1000000)) /1000),
                                                            //((((int)aux_lf)/1000000)*1000000) //119.000.000
                                                             //(((int)((aux_lf) - ((((int)aux_lf)/1000000)*1000000)) /1000)*1000) //142.000
                                                             ((aux_lf) - ((((int)aux_lf)/1000000)*1000000)) -
                                                             (((int)((aux_lf) - ((((int)aux_lf)/1000000)*1000000)) /1000)*1000)
            );

    /*********** MAIOR E MENOR PREMIOS JA RATEADOS *************/

}


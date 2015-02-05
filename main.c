//guilmour.com
#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao=0;
    printf("SEGUNDA LISTA DE EXERCICIOS - GUILMOUR ROSSI - PROG1 - PROF ROBSON LINHARES");

    printf("\n************************************************************************\n");
    printf("\t\t\tEscolha um dos exercicios:\n\t\t\t1 : Exercicio 62.");
    printf("\n\t\t\t2 : Exercicio 75.");
    printf("\n\t\t\t3 : Exercicio 110.");
    printf("\n\t\t\t4 : Exercicio 119.");
    //printf("\n\t\t\t5 : Exercicio 124.");
    printf("\n\t\t\t5 : Exercicio 124.");
    printf("\n\t\t\t6 : SAIR");
    printf("\n\n************************************************************************\n");

    scanf("%d", &opcao);

    if (opcao == 1){
        system("CLS");
        exercicio62();
        printf("\n");
        system("PAUSE");
        system("CLS");
        opcao = 0;
        main();
    }
    else if (opcao == 2){
        system("CLS");
        exercicio75();
        printf("\n");
        system("PAUSE");
        system("CLS");
        opcao = 0;
        main();
    }
    else if (opcao == 3){
        system("CLS");
        exercicio110();
        printf("\n");
        system("PAUSE");
        system("CLS");
        opcao = 0;
        main();
    }
    else if (opcao == 4){
        system("CLS");
        exercicio119();
        //printf("\n");
        //system("PAUSE");
        system("CLS");
        opcao = 0;
        main();
    }
    else if (opcao == 5){
        system("CLS");
        exercicio124_2();
        printf("\n");
        system("PAUSE");
        system("CLS");
        opcao = 0;
        main();
    }
    /*
    else if (opcao == 6){
        system("CLS");
        exercicio124_2();
        printf("\n");
        system("PAUSE");
        system("CLS");
        opcao = 0;
        main();
    }
    */
    else if (opcao == 6){
        exit;
    }






}

//guilmour.com
#include <stdio.h>
#include <stdlib.h>

void cebolinhaString(char* frase, char* buffer);

void exercicio110(){
    printf("Exercicio 110:(Cortesia do Prof. Bogdan Tomoyuki Nassu) Cebolinha e\n"
            "tum personagem de historia em quadrinhos que quando fala, troca o R\n"
            "tpelo L. Escreva uma funcao cebolinhaString, que recebe uma string s\n"
            "te um buffer (um vetor capaz de armazenar outra string com o mesmo\n"
            "tamanho de s) e armazene no buffer uma versao de s com todos os R's\n"
            "trocados por L's, exceto quando o R e a ultima letra de uma palavra.\n"
            "Dois R's seguidos devem ser substituídos por um unico L. Lembre-se\n"
            "de manter as letras maiusculas e minusculas como no texto original.\n\n****************************************\n\n\n");
    char frase[100], buffer[100];
    int i;
    printf("Digite uma frase com muitos 'r' para o cebolinha traduzir :\n");
    gets(frase);
    fgets(frase, 100, stdin);
    //printf("%s\n", frase);
    cebolinhaString(&frase, &buffer);
    printf("%s\n", buffer);

}

void cebolinhaString(char *frase, char *buffer){
    //COPIE  E ELIMINA OS DOIS RR
    int i, k=0, j=0;

    for(i=0; i<100; i++){

        //ANALISA SE EXISTEM DOIS 'R' SEGUIDOS
        if ((frase[i+k] == 'r' && frase[i+k-1] == 'r') || (frase[i+k] == 'R' && frase[i+k-1] == 'R')){
            k++;
            buffer[i] = frase[i+k];
        }

        else {
            buffer[i] = frase[i+k];
        }
    }

    //SUBSTITUI R POR L AO MENOS QUE NAO ESTEJA NO FINAL DA FRASE
    for(i=0; i<100; i++){

        if (buffer[i] == 'r' &&(buffer[i+1] != '.' && buffer[i+1] != '\n' && buffer[i+1] != ',' && buffer[i+1] != ' '))
            buffer[i] = 'l';

        else if(buffer[i] == 'R' &&(buffer[i+1] != '.' && buffer[i+1] != '\n' && buffer[i+1] != ',' && buffer[i+1] != ' '))
            buffer[i] = 'L';
    }

}



//guilmour.com
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    double valor;
    int quantidade;
}Item;

int k=0, i=0; //variavel global
Item item[5];

void preenche(){
    for(i=0; i<50; i++){
        item[i].nome[i] = '\0';
    }
}

void exercicio119(){
    printf("119. Fazer um programa para gerenciamento de compras em um supermercado, com as\n"
            "seguintes caracteristicas:\n"
            "\na-O programa deve mostrar um menu de opcoes ao usuario: adicionar item, remover\n"
            "item, obter valor total da compra, mostrar relatorio (lista de itens) e sair.\n"
            "\nb. O programa deve definir o tipo de registro Item, que pretende representar\n"
            "um item sendo comprado no supermercado.\n"
            "\ti. Campos: nome do item, valor unitario e quantidade.\n"
            "\nc. O programa deve definir um array (vetor) para permitir criar uma lista de\n"
            "compras num supermercado. O tamanho inicial do array deve ser 5 e deve aumentar\n"
            "a medida que mais do que 5 elementos sejam adicionados a lista (dica: utilizar\n"
            "alocacao e desalocacao dinamicas)\n\n\n***************************************************************************\n\n");
    preenche();
    menu();
}

void menu(){
    int k=0, opcao=0; //quantos itens passuem a lista
    printf("MENU:\n");
    printf("1-ADICIONAR ITEM\n");
    printf("2-REMOVER ITEM\n");
    printf("3-VALOR TOTAL\n");
    printf("4-RELATORIO\n"); //LISTA DE ITENS
    printf("5-SAIR\n"); //LISTA DE ITENS

    scanf("%d", &opcao);

    if (opcao == 1){
        addItem();
        printf("\nItem Adicioando com Sucesso!\n");
        system("PAUSE");
        system("CLS");
        menu();
    }
    else if (opcao == 2){
        delItem();
        system("PAUSE");
        system("CLS");
        menu();
    }
    else if (opcao == 3){
        Total();
        system("PAUSE");
        system("CLS");
        menu();
    }
    else if (opcao == 4){
        Relatorio();
        printf("\n----fim-----\n");
        system("PAUSE");
        system("CLS");
        menu();
    }
    else if (opcao == 5){
        exit;
    }
}

void addItem(){
    printf("\n***********\nNome do Item: ");
    //fflush(stdin);
    //scanf("%[^\n]s", item[k].nome);
    gets(item[k].nome);
    fgets(item[k].nome, 50, stdin);
    printf("Valor do Item: ");
    scanf("%lf", &item[k].valor);
    printf("Quantidade: ");
    scanf("%d", &item[k].quantidade);
    k++;
}

void Relatorio(){

    for(i=0; i<k; i++){
    printf("%d. Item: %s", i+1, item[i].nome);
    }

}

void Total(){
    double total;
    for(i=0; i<k; i++){
    total = total + (item[i].valor * item[i].quantidade) ;
    }
    printf("\nTOTAL DA COMPRA: R$%.2lf\n", total );
}

void delItem(){
    int c=0;
    printf("Qual item deseja deletar?\n");
    Relatorio();
    printf("\n");
    scanf("%d", &c);
    for(i=0; i<k; i++){
        //strcpy(item[c-1+i].nome, item[c+i].nome);
        strcpy(item[c-1+i].nome, item[c+i].nome);
        item[c-1+i].valor = item[c+i].valor;
        item[c-1+i].quantidade = item[c+i].quantidade;
    }
    k--;
    /*
    for(i=0; i<k; i++){
        strcpy(item[c-1].nome, item[c].nome);
        item[c-1].valor = item[c].valor;
        item[c-1].quantidade = item[c].quantidade;
    }*/

    //item[c-1].nome = '\0';

}

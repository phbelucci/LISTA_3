#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MENU             0
#define VENDAS           1
#define BUSCA_VENDA      2
#define LISTA_VENDA      3
#define VENDA_PRAZO      4
#define VENDA_VISTA      5
#define LUCRO_TOTAL      6
#define MAIOR_LUCRO      7
#define SAIR             8


typedef struct {
        int codigo;
        char descr[10];
        float preco_custo;
        float preco_venda;
        float lucro;
        int qtd_estoque;
    } Produtos;

typedef struct {
        int registro;
        char prod_vend[10];
        int qtd_venda;
        float total_venda;
        char forma_pgto;
        float lucro;
    } Vendas;

    Produtos prod   [10];
    Vendas venda    [100];


void maior_lucro (){

    system("cls");
    printf("*************** PRODUTO COM MAIOR LUCRO ***************\n\n");

    int i;
    float maior = -9999;

    for (i=0; i<5 ; i++){

        if (prod[i].lucro > maior){

            maior = prod[i].lucro;

        }

    }
    printf("O MAIOR LUCRO É: %.2f\n\n", maior);
    system("pause");
    system("cls");
    menu();

}


void lucro_total(){

    int i;
    float lucro_total = 0;

    system("cls");
    printf("*************** LUCRO TOTAL DA VENDAS ***************\n\n");

    for (i = 0; i <100 ; i ++){
        lucro_total = lucro_total + venda[i].lucro;
    }
    printf("LUCRO TOTAL DA VENDAS: R$ %.2f\n\n", lucro_total);

    system("pause");
    system("cls");
    menu();


}

void total_prazo(){

    int total_prazo = 0;
    int cont_prazo;

    system("cls");
    printf("*************** TOTAL VENDAS PRAZO ***************\n\n");

    for (cont_prazo = 0; cont_prazo <100; cont_prazo ++){
        venda[cont_prazo].forma_pgto = toupper(venda[cont_prazo].forma_pgto);
        if ((venda[cont_prazo].forma_pgto == 'P') || (venda[cont_prazo].forma_pgto == 'p')) {
            total_prazo = total_prazo + 1;
        }
    }
    printf("TOTAL DE VENDAS A PRAZO: %i\n\n", total_prazo);


    system("pause");
    system("cls");
    menu();




}

void total_vista(){

    int total_vista = 0;
    int cont_vista;

    system("cls");
    printf("*************** TOTAL VENDAS VISTA ***************\n\n");

    for (cont_vista = 0; cont_vista <100; cont_vista ++){
        venda[cont_vista].forma_pgto = toupper (venda[cont_vista].forma_pgto);
        if ((venda[cont_vista].forma_pgto == 'V') || (venda[cont_vista].forma_pgto == 'v')){
            total_vista = total_vista + 1;
        }
    }
    printf("TOTAL DE VENDAS A VISTA: %i\n\n", total_vista);

    system("pause");
    system("cls");
    menu();

}

void procura_venda(){

    int cont_busca;
    int opcao_busca;

    system("cls");
    printf("*************** BUSCA VENDAS ***************\n\n");

    printf("DIGITE O CODIGO DA VENDA: ");
    scanf ("%i", &opcao_busca);

    for (cont_busca = 0; cont_busca <100; cont_busca ++){

            if (venda[cont_busca].registro == opcao_busca){

            printf("\n-------------- VENDA %i -------------- \n\n", venda[cont_busca].registro);
            printf("PRODUTO ESCOLHIDO: %s", venda[cont_busca].prod_vend);
            printf("\nQUANTIDADE ESCOLHIDA: %i", venda[cont_busca].qtd_venda);
            printf("\nVALOR TOTAL: %.2f", venda[cont_busca].total_venda);
            printf("\nFORMA DE PAGAMENTO: %c\n", venda[cont_busca].forma_pgto);

            }


    }

    printf("\n\n");
    system("pause");
    system("cls");
    menu();

}

void lista_vendas(){

    int cont_lista;
    system("cls");
    printf("*************** LISTA VENDAS ***************");
    for (cont_lista = 0; cont_lista <100; cont_lista ++){

            if (venda[0].registro == 0){
                printf("NÃO EXISTEM VENDAS EFETUADAS");
                break;
            }

            if (venda[cont_lista].registro != 0){

            printf("\n-------------- VENDA %i -------------- \n\n", venda[cont_lista].registro);
            printf("PRODUTO ESCOLHIDO: %s", venda[cont_lista].prod_vend);
            printf("\nQUANTIDADE ESCOLHIDA: %i", venda[cont_lista].qtd_venda);
            printf("\nVALOR TOTAL: %.2f", venda[cont_lista].total_venda);
            printf("\nFORMA DE PAGAMENTO: %c\n", venda[cont_lista].forma_pgto);

            }


    }
    printf("\n\n");
    system("pause");
    system("cls");
    menu();

}


void menu (){

    int opcao_menu = 0;

    printf("************ MENU ************\n\n");
    printf("1 - REALIZAR UMA NOVA VENDA.\n");
    printf("2 - PROCURAR UMA VENDA PELO NÚMERO DE REGISTRO.\n");
    printf("3 - LISTAR VENDAS.\n");
    printf("4 - TOTAL VENDAS A PRAZO.\n");
    printf("5 - TOTAL VENDAS A VISTA.\n");
    printf("6 - LUCRO TOTAL C/ VENDAS.\n");
    printf("7 - PRODUTO COM MAIOR LUCRO.\n");
    printf("8 - SAIR DO PROGRAMA.\n\n");


    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%i", &opcao_menu);

    while ((opcao_menu < 1) || (opcao_menu > 8)){
        printf("\nOPÇÃO INVÁLIDA!!!\n");
        printf("DIGITE OPÇÃO ENTRE 1 E 8: ");
        scanf("%[^a-z]i", &opcao_menu);
    }

    switch (opcao_menu){
        case VENDAS:
            system ("cls");
            printf("************ SISTEMA DE VENDAS ************\n\n");
            vendas();
            break;

        case BUSCA_VENDA:
            procura_venda();
            break;

        case LISTA_VENDA:
            lista_vendas();
            break;

        case VENDA_PRAZO:
            total_prazo();
            break;

        case VENDA_VISTA:
            total_vista();
            break;

        case LUCRO_TOTAL:
            lucro_total();
            break;

        case MAIOR_LUCRO:
            maior_lucro();
            break;

        case SAIR:
            break;

        default:
            printf("Caracter Invalido");
            menu();
            break;

        }

}

void cadastramento (){

    memset(&prod, 0, sizeof(Produtos));
    int cont_pl = 0;

    //INICIA CADASTRAMENTO DE PRODUTO

    for (cont_pl = 0; cont_pl <5 ; cont_pl ++){

            system ("cls");
            printf("****************** CADASTRAMENTO DE PRODUTO ******************\n\n");

            prod[cont_pl].codigo = cont_pl+1;
            printf("CÓD PRODUTO: %i\n\n", prod[cont_pl].codigo);


            printf("Digite o nome do produto: \n");
            scanf("%s", &prod[cont_pl].descr);


            printf("Digite o valor de custo do produto: \n");
            scanf("%f", &prod[cont_pl].preco_custo);


            printf("Digite o valor de venda do produto: \n");
            scanf("%f", &prod[cont_pl].preco_venda);


            printf("Digite a quantidade de estoque: \n");
            scanf("%i", &prod[cont_pl].qtd_estoque);

            prod[cont_pl].lucro = prod[cont_pl].preco_venda - prod[cont_pl].preco_custo;
            //printf("Lucro: %.2f\n", prod[cont_pl].lucro);
            //system("pause");



    }


    printf("****************** CADASTRAMENTO FINALIZADO******************\n\n");
    system("pause");
    system ("cls");

}

void vendas(){

    memset(&venda, 0, sizeof(Vendas));

    int cont_pl;
    int opcao_prod = 0;
    int opcao_qtd = 0;
    char opcao_nova_venda;
    int cont_venda = 0;


    //INICIA LOOP VENDA
    do {
    //TESTE CODIGO DA VENDA

    venda[cont_venda].registro = cont_venda + 1;
    printf("-------- REGISTRO DA VENDA: %i -------- \n\n", venda[cont_venda].registro);


    printf("PRODUTOS DISPONIVEIS: \n\n");
        for(cont_pl = 0; cont_pl <3; cont_pl ++){
            if (prod[cont_pl].qtd_estoque > 0){
            printf("CÓDIGO %i: %s - P_VENDA: %.2f - ESTOQUE : %i\n", prod[cont_pl].codigo, prod[cont_pl].descr, prod[cont_pl].preco_venda, prod[cont_pl].qtd_estoque);
            }
        }

    printf("\n\nDIGITE O CÓDIGO DO PRODUTO [1 a 10]: ");
    scanf("%i", &opcao_prod);

    while (prod[opcao_prod-1].qtd_estoque <= 0){
        printf("PRODUTO NÃO DISPONÍVEL!");
        printf("\n\nDIGITE O CÓDIGO DO PRODUTO [1 a 10]: ");
        scanf("%i", &opcao_prod);
    }

        while ((opcao_prod < 1) || (opcao_prod > 10)){
            printf("\nOPÇÃO INVÁLIDA!!!\n");
            printf("DIGITE OPÇÃO ENTRE 1 E 10: \n");
            scanf("%i", &opcao_prod);
        }

    opcao_prod = opcao_prod - 1;
    printf("DIGITE A QUANTIDADE: ");
    opcao_qtd = 0;
    scanf("%i", &opcao_qtd);



    while (opcao_qtd > prod[opcao_prod].qtd_estoque){

        printf("NÃO É POSSÍVEL CONCLUIR A VENDA!\nQUANTIDADE SELECIONADA É MAIOR QUE A QUANTIDADE DE PROTUDO EM ESTOQUE!!!");
        printf("DIGITE A QUANTIDADE NOVAMENTE: ");
        opcao_qtd = 0;
        scanf("%i", &opcao_qtd);

    }

    while (opcao_qtd < 1){
        printf("\nOPÇÃO INVÁLIDA!!!\n");
        printf("DIGITE A QUANTIDADE MAIOR QUE 0: ");
        scanf("%i", &opcao_qtd);
    }



    for (cont_pl = 0; cont_pl < 3 ; cont_pl ++){
        if (opcao_prod == cont_pl){

            printf("\n\nPRODUTO ESCOLHIDO: %s\nQTD ESCOLHIDA: %i\nVALOR DA COMPRA: %.2f\n\n", prod[cont_pl].descr, opcao_qtd, prod[cont_pl].preco_venda*opcao_qtd);
            prod[cont_pl].qtd_estoque = prod[cont_pl].qtd_estoque - opcao_qtd;


            printf("QUAL A FORMA DE PAGAMENTO\nV - A VISTA\nP - A PRAZO\n\nOPÇÃO: ");
            scanf(" %c", &venda[cont_venda].forma_pgto);
            venda[cont_venda].forma_pgto = toupper(venda[cont_venda].forma_pgto);

            while ((venda[cont_venda].forma_pgto != 'V') && (venda[cont_venda].forma_pgto != 'P')){

                printf("OPÇÃO INVALIDA!!! DIGITE NOVAMENTE.\n");
                printf("V - A VISTA\nP - A PRAZO\n\nOPÇÃO: ");
                scanf(" %c", &venda[cont_venda].forma_pgto);
                venda[cont_venda].forma_pgto = toupper(venda[cont_venda].forma_pgto);
            }

            strcpy(venda[cont_venda].prod_vend, prod[cont_pl].descr);

            venda[cont_venda].qtd_venda = opcao_qtd;
            venda[cont_venda].total_venda = prod[cont_pl].preco_venda * venda[cont_venda].qtd_venda;
            venda[cont_venda].lucro = prod[cont_pl].lucro * opcao_qtd;



            system("cls");
            printf("\n\n**** RESUMO DA VENDA %i ****\n\n", venda[cont_venda].registro);
            printf("PRODUTO ESCOLHIDO: %s", venda[cont_venda].prod_vend);
            printf("\nQUANTIDADE ESCOLHIDA: %i", venda[cont_venda].qtd_venda);
            printf("\nVALOR TOTAL: %.2f", venda[cont_venda].total_venda);
            printf("\nFORMA DE PAGAMENTO: %c\n", venda[cont_venda].forma_pgto);
            printf("LUCRO DA COMPRA: %.2f", venda[cont_venda].lucro);


        }
    }


        printf("\n\nDESEJA REALIZAR NOVA VENDA? [S/N] ");
        scanf(" %c", &opcao_nova_venda);
        opcao_nova_venda = toupper(opcao_nova_venda);
        cont_venda ++;
        system("cls");

    } while (opcao_nova_venda == 'S');

    if (opcao_nova_venda == 'N'){
        system("cls");
        menu();
    }

}

int main(){

    setlocale(LC_ALL, "");

    //INICIA CADASTRAMENTO
    cadastramento();

    //INICIA MENU
    menu();


return 0;

}

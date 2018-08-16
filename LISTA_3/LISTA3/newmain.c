

#include <stdio.h>
#include <stdlib.h>


int main(){

    int cont_pl;
    int cont_pc;
    int cont_venda;

    typedef struct {
        int codigo;
        char descr;
        float preco_custo;
        float preco_venda;
        int qtd_estoque;
    } Produtos;

    typedef struct {
        int registro;
        char prod_vend;
        int qtd_venda;
        float total_venda;
        char pgto;
    } Vendas;

    Produtos prod[10][5];
    Vendas venda[10][5];

    for (cont_pl = 0; cont_pl <10 ; cont_pl ++){
        for (cont_pc = 0; cont_pc <5 ; cont_pc ++){
            switch (cont_pc){
                case 0:
                    prod[cont_pl][cont_pc].codigo += 1;
                    break;
                //case 1:
                    //printf("Digite o nome do produto: \n");
                    //scanf("%s", prod[cont_pl][cont_pc].descr);
                    //break;
                case 2:
                    printf("Digite o valor de custo do produto: \n");
                    scanf("%f", prod[cont_pl][cont_pc].preco_custo);
                    break;
                case 3:
                    printf("Digite o valor de venda do produto: \n");
                    scanf("%f", prod[cont_pl][cont_pc].preco_venda);
                    break;
                case 4:
                    printf("Digite a quantidade de estoque: \n");
                    scanf("%i", prod[cont_pl][cont_pc].qtd_estoque);
                    break;
            }


        }




    }









return 0;

}


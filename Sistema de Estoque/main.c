#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define tam_struct 300 // QUANTIDADE DE TIPOS DE PRODUTOS

struct MemoriaEstoque{

    int codigo;
    char nome[50];
    int qtdEstoque;
    float precoCusto;
    int qtdVendida;
    float precoVenda;

};

// MODULO DE MENU DE OPÇÕES
void menu(int *op, int quantidade){


    printf("PRODUTOS CADASTRADOS: %i\n", quantidade);
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²     M  E  N  U     ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²                                              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²                                              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²         [1] - CADASTRAR PRODUTO              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²                                              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²         [2] - ALTERAR PRODUTO                ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²                                              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²         [3] - EXCLUIR PRODUTO                ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²                                              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²         [4] - RELATORIO SIMPLES              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²                                              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²         [5] - RELATORIO COMPLETO             ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²                                              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²         [6] - SAIR                           ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²                                              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²   Version 1.0   ²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("OPCAO:");
    scanf("%i", op);

}

void cadastrarProduto(struct MemoriaEstoque *estoque, int *quantidade){

    int op, i = 0;
    int codigoTeste = 0, estoqueTeste = 0;
    float precoCustoTeste = 0, precoVendaTeste = 0;
    int boolean = 0;

    do{
        system("cls");
        printf("\n\n");
        printf("   CADASTRO DE PRODUTO\n\n");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²                           P R E E N C H A    O S    C A M P O S                      ²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n\n");

        if(*quantidade == 0){
            printf("CODIGO DO PRODUTO: ");
            scanf("%i", &estoque[*quantidade].codigo);
        }else{

            do{
                boolean = 0;
                printf("CODIGO DO PRODUTO: ");
                scanf("%i", &codigoTeste);

                for(i = 0; i < *quantidade; i++){

                    if(codigoTeste == estoque[i].codigo){
                        printf("CODIGO JÁ EXISTE! digite novamente\n");
                        boolean = 1;
                    }

                }
            }while(boolean == 1);
            estoque[*quantidade].codigo = codigoTeste;
            boolean = 0;

        }

        printf("NOME DO PRODUTO: ");
        scanf(" %[^\n]", estoque[*quantidade].nome);

        do{
            printf("DIGITE A QUANTIDADE: ");
            scanf("%i", &estoqueTeste);

            if(estoqueTeste <= 0){
                printf("QUANTIDADE DEVE SER MAIOR QUE 0!\n");
                boolean = 1;
            }else{
                boolean = 0;
                estoque[*quantidade].qtdEstoque = estoqueTeste;
            }

        }while(boolean == 1);

        do{
            printf("PRECO UNITARIO DE CUSTO: ");
            scanf("%f", &precoCustoTeste);

            if(precoCustoTeste <= 0){
                printf("O PRECO DEVE SER MAIOR QUE ZERO!\n");
                boolean = 1;
            }else{
                boolean = 0;
                estoque[*quantidade].precoCusto = precoCustoTeste;
            }

        }while(boolean == 1);

        do{
            printf("PRECO UNITARIO DE VENDA: ");
            scanf("%f", &precoVendaTeste);

            if(precoVendaTeste <= 0){
                printf("O PRECO DEVE SER MAIOR QUE ZERO!\n");
                boolean = 1;
            }else{
                boolean = 0;
                estoque[*quantidade].precoVenda = precoVendaTeste;
            }

        }while(boolean == 1);
        estoque[*quantidade].qtdVendida = 0;
        *quantidade = *quantidade + 1;

        system("cls");
        printf("PRODUTO CADASTRADO COM SUCESSO!\n");
        Sleep(2000);

        do{
            printf("DESEJA CADASTRAR OUTRO PRODUTO?: \n");
            printf("[1] - SIM\n");
            printf("[2] - NAO\n");
            printf("OPCAO: ");
            scanf("%i", &op);

            if(op != 1 && op != 2){
                printf("OPCAO INVALIDA!\n");
                Sleep(1000);
                system("cls");
            }

        }while(op != 1 && op != 2);

    }while(op != 2);
}

void alterarProduto(struct MemoriaEstoque *estoque, int *quantidade){

    int codigo, i = 0, teste = 0, op, indiceCodigo;
    int boolean = 0, novaQuantidade;
    float novoPreco;

    //do{

        system("cls");
        printf("\n\n");
        printf("   ALTERACAO DE PRODUTO\n\n");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²                           M E N U   D E   A L T E R A C A O                          ²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n\n");

        if(*quantidade == 0){
            printf("NAO TEM PRODUTOS EM ESTOQUE");
        }else{
            teste = 0;
            do{

            printf("DIDITE O CODIGO DO PRODUTO: ");
            scanf("%i", &codigo);

            for(i=0; i<*quantidade; i++){

                if(estoque[i].codigo == codigo){
                    teste = 1;
                    indiceCodigo = i;
                }
            }

            if(teste == 1){

                printf("CODIGO ENCONTRADO!\n\n");

                do{
                    printf("O QUE DESEJA ALTERAR?\n");
                    printf("[1] - PRECO\n");
                    printf("[2] - QUANTIDADE\n");
                    printf("OPCAO: ");
                    scanf("%i", &op);

                    if(op != 1 && op != 2){
                        printf("OPCAO INVALIDA! digite novamente\n");

                    }else if(op == 1){

                        printf("Codigo: %i\n", estoque[indiceCodigo].codigo);
                        printf("Preco: %2f\n", estoque[indiceCodigo].precoVenda);
                        printf("\n");
                        printf("DIGITE UM NOVO PRECO: ");
                        scanf("%f", &novoPreco);

                        estoque[indiceCodigo].precoVenda = novoPreco;


                        system("cls");
                        printf("PRECO ALTERADO COM SUCESSO!\n");
                        Sleep(2000);

                    }else{
                        printf("Codigo: %i\n", estoque[indiceCodigo].codigo);
                        printf("Quantidade em estoque: %i\n", estoque[indiceCodigo].qtdEstoque);
                        printf("\n");
                        printf("DIGITE UMA NOVA QUANTIDADE: ");
                        scanf("%i", &novaQuantidade);

                        estoque[indiceCodigo].qtdEstoque = novaQuantidade;

                        system("cls");
                        printf("QUANTIDADE ALTERADA COM SUCESSO!\n");
                        Sleep(2000);
                    }


                }while((op != 1 && op != 2));

                boolean = 1;
            }else{
                printf("CODIGO NAO ENCONTRADO!\n");
                boolean = 0;
            }


        }while(boolean == 0);


        }


    //}while();


}

void excluirProduto(struct MemoriaEstoque *estoque, int *quantidade){

    int codigo, i = 0, teste = 0, indiceCodigo;
    //struct MemoriaEstoque aux;



        if(*quantidade == 0){
            system("cls");
            printf("NAO TEM PRODUTOS EM ESTOQUE");
            Sleep(1500);
            system("cls");

        }else{

        system("cls");
        printf("\n\n");
        printf("   EXCLUIR PRODUTO\n\n");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²               M E N U   D E   E X C L U S A O   D E   P R O D U T O                  ²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n\n");


            teste = 0;

            do{
                printf("DIGITE O CODIGO DO PRODUTO");
                scanf("%i", &codigo);

                for(i=0; i< *quantidade; i++){

                    if(estoque[i].codigo == codigo){
                        teste = 1;
                        indiceCodigo = i;
                    }
                }

                if(teste == 1){
                    printf("CODIGO ENCONTRADO!\n\n");

                    if(*quantidade == 1){
                        *quantidade = *quantidade -1;
                        printf("PRODUTO EXCLUIDO COM SUCESSO!\n\n");
                        system("pause");
                    }else{

                        for(i=0; i < *quantidade; i++){

                            if(indiceCodigo == i){

                                estoque[indiceCodigo] = estoque[indiceCodigo+1];
                                indiceCodigo = indiceCodigo + 1;
                            }
                        }
                        *quantidade = *quantidade - 1;

                        printf("PRODUTO EXCLUIDO COM SUCESSO");
                    }


                }else{
                    printf("PRODUTO NAO ENCONTRADO! digite novamente\n\n");

                }

            }while(teste == 0);
        }

}

void exibirRelatorioSimples(struct MemoriaEstoque *estoque, int *quantidade){

    int i, lim = *quantidade -1, troca;
    struct MemoriaEstoque aux;

    if(*quantidade == 0){
        system("cls");
        printf("NAO EXISTEM PRODUTOS EM ESTOQUE!\n\n");
        Sleep(2000);
    }else{

        system("cls");
        printf("\n\n");
        printf("   RELATORIO DO ESTOQUE\n\n");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²               M E N U    R E L A T O R I O    D E   P R O D U T O S                  ²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n\n");

        if(*quantidade > 1){

            // METODO BOLHA PARA ORDENAR AS STRUCT PELA CODIGO DO PRODUTO
            do{
                troca = 0;
                for(i = 0; i<= lim-1; i++){

                    if(estoque[i].codigo > estoque[i+1].codigo){

                        aux = estoque[i];
                        estoque[i] = estoque[i+1];
                        estoque[i+1] = aux;
                        troca = 1;
                    }
                }
                lim = lim - 1;
            }while(troca == 1);

                printf("                   ====================== L I S T A ============================\n\n");

            for(i=0; i < *quantidade; i++){
                printf("\n\n");
                printf("=====================================\n");
                printf("CODIGO: %i\n", estoque[i].codigo);
                printf("\n");
                printf("NOME: %s\n", estoque[i].nome);
                printf("====================================\n");

          }
            system("pause");
        }else{

            printf("\n\n");
            printf("===================================\n");
            printf("CODIGO: %i\n", estoque[*quantidade-1].codigo);
            printf("\n");
            printf("NOME: %s\n", estoque[*quantidade-1].nome);
            printf("===================================\n");
            system("pause");
        }
    }
}

void exibirRelatorioCompleto(struct MemoriaEstoque *estoque, int *quantidade){

    int i, lim = *quantidade -1, troca;
    struct MemoriaEstoque aux;

    if(*quantidade == 0){
        system("cls");
        printf("NAO EXISTEM PRODUTOS EM ESTOQUE!\n\n");
        Sleep(2000);
    }else{

        system("cls");
        printf("\n\n");
        printf("   RELATORIO DO ESTOQUE\n\n");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²               M E N U    R E L A T O R I O    D E   P R O D U T O S                  ²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n\n");

        if(*quantidade > 1){

            // METODO BOLHA PARA ORDENAR AS STRUCT PELA CODIGO DO PRODUTO
            do{
                troca = 0;
                for(i = 0; i<= lim-1; i++){

                    if(estoque[i].codigo > estoque[i+1].codigo){

                        aux = estoque[i];
                        estoque[i] = estoque[i+1];
                        estoque[i+1] = aux;
                        troca = 1;
                    }
                }
                lim = lim - 1;
            }while(troca == 1);

                printf("                   ====================== L I S T A ============================\n\n");

            for(i=0; i < *quantidade; i++){
                printf("\n\n");
                printf("=====================================\n");
                printf("CODIGO: %i\n", estoque[i].codigo);
                printf("\n");
                printf("NOME: %s\n", estoque[i].nome);
                printf("\n");
                printf("QUANTIDADE EM ESTOQUE: %i", estoque[i].qtdEstoque);
                printf("\n");
                printf("PRECO UNITARIO DE CUSTO: %.2f", estoque[i].precoCusto);
                printf("\n");
                printf("PRECO UNITARIO DE VENDA: %.2f", estoque[i].precoVenda);
                printf("\n");
                printf("QUANTIDADE VENDIDA: %i", estoque[i].qtdVendida);
                printf("\n");
                printf("VALOR TOTAL DO PRODUTO EM ESTOQUE: %.2f", estoque[i].precoCusto * estoque[i].qtdEstoque);
                printf("\n");
                printf("VALOR TOTAL POR VALOR DE VENDA: %.2f", estoque[i].precoVenda * estoque[i].qtdEstoque);
                printf("\n");
                printf("LUCRO TOTAL POR ESTOQUE DE PRODUTO PRODUTO: %.2f", (estoque[i].precoVenda * estoque[i].qtdEstoque) - (estoque[i].precoCusto * estoque[i].qtdEstoque));
                printf("====================================\n");

          }
            system("pause");
        }else{

            printf("\n\n");
            printf("===================================\n");
            printf("CODIGO: %i\n", estoque[*quantidade-1].codigo);
            printf("\n");
            printf("NOME: %s\n", estoque[*quantidade-1].nome);
            printf("\n");
            printf("QUANTIDADE EM ESTOQUE: %i", estoque[*quantidade-1].qtdEstoque);
            printf("\n");
            printf("PRECO UNITARIO DE CUSTO: %.2f", estoque[*quantidade-1].precoCusto);
            printf("\n");
            printf("PRECO UNITARIO DE VENDA: %.2f", estoque[*quantidade-1].precoVenda);
            printf("\n");
            printf("QUANTIDADE VENDIDA: %i", estoque[*quantidade-1].qtdVendida);
            printf("\n");
            printf("VALOR TOTAL DO PRODUTO EM ESTOQUE: %.2f", estoque[*quantidade-1].precoCusto * estoque[*quantidade-1].qtdEstoque);
            printf("\n");
            printf("VALOR TOTAL POR VALOR DE VENDA: %.2f", estoque[*quantidade-1].precoVenda * estoque[*quantidade-1].qtdEstoque);
            printf("\n");
            printf("LUCRO TOTAL POR ESTOQUE DE PRODUTO PRODUTO: %.2f", (estoque[*quantidade-1].precoVenda * estoque[*quantidade-1].qtdEstoque) - (estoque[*quantidade-1].precoCusto * estoque[*quantidade-1].qtdEstoque));
            printf("===================================\n");
            system("pause");
        }
    }

}

int main()
{

    system("mode con:cols=100 lines=34"); // RESOLUÇÃO FIXA DE TELA
    system("color F0"); // TELA BRANCA COM LETRA PRETA

    struct MemoriaEstoque cadastros[tam_struct];
    int op = 0, quantidade = 0;

    do{
        system("cls");
        menu(&op, quantidade);

        switch(op){

        case 1:
                system("cls");
                cadastrarProduto(cadastros, &quantidade);
            break;

        case 2:
                system("cls");
                alterarProduto(cadastros, &quantidade);
            break;

        case 3:
                system("cls");
                excluirProduto(cadastros, &quantidade);
            break;

        case 4:
                system("cls");
                exibirRelatorioSimples(cadastros, &quantidade);
            break;

        case 5:
                system("cls");
                exibirRelatorioCompleto(cadastros, &quantidade);
            break;

        case 6:
            exit(0);
            break;

        default:

            printf("\n");
            printf("Opcao Invalida!");
            Sleep(500);
            system("cls");
            break;
        }

    }while(op != 7);


    return 0;
}

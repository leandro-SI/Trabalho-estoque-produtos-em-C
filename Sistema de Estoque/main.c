#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define tam_struct 300 // QUANTIDADE DE TIPOS DE PRODUTOS
#define tempo 70
#define tempoCarregar 40

/**
 ESTRUTURA COM TODAS AS VARIÁVEIS USADAS DE UM DETERMINADO PRODUTO CADASTRADO.

 OBS: PARA UM BOM FUNCIONAMENTO DO SISTEMA, NÃO DIGITE CARACTERES EM VARIÁVEIS
 DO TIPO INT OU FLOAT. VARIAVEIS DO TIPO FLOAT QUE ARMAZENAM PREÇO, UTILIZE PONTO (.)
 PARA SEPARAR AS CASAS DECIMAIS.
*/
struct MemoriaEstoque{

    int codigo;
    char nome[50];
    int qtdEstoque;
    float precoCusto;
    int qtdVendida;
    float precoVenda;

};

/**
 FUNÇÃO RESPONSÁVEL POR APRESENTAR O MENU DE OPÇÕES DO SISTEMA
 - @Param op: OPCAO DO MENU QUE SERÁ PASSADO POR REFERENCIA PARA A FUNÇÃO MAIN
 - @Param quantidade: QUANTIDADE DE PRODUTOS CADASTRADO NO SISTEMA
*/
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

}//FIM DA FUNÇÃO

/**
 FUNCÇÃO RESPONSÁVEL POR CADASTRAR UM PRODUTO NO SISTEMA
 - @Param estoque: PONTEIRO PARA A STRUCT MEMORIA ESTOQUE
 - @Param quantidade: QUANTIDADE DE PRODUTO CADASTRADO NO SISTEMA
*/
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

        //CASO A QUANTIDADE EM ESTOQUE FOR 0, ELE ARMAZENA NA PRIMEIRA POSIÇÃO
        //DO VETOR DE STRUCT, SEM VERIFICAÇÃO.
        if(*quantidade == 0){
            printf("CODIGO DO PRODUTO: ");
            scanf("%i", &estoque[*quantidade].codigo);
        //CASO A QUANTIDADE EM ESTOQUE FOR MAIOR QUE 0, ELE VERIFICA SE JÁ EXISTE
        // O CODIGO NO SISTEMA.
        }else{
            do{
                boolean = 0;
                printf("CODIGO DO PRODUTO: ");
                scanf("%i", &codigoTeste);

                // VARRE O VETOR, CASO O CODIGO JÁ EXISTA ELE RETORNA UMA MENSAGEM DE ERRO
                // ATÉ QUE O USUÁRIO DIGITE UM CODIGO NÃO EXISTENTE
                for(i = 0; i < *quantidade; i++){
                    if(codigoTeste == estoque[i].codigo){
                        printf("CODIGO JÁ EXISTE! digite novamente\n");
                        boolean = 1;
                    }// FIM DO IF
                }// FIM DO FOR
            }while(boolean == 1);
            estoque[*quantidade].codigo = codigoTeste;
            boolean = 0;
        }// FIM DO ELSE

        printf("NOME DO PRODUTO: ");
        scanf(" %[^\n]", estoque[*quantidade].nome);

        do{
            printf("DIGITE A QUANTIDADE: ");
            scanf("%i", &estoqueTeste);
            // CONDIÇÃO PARA CADASTRO, VALOR DE ESTOQUE MAIOR QUE 0.
            if(estoqueTeste <= 0){
                printf("QUANTIDADE DEVE SER MAIOR QUE 0!\n");
                boolean = 1;
            }else{
                boolean = 0;
                estoque[*quantidade].qtdEstoque = estoqueTeste;
            }// FIM DO ELSE
        }while(boolean == 1);

        do{
            printf("PRECO UNITARIO DE CUSTO: ");
            scanf("%f", &precoCustoTeste);
            //CONDIÇÃO PARA CADASTRO, VALOR MAIOR QUE 0.
            if(precoCustoTeste <= 0){
                printf("O PRECO DEVE SER MAIOR QUE ZERO!\n");
                boolean = 1;
            }else{
                boolean = 0;
                estoque[*quantidade].precoCusto = precoCustoTeste;
            }// FIM DO ELSE
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
            }// FIM DO ELSE

        }while(boolean == 1);
        estoque[*quantidade].qtdVendida = 0;

        // FIM DO CADASTRO, INCREMENTA + 1 NO ESTOQUE PARA MANIPULAÇÃO DO VETOR DE STRUCT
        *quantidade = *quantidade + 1;
                                                        //P
        system("cls");
        printf("\n\n");
        printf("\t\t\t\tPRODUTO CADASTRADO COM SUCESSO!\n");
        Sleep(1500);

        do{
            printf("\n\n");
            printf("\t\t\t\tDESEJA CADASTRAR OUTRO PRODUTO?: \n\n");
            printf("\t\t\t\t\t[1] - SIM\n");
            printf("\t\t\t\t\t[2] - NAO\n");
            printf("\t\t\t\t\tOPCAO: ");
            scanf("%i", &op);

            if(op != 1 && op != 2){
                printf("OPCAO INVALIDA!\n");
                Sleep(1000);
                system("cls");
            }// FIM DO IF
        }while(op != 1 && op != 2);
    }while(op != 2);
}//FIM DA FUNÇÃO

/**
 FUNCÃO RESPONSAVEL POR FAZER ALTERAÇÃO EM UM DETERMINADO PRODUTO
 - @Param estoque: PONTEIRO PARA A STRUCT MEMORIA ESTOQUE
 - @Param quantidade: QUANTIDADE DE PRODUTO CADASTRADO NO SISTEMA
*/
void alterarProduto(struct MemoriaEstoque *estoque, int *quantidade){

        int codigo, i = 0, teste = 0, op, indiceCodigo;
        int boolean = 0, novaQuantidade;
        float novoPreco;

        if(*quantidade == 0){
            printf("\n\n\n\n\n");
            printf("\t\t\t\t   NAO TEM PRODUTOS EM ESTOQUE!");
            Sleep(2500);
        }else{

            system("cls");
            printf("\n\n");
            printf("   ALTERACAO DE PRODUTO\n\n");
            printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
            printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
            printf("²²²²²²²                           M E N U   D E   A L T E R A C A O                          ²²²²²²²");
            printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
            printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
            printf("\n\n");

            teste = 0;
            do{
            printf("DIGITE O CODIGO DO PRODUTO: ");
            scanf("%i", &codigo);

            // CASO O CODIGO PROCURADO SEJA ENCONTRADO, ELE MUDA A CONDIÇÃO DA VARIAVEL TESTE PARA 1,
            //E GUARDA O INDICE DO PRODUTO PESQUISADO.
            for(i=0; i<*quantidade; i++){
                if(estoque[i].codigo == codigo){
                    teste = 1;
                    indiceCodigo = i;
                }// FIM DO IF
            }// FIM DO FOR

            if(teste == 1){
                printf("\t\t\t\t\tCODIGO ENCONTRADO!\n\n");

                do{
                    printf("\t\t\t\t\tO QUE DESEJA ALTERAR?\n");
                    printf("\t\t\t\t\t[1] - PRECO\n");
                    printf("\t\t\t\t\t[2] - QUANTIDADE\n");
                    printf("\t\t\t\t\tOPCAO: ");
                    scanf("%i", &op);

                    if(op != 1 && op != 2){
                        printf("OPCAO INVALIDA! digite novamente\n");

                    }else if(op == 1){

                        printf("Codigo: %i\n", estoque[indiceCodigo].codigo);
                        printf("Preco: %.2f\n", estoque[indiceCodigo].precoVenda);
                        printf("\n");
                        printf("DIGITE UM NOVO PRECO: ");
                        scanf("%f", &novoPreco);
                        estoque[indiceCodigo].precoVenda = novoPreco;
                        system("cls");
                        printf("\n\n\n\n");
                        printf("\t\t\t\t\tPRECO ALTERADO COM SUCESSO!\n");
                        Sleep(2000);

                    }else{
                        printf("Codigo: %i\n", estoque[indiceCodigo].codigo);
                        printf("Quantidade em estoque: %i\n", estoque[indiceCodigo].qtdEstoque);
                        printf("\n");
                        printf("DIGITE UMA NOVA QUANTIDADE: ");
                        scanf("%i", &novaQuantidade);
                        estoque[indiceCodigo].qtdEstoque = novaQuantidade;
                        system("cls");
                        printf("\n\n\n\n");
                        printf("\t\t\t\tQUANTIDADE ALTERADA COM SUCESSO!\n");
                        Sleep(2000);
                    }// FIM DO ELSE
                }while((op != 1 && op != 2));

                boolean = 1;

            }else{
                printf("CODIGO NAO ENCONTRADO!\n");
                printf("\n");
                boolean = 0;
            }// FIM DO ELSE
        }while(boolean == 0);
    }
}//FIM DA FUNÇÃO

/**
 FUNÇÃO RESPONSÁVEL POR EXCLUIR UM DETERMINADO PRODUTO DO ESTOQUE
 - @Param estoque: PONTEIRO PARA A STRUCT MEMORIA ESTOQUE
 - @Param quantidade: QUANTIDADE DE PRODUTO CADASTRADO NO SISTEMA
*/
void excluirProduto(struct MemoriaEstoque *estoque, int *quantidade){

    int codigo, i = 0, teste = 0, indiceCodigo;

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
                printf("DIGITE O CODIGO DO PRODUTO: ");
                scanf("%i", &codigo);

                for(i=0; i< *quantidade; i++){
                    if(estoque[i].codigo == codigo){
                        teste = 1;
                        indiceCodigo = i;
                    }// FIM DO IF
                }// FIM DO FOR

                if(teste == 1){
                    printf("CODIGO ENCONTRADO!\n\n");

                    //CASO A QUANTIDADE FOR IGUAL A 1, ELE SÓ DECREMENTA O VETOR DE STRUCT
                    // E RETORNA A 0.
                    if(*quantidade == 1){
                        *quantidade = *quantidade -1;
                        printf("PRODUTO EXCLUIDO COM SUCESSO!\n\n");
                        Sleep(2000);

                    //CASO A QUANTIDADE FOR IGUAL A 1, ELE VERIFICA A POSIÇÃO ONDE ESTÁ O PRODUTO A SER EXCLUIR
                    // E SOBREPÔE ESSA POSIÇÃO DA DIREITA PARA A ESQUERDA REALOCANDO O VETOR DE STRUCT
                    // E DECREMENTA -1.
                    }else{

                        for(i=0; i < *quantidade; i++){
                            if(indiceCodigo == i){
                                estoque[indiceCodigo] = estoque[indiceCodigo+1];
                                indiceCodigo = indiceCodigo + 1;
                            }// FIM DO IF
                        }//FIM DO FOR
                        *quantidade = *quantidade - 1;
                        printf("PRODUTO EXCLUIDO COM SUCESSO");
                    }//FIM DO ELSE
                }else{
                    printf("PRODUTO NAO ENCONTRADO! digite novamente\n\n");
                }//FIM DO ELSE
            }while(teste == 0);
        }
}

/**
 FUNÇÃO RESPONSÁVEL POR EXIBIR UM RELATORIO DE TODOS OS PRODUTOS
 - @Param estoque: PONTEIRO PARA A STRUCT MEMORIA ESTOQUE
 - @Param quantidade: QUANTIDADE DE PRODUTO CADASTRADO NO SISTEMA
*/
void exibirRelatorioSimples(struct MemoriaEstoque *estoque, int *quantidade){

    int i, lim = *quantidade -1, troca;
    struct MemoriaEstoque aux;

    if(*quantidade == 0){
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t  NAO EXISTEM PRODUTOS EM ESTOQUE!\n\n");
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
            // METODO BOLHA PARA ORDENAR AS STRUCT PELO CODIGO DO PRODUTO
            do{
                troca = 0;
                for(i = 0; i<= lim-1; i++){
                    if(estoque[i].codigo > estoque[i+1].codigo){
                        aux = estoque[i];
                        estoque[i] = estoque[i+1];
                        estoque[i+1] = aux;
                        troca = 1;
                    }//FIM DO IF
                }//FIM DO FOR
                lim = lim - 1;
            }while(troca == 1);

                printf("                   ====================== L I S T A ============================\n\n");

                for(i=0; i < *quantidade; i++){
                printf("\n\n");
                printf("=====================================\n");
                printf("CODIGO: %i\n", estoque[i].codigo);
                printf("NOME: %s\n", estoque[i].nome);
                printf("QUANTIDADE EM ESTOQUE: %i\n", estoque[i].qtdEstoque);
                printf("=====================================\n");
          }//FIM DO FOR
                system("pause");
        }else{
            printf("\n\n");
            printf("===================================\n");
            printf("CODIGO: %i\n", estoque[*quantidade-1].codigo);
            printf("NOME: %s\n", estoque[*quantidade-1].nome);
            printf("QUANTIDADE EM ESTOQUE: %i\n", estoque[*quantidade-1].qtdEstoque);
            printf("===================================\n");
            system("pause");
        }
    }
}

/**
 FUNÇÃO RESPONSÁVEL POR EXIBIR UM RELATORIO COMPLETO DE TODOS OS PRODUTOS
 - @Param estoque: PONTEIRO PARA A STRUCT MEMORIA ESTOQUE
 - @Param quantidade: QUANTIDADE DE PRODUTO CADASTRADO NO SISTEMA
*/
void exibirRelatorioCompleto(struct MemoriaEstoque *estoque, int *quantidade){

    int i, lim = *quantidade -1, troca;
    struct MemoriaEstoque aux;

    if(*quantidade == 0){
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t  NAO EXISTEM PRODUTOS EM ESTOQUE!\n\n");
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
                    }//FIM DO IF
                }//FIM DO FOR
                lim = lim - 1;
            }while(troca == 1);

                printf("                   ====================== L I S T A ============================\n\n");

            for(i=0; i < *quantidade; i++){
                printf("\n\n");
                printf("=====================================\n");
                printf("CODIGO: %i\n", estoque[i].codigo);
                printf("NOME: %s\n", estoque[i].nome);
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
                printf("LUCRO TOTAL POR ESTOQUE DE PRODUTO: %.2f", (estoque[i].precoVenda * estoque[i].qtdEstoque) - (estoque[i].precoCusto * estoque[i].qtdEstoque));
                printf("\n");
                printf("====================================\n");

          }
            system("pause");
        }else{

            printf("\n\n");
            printf("===================================\n");
            printf("CODIGO: %i\n", estoque[*quantidade-1].codigo);
            printf("NOME: %s\n", estoque[*quantidade-1].nome);
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
            printf("LUCRO TOTAL POR ESTOQUE DE PRODUTO: %.2f", (estoque[*quantidade-1].precoVenda * estoque[*quantidade-1].qtdEstoque) - (estoque[*quantidade-1].precoCusto * estoque[*quantidade-1].qtdEstoque));
            printf("\n");
            printf("===================================\n");
            system("pause");
        }//FIM DO ELSE
    }//FIM DO ELSE
}//FIM DA FUNÇÃO

/**
 FUNÇÃO PARA DETERMINAR BARRA DE ROLAGEM NAS BORDAS DA INTERFACE.
 - @Param coluna: DETERMINA TAMANHO DA BARRA DE ROLAGEM NA HORIZONTAL.
 - @Param linha: DETERMINA TAMANHO DA BARRA DE ROLAGEM NA VERTICAL.
*/
void tela(int coluna, int linha) {
    COORD telasize;
    telasize.X=coluna;
    telasize.Y=linha;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),telasize);
}

void apresentacao(void){

    int i;

    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²  ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²           ²²²²²²²²       ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²  ²²²²²²²  ²²²²²²²²²²   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²  ²²²²²²²²²²²²²²²²²²²   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²  ²²²²²²²²²²²²²²²²²²²   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²           ²²²²²²²²²²   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²  ²²²²²²²²²²   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²  ²²²²²²²²²²   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²  ²²²²²²²  ²²²²²²²²²²   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²           ²²²  ²²²       ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²      ");
    for(i=0; i<1; i++){
        printf("S "); Sleep(tempo); printf("I "); Sleep(tempo); printf("S "); Sleep(tempo); printf("T "); Sleep(tempo);
        printf("E "); Sleep(tempo); printf("M "); Sleep(tempo); printf("A "); Sleep(tempo); printf("S "); Sleep(tempo);
        printf(" "); Sleep(tempo); printf(" ");  Sleep(tempo); printf(" ");  Sleep(tempo); printf("D ");  Sleep(tempo);
        printf("E "); Sleep(tempo); printf(" "); Sleep(tempo); printf(" "); Sleep(tempo); printf(" "); Sleep(tempo);
        printf("I "); Sleep(tempo); printf("N "); Sleep(tempo); printf("F "); Sleep(tempo); printf("O "); Sleep(tempo);
        printf("R "); Sleep(tempo); printf("M ");  Sleep(tempo); printf("A ");  Sleep(tempo); printf("C ");  Sleep(tempo);
        printf("A "); Sleep(tempo); printf("O "); Sleep(tempo); printf("      "); Sleep(tempo);
    }
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
    printf("²²²²²²²²²²²²²²²²²²²²²²²");
    printf("\n\n\n\n");
    printf("\t\t\t");
    printf("                     AGUARDE...\n");
    printf("\n");
    printf("\t");
    for(i=0; i<40; i++){
        printf("²²");
        Sleep(tempoCarregar);
    }
    Sleep(1000);
}//FIM FUNÇÃO


int main()
{

    system("mode con:cols=100 lines=34"); // RESOLUÇÃO FIXA DE TELA
    tela(100, 200);
    system("color F0"); // TELA BRANCA COM LETRA PRETA

    struct MemoriaEstoque cadastros[tam_struct];
    int op = 0, quantidade = 0;
    apresentacao();
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
            system("cls");
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\t\t     B Y E!");
            Sleep(2000);
            exit(0);
            break;

        default:
            printf("\n");
            printf("Opcao Invalida!");
            Sleep(500);
            system("cls");
            break;
        }//FIM DO SWITCH
    }while(op != 7);

    return 0;
}

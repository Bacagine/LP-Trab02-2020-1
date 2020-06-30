/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2020-01                         *
 *                                                                                *
 * Copyright (C) 2020                                                             *
 *                                                                                *
 * movimentacao.c: Arquivo com o desenvolvimento das funções da biblioteca        *
 * movimentacao.h                                                                 *
 *                                                                                *
 * bank é um caixa eletronico escrito em C que faz cadastro e listagem de contas, *
 * cadastro e listagem de movimentações de saque e de deposito.                   *
 *                                                                                *
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                                                                                *
 * Este programa é software livre; você pode redistribuí-lo e/ou modificá-lo      *
 * sob os termos da GNU General Public License conforme publicada pela Free       *
 * Software Foundation; quer a versão 2 da licença, ou (conforme você escolha)    *
 * qualquer versão posterior.                                                     *
 *                                                                                *
 * Este programa é distribuído com a esperança de que seja útil, mas SEM          *
 * QUALQUER GARANTIA; mesmo sem a garantia implícita de MERCANTIBILIDADE OU       *
 * ADEQUAÇÃO A UM DETERMINADO PROPÓSITO. Para mais detalhes, veja a               *
 * GNU General Public License.                                                    *
 *                                                                                *
 * Você deve ter recebido uma cópia da GNU General Public License juntamente      *
 * com este programa; caso contrário, veja <https://www.gnu.org/licenses/>        *
 *                                                                                *
 * Data de inicio: 29/06/2020                                                     *
 * Data da última modificação: 30/06/2020                                         *
 **********************************************************************************/

#include <stdio.h>
#include "../include/bank.h"
#include "../include/conta.h"
#include "../include/movimentacao.h"
#include "../include/fatec.h"

void cadastrar_movimentacao(void){
    setlocale(LC_ALL, "");
    
    FILE *arq_conta, *arq_mov;
    conta bankaccount;
    movimentacao movimentation;
    float resultado;
    //data date;
    
    if((arq_mov = fopen(ARQ_MOVIMENTACAO, "ab")) == NULL){
        clear_terminal();
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo movimentacao.dat!");
        stay();
        clear_buffer(); /* Limpamos o buffer aqui pois, caso o usuario 
                         * digite algo e de enter, o valor digitado não 
                         * será pego pelo menu */
        clear_terminal();
        return;
    }
    fseek(arq_mov, 0, SEEK_END); // Desloca o indicador de posição para o final do arquivo
    
    movimentation.num_conta = ftell(arq_mov) / sizeof(movimentacao) + 1; /* Pega o número atual da 
                                                                          * movimentação cadastrada em bytes
                                                                          * divide pelo tamanho da estrutura 
                                                                          * movimentação em bytes e soma + 1
                                                                          * 
                                                                          * Somamos 1 pois, o valor inicial da
                                                                          * movimentação não pode ser 0 e, o proximo 
                                                                          * valor da movimentação será a atual somado mais 1 */
    clear_terminal();
    printf("********Nova Movimentacao********\n");
    printf("Numero da movimentacao: %d\n", movimentation.num_conta);
    printf("Digite o numero da conta: ");
    scanf("%d", &bankaccount.num_conta);
    
    if((arq_conta = fopen(ARQ_CONTA, "rb")) == NULL){
        clear_terminal();      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não nenhum cliente cadastrado!");
        stay();          // Pausa a mensagem de erro no terminal
        clear_buffer();
        clear_terminal(); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    while(fread(&bankaccount, sizeof(conta), 1, arq_conta) > 0){
        if(bankaccount.num_conta == movimentation.num_conta){
            printf("\n%s\n\n", bankaccount.nome);
            printf("Data da movimentacao\n");
            printf("--------------------\n");
            printf("Digite a data: ");
            scanf("%d/%d/%d", &movimentation.dt_movimentacao.dia, &movimentation.dt_movimentacao.mes, &movimentation.dt_movimentacao.ano);
            printf("Digite o tipo de movimentacao\n(1 - saque, 2 - deposito): ");
            scanf("%d", &movimentation.tipo);
            
            while(movimentation.tipo != 1 && movimentation.tipo != 2){
                fprintf(stderr, "Erro! Digite apenas 1 ou 2\n");
                scanf("%d", &movimentation.tipo);
            }
            
            if(movimentation.tipo == 1){
                printf("Valor da movimentacao: R$ ");
                scanf("%f", &movimentation.valor);
                while(movimentation.valor <= 0){
                    fprintf(stderr, "Valor inválido!\n");
                    fprintf(stderr, "Por favor, digite um número maior que 0:\n");
                    printf("\nValor da movimentacao: R$ ");
                    scanf("%f", &movimentation.valor); 
                }
                bankaccount.saldo -= movimentation.valor;
                //bankaccount.saldo = resultado;
                fwrite(&movimentation, sizeof(movimentacao), 1, arq_mov);
                fclose(arq_mov);
                clear_terminal();      // Limpa o terminal após o termino do cadastrado da compra
                puts(MOV_SUCESS);    // Mostra a mensagem que foi definida em MOV_SUCESS
                stay();         /* Pausa a mensagem que está definida em
                                 * MOV_SUCESS no terminal */
                clear_buffer();
                clear_terminal(); // Limpa o terminal antes de voltar para o menu
            }
            else if(movimentation.tipo == 2){
                printf("Valor da movimentacao: R$ ");
                scanf("%f", &movimentation.valor);
                while(movimentation.valor <= 0){
                    fprintf(stderr, "Valor inválido!\n");
                    fprintf(stderr, "Por favor, digite um número maior que 0:\n");
                    printf("\nValor da movimentacao: R$ ");
                    scanf("%f", &movimentation.valor); 
                }
                bankaccount.saldo += movimentation.valor;
                //bankaccount.saldo = resultado;
                fwrite(&movimentation, sizeof(movimentacao), 1, arq_mov);
                fclose(arq_mov);
                clear_terminal();      // Limpa o terminal após o termino do cadastrado da compra
                puts(MOV_SUCESS);    // Mostra a mensagem que foi definida em MOV_SUCESS
                stay();         /* Pausa a mensagem que está definida em
                                 * MOV_SUCESS no terminal */
                clear_buffer(); /* Limpamos o buffer aqui pois, caso o usuario 
                                 * digite algo e de enter, o valor digitado não 
                                 * será pego pelo menu */
                clear_terminal(); // Limpa o terminal antes de voltar para o menu
            }
        }
    }
    if(bankaccount.num_conta != movimentation.num_conta){
        clear_terminal();
        printf("Não existe nenhuma conta com esse código\n");
        printf("Movimentacao interrompida!\n");
//             fclose(arq_cliente);
        stay();
        clear_buffer(); /* Limpamos o buffer aqui pois, caso o usuario 
                            * digite algo e de enter, o valor digitado não 
                            * será pego pelo menu */
        clear_terminal();
    }
    
    fclose(arq_conta);
    
}

void listar_movimentacoes(void){
    setlocale(LC_ALL, "Portuguese");
    
    FILE *arq;         // Declarando uma variavel de arquivo
    movimentacao movimentation;       // Declarando uma estrutura do tipo compra
    
    int cod_movimentation;
    int count;
    
    clear_terminal();
    fprintf(stdout, "********Consultar Movimentacoes********\n");
    fprintf(stdout, "Digite o código da conta: ");
    scanf("%d", &cod_movimentation);
    
    if((arq = fopen(ARQ_MOVIMENTACAO, "rb")) == NULL) {
        clear_terminal();      // Limpa o terminal ao entrar aqui
        puts(NOT_MOV);       // Mostra a mensagem que foi definida em NOT_MOV
        stay();          /* Pausa a mensagem que está definida em
                          * NOT_MOV no terminal */
        clear_buffer();
        clear_terminal(); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    clear_terminal();
    fprintf(stdout, "**********************************************************\n");
    fprintf(stdout, "#Código da Conta             Valor              Data      \n");
    fprintf(stdout, "**********************************************************\n");
    // Lê o arquivo e busca pelo nome digitado
    count = 0;
    while(fread(&movimentation, sizeof(movimentacao), 1, arq) > 0){
        if((movimentation.num_conta == cod_movimentation) != 0){
            fprintf(stdout, "%06d                       R$%.2f           %02d/%02d/%02d\n",
                                movimentation.num_conta, movimentation.valor,
                                movimentation.dt_movimentacao.dia,movimentation.dt_movimentacao.mes, movimentation.dt_movimentacao.ano);
            
            count++;
        }
    }
    fprintf(stdout, "**********************************************************\n");
    
    if(count == 0){
        clear_terminal();
        fprintf(stdout, "ERRO! Não houve nenhuma movimentacao para esta conta\n");
    }
    
    fclose(arq);            // Fecha o arquivo compras.dat
    
    stay();            /* Pausa o arquivo de cadastros 
                        * no terminal para que o usuario
                        * possa ver as compras cadastradas */
    clear_buffer();
    clear_terminal();  // Limpa o terminal antes de voltar para o menu
}

/*
int compara_datas(data, data){
    setlocale(LC_ALL, "Portuguese");
    
}
*/

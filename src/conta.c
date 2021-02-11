/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2020-01                         *
 *                                                                                *
 * Copyright (C) 2020                                                             *
 *                                                                                *
 * conta.c: Arquivo com o desenvolvimento das funções da biblioteca conta.h       *
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
 * Data da última modificação: 11/02/2021                                         *
 **********************************************************************************/

#include <stdio.h>
#include <fatec/fatec.h>
#include "../include/bank.h"
#include "../include/conta.h"

void cadastrar_conta(void){
    setlocale(LC_ALL, "");
    
    FILE *arq;          // Declarando uma variavel do tipo arquivo
    conta bankaccount; // Declarando uma estrutura do tipo conta
    char nome[51];    // Armazena o nome que o usuário digitar
    
    /* Cria um arquivo binaraio chamado contas.dat */
    if((arq = fopen(ARQ_CONTA, "ab")) == NULL){
        clear_terminal();
        fprintf(stderr, "Erro: não foi possível abrir o arquivo contas.dat!");
        stay(); // Simula o system("pause") do windows
        return;
    }
    fseek(arq, 0, SEEK_END); // Desloca o indicador de posição para o final do arquivo
    
    bankaccount.num_conta = ftell(arq) / sizeof(conta) + 1; /* Pega o número atual da 
                                                             * conta cadastradas em bytes
                                                             * divide pelo tamanho da estrutura 
                                                             * conta em bytes e soma + 1
                                                             * 
                                                             * Somamos 1 pois, o valor inicial da
                                                             * conta não pode ser 0 e, o proximo 
                                                             * valor da conta será a atual somado mais 1 */
    clear_terminal();
    printf("************Nova Conta************\n");
    printf("Número da conta: %d\n", bankaccount.num_conta); // Mostra o numero da conta que será cadastrado
    printf("Nome do cliente: ");
    scanf(" %50[^\n]", nome);
    clear_buffer();
    /*while(strlen(nome) > 50){
        fprintf(stderr, "Erro: o nome digitado excede 50 caracteres!\n");
        fprintf(stdout, "Por favor digite um nome menor: ");
        scanf(" %50[^\n]", nome);
    }*/
    /* Armazena o nome do cliente 
     * na estrutura bankaccount */
    strcpy(bankaccount.nome, nome);
    printf("Digite o saldo: ");
    scanf("%f", &bankaccount.saldo);
    loading("Cadastrando conta...");
    clear_buffer();
    fwrite(&bankaccount, sizeof(conta), 1, arq);
    fclose(arq);                 // Fecha o arquivo contas.dat
    clear_terminal();
    puts(BANKACCOUNT_SUCESS); // Mostra que a conta foi cadastrada com sucesso
    stay();                  /* Simula o system("pause") do windows */
}

void listar_contas(void){
    setlocale(LC_ALL, "");
    
    FILE *arq;          // Declarando uma variavel de arquivo
    conta bankaccount; //  Declarando uma estrutura do tipo conta
    
    /* Verifica se o arquivo contas.dat existe
     * e abre para leitura */
    if((arq = fopen(ARQ_CONTA, "rb")) == NULL) {
        clear_terminal();
        puts(NOT_BANKACCOUNT); // Mostra a mensagem de erro
        stay();               /* Simula o system("pause") do windows */
        return;
    }

    clear_terminal();
    fprintf(stdout, "\t\t\tContas Cadastrados\n");
    fprintf(stdout, "************************************************************************\n");
    fprintf(stdout, "#Conta      Nome do Cliente                                     Saldo   \n");
    fprintf(stdout, "************************************************************************\n");
    while(fread(&bankaccount, sizeof(conta), 1, arq) > 0){
        fprintf(stdout, "%06d      %-50.50s  R$%.2f\n", bankaccount.num_conta,
                                                        bankaccount.nome,
                                                        bankaccount.saldo);
    }
    fprintf(stdout, "************************************************************************\n");
    
    fclose(arq); // Fecha o arquivo contas.dat
    
    stay();     /* Pausa o arquivo de cadastros 
                 * no terminal para que o usuario
                 * possa ver as compras cadastradas */
}

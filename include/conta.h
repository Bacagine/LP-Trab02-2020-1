/* conta.h */

#ifndef _CONTA_H
#define _CONTA_H

/* Nome do arquivo aonde as contas bancárias são cadastrados */
#define ARQ_CONTA "contas.dat"

/* Estrutura que representa uma conta bancária */
typedef struct {
    int num_conta;
    char nome[51];
    float saldo;
} conta;

/* função que cadastra uma nova conta bancária no arquivo */
void cadastrar_conta(void);

/* função que exibe uma listagem no formato de tabela
 * mostrando o número da conta, nome e saldo de todas as
 * contas bancárias cadastradas */
void listar_contas(void);

#endif

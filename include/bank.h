/* Git Hub: https://github.com/Bacagine/LP-Trab02-2020-01
 * 
 * Copyright (C) 2020
 * 
 * bank.h: Biblioteca com as macros do programa bank
 * 
 * Biblioteca criada por Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * bank é um caixa eletronico escrito em C que faz cadastro e listagem de contas,
 * cadastro e listagem de movimentações de saque e de deposito.
 * 
 * Este programa é software livre; você pode redistribuí-lo e/ou modificá-lo
 * sob os termos da GNU General Public License conforme publicada pela Free
 * Software Foundation; quer a versão 2 da licença, ou (conforme você escolha)
 * qualquer versão posterior.
 * 
 * Este programa é distribuído com a esperança de que seja útil, mas SEM
 * QUALQUER GARANTIA; mesmo sem a garantia implícita de MERCANTIBILIDADE OU
 * ADEQUAÇÃO A UM DETERMINADO PROPÓSITO. Para mais detalhes, veja a
 * GNU General Public License.
 * 
 * Você deve ter recebido uma cópia da GNU General Public License juntamente
 * com este programa; caso contrário, veja <https://www.gnu.org/licenses/>
 * 
 * Data de criação: 29/06/2020
 * Data da última modificação: 07/07/2020
 */


#ifndef _BANK_H
#define _BANK_H

#define VERSION            "bank 20.07.07v2 (amd64)" // Versão da aplicação
#define HELP               "Usage: bank [option]\n\
\nbank é um caixa eletronico escrito em C que faz cadastro e listagem\n\
de contas, cadastro e listagem de movimentações de saque e de deposito\n\
\n\
Argumentos:\n\
  -v,   --version             Imprimir a versão e sai\n\
  -h,   --help                Imprimir a ajuda (esta mensagem) e sair\n\
  -dev, --developer           Mostra os desenvolvedores e sai\n\
  --license                   Mostra a licença do software e sai\n\
\t\tEssa aplicação contém segredos do tux maquinista =)" /* Mensagem de ajuda
                                                          * para o usuário */
/* Mensagem a ser 
 * mostrada após o 
 * cadastro da conta */
#define BANKACCOUNT_SUCESS "Conta cadastrada com sucesso!"

/* Mensagem a ser 
 * mostrada caso
 * não haja nenhuma
 * conta cadastrada */
#define NOT_BANKACCOUNT    "Erro: Não existe nenhuma conta cadastrada!"

/* Mensagem a ser 
 * mostrada após o 
 * saque */
#define SAQ_SUCESS         "Saque realizado com sucesso!"

/* Mensagem a ser 
 * mostrada após o 
 * deposito */
#define DEP_SUCESS         "Deposito realizado com sucesso!"

/* Mensagem a ser 
 * mostrada caso
 * não haja nenhuma
 * movimentação cadas-
 * trada */
#define NOT_MOV            "Erro: Não há nenhuma movimentação cadastrada!"

/* Tempo de carregamento
 * para a função loading */
#define SLEEP_US           100000

/* Arquivo com a licença do software */
#define LICENSE            "LICENSE"

#include <unistd.h> // Biblioteca necessária para a função loading

/* Barra de carregamento
 * 
 * Ela recebe como parametro
 * o texto que irá aparecer
 * para o usuário */
void loading(const char *str);

/* Verifica se foi passado
 * argumentos na função main
 * e, em caso positivo verifica
 * quais são esses argumentos */
int verifica_args(int num_args, char **args);

#endif

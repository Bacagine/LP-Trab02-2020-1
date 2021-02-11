/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2020-01                         *
 *                                                                                *
 * Copyright (C) 2020                                                             *
 *                                                                                *
 * bank.c: Arquivo com o menu da aplicação                                        *
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
#include "../include/movimentacao.h"
#include "../include/progressbar.h"
#include "../include/statusbar.h"
#include "../include/sl.h"

void menu(void){
    setlocale(LC_ALL, "");
    int op;
    loading("Loading...");
    do{
        clear_terminal();
        printf("*************MENU*************\n");
        printf("* 1) Cadastrar Conta         *\n");
        printf("* 2) Listar Contas           *\n");
        printf("* 3) Cadastrar Movimentacao  *\n");
        printf("* 4) Listar Movimentacoes    *\n");
        printf("* 5) Sair                    *\n");
        printf("******************************\n");
        printf("Option: ");
        scanf("%d", &op);
        clear_buffer();
        
        switch(op){
            case 1:
                cadastrar_conta();
                break;
            case 2:
                listar_contas();
                break;
            case 3:
                cadastrar_movimentacao();
                break;
            case 4:
                listar_movimentacoes();
                break;
            case 5:
                break;
            default:
                clear_terminal();
                puts(INVALID_OPTION);
                stay();
                break;
        }
        
    } while(op != 5);
}

void loading(const char *str){
    int max = 60;
    clear_terminal();
    for(int i = 0; i < 10; i++){
        printf("\n");
    }
    progressbar *smooth = progressbar_new(str, max);
    for(int i = 0; i < max; i++){
        usleep(SLEEP_US);
        progressbar_inc(smooth);
    }
    progressbar_finish(smooth);
}

int license(const char *l){
    FILE *arq;
    arq = fopen(l, "r");
    if(arq == NULL){
        fprintf(stderr, "Erro: Não foi possível exibir a licença deste software! =(\n");
        fprintf(stdout, "Você pode encontra-lá no site: <https://www.gnu.org/licenses/old-licenses/gpl-2.0.html>\n");
        return -1;
    }
    char line[10000];
    while(fgets(line, 10000, arq) != NULL){
        fputs(line, stdout);
    }
    fclose(arq);
    return 0;
}

void developers(void){
    setlocale(LC_ALL, "Portuguese");
    
    fprintf(stdout, "*************************DESENVOLVEDORES*************************\n");    
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* FATEC        -          Carapicuiba            -         2020 *\n");
    fprintf(stdout, "*---------------------------------------------------------------*\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *\n");
    fprintf(stdout, "* Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *\n");
    fprintf(stdout, "* Caio Elias Emerick Regino <caioregino.147@gmail.com>          *\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* bank é um caixa eletronico escrito em C que faz cadastro e    *\n");
    fprintf(stdout, "* listagem de contas, cadastro e listagem de movimentações de   *\n");
    fprintf(stdout, "* saque e de deposito                                           *\n");
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "*****************************************************************\n");
}

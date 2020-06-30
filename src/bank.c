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
 * Data da última modificação: 30/06/2020                                         *
 **********************************************************************************/

#include <stdio.h>
#include "../include/fatec.h"
#include "../include/bank.h"
#include "../include/conta.h"
#include "../include/movimentacao.h"
#include "../include/progressbar.h"
#include "../include/statusbar.h"

void menu(void){
    int op;
    loading();
    do{
        clear_terminal();
        printf("*************MENU*************\n");
        printf("* 1) Cadastrar Conta         *\n");
        printf("* 2) Listar Contas           *\n");
        printf("* 3) Cadastrar Movimentacao  *\n");
        printf("* 4) Listar Movimentacoes    *\n");
        printf("* 5) Comparar Datas          *\n");
        printf("* 6) Sair                    *\n");
        printf("******************************\n");
        printf("Option: ");
        scanf("%d", &op);
        
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
                //compara_datas();
                break;
            case 6:
                break;
            default:
                fprintf(stderr, "Erro!\nOpcao invalida! Por favor tente novamente: ");
        }
        
    } while(op != 6);
}

void loading(void){
    int max = 60;
    clear_terminal();
    for(int i = 0; i < 10; i++){
        printf("\n");
    }
    progressbar *smooth = progressbar_new("Loading...", max);
    for(int i = 0; i < max; i++){
        usleep(SLEEP_US);
        progressbar_inc(smooth);
    }
    progressbar_finish(smooth);
}

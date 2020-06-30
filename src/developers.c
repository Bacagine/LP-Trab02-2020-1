/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2020-1                          *
 *                                                                                *
 * Copyright (C) 2020                                                             *
 *                                                                                *
 * developers.c: Mostra os desenvolvedores da aplicação                           *
 *                                                                                *
 * bank é um caixa eletronico escrito em C que faz cadastro e listagem de contas, *
 * cadastro e listagem de movimentações de saque e de deposito.                   *
 *                                                                                *
 * Desenvolvedores: Gustavo Bacagine <gustavo.bacagine@protonmail.com>            *
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


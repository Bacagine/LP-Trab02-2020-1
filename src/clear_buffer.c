/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/LP-Trab02-2020-1                          *
 *                                                                                *
 * Aqui deverá vir uma breve explicação sobre a aplicação                         *
 *                                                                                *
 * clear_buffer.c: arquivo com o desenvolvimento do prototipo da função           *
 * clear_buffer da biblioteca buffer.h                                            *
 *                                                                                *
 * OBS: Essa função não foi desenvolvida por mim. Percebi que muitos              *
 * programadores se utilizam dessa função e passei a usa-lá em meus programas     *
 *                                                                                *
 * Versão: (aqui deve vir a versão da sua aplicação. Ex.: 1.0)                    *
 *                                                                                *
 * Desenvolvedores: Gustavo Bacagine          <gustavobacagine@gmail.com>         *
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
 * Data de inicio: 30/11/2019                                                     *
 * Data da última modificação: 30/06/2020                                         *
 **********************************************************************************/

#include <stdio.h>
#include "../include/fatec.h"

void clear_buffer(void){    
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

void buffer_clean(void){
    while(getchar() != '\n');
}

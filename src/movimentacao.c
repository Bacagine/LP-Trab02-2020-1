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
 * Data da última modificação: 07/07/2020                                         *
 **********************************************************************************/

#include <stdio.h>
#include "../include/bank.h"
#include "../include/conta.h"
#include "../include/movimentacao.h"
#include "../include/fatec.h"

void cadastrar_movimentacao(void){
    setlocale(LC_ALL, "");
    
    FILE *arq_conta, *arq_mov;    // Cria variaveis do tipo arquivo
    conta bankaccount;           // Cria uma estrutura do tipo conta
    movimentacao movimentation; // Cria uma estrutura do tipo movimentacao
    int num_conta; /* Codigo da conta que 
                    * o usuário deseja realizar 
                    * uma movimentação */
    int tipo; /* Armazena o tipo de movimen-
               * tação (1 - saque 2 - deposito) */
    float valor; /* Valor da movimentação 
                  * escolhido pelo usuário */
    
    /* Abre ou cria o arquivo movimentacao.dat */
    if((arq_mov = fopen(ARQ_MOVIMENTACAO, "ab")) == NULL){
        clear_terminal();
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo movimentacao.dat!");
        stay();
        return;
    }
    /* Desloca o indicador de 
     * posição para o final do 
     * arquivo */
    fseek(arq_mov, 0, SEEK_END);
    
    /* Abre o arquivo contas.dat para leitura e escrita */
    if((arq_conta = fopen(ARQ_CONTA, "r+b")) == NULL){
        clear_terminal();
        fprintf(stderr, "Erro: não nenhuma conta cadastrado!");
        stay(); // Simula o system("pause") do windows
        return;
    }
    
    clear_terminal();
    printf("********Nova Movimentacao********\n");
    printf("Digite o numero da conta: ");
    scanf("%d", &num_conta);
    /* Move o indicador de posição para o número anterior a 
     * conta digitada */
    fseek(arq_conta, (num_conta - 1) * sizeof(conta), SEEK_SET);
    /* Le a estrutura conta */
    fread(&bankaccount, sizeof(conta), 1, arq_conta);
    
    /* Verifica se o usuario digitou um numero 
     * de conta que não existe */
    if(feof(arq_conta) || num_conta <= 0){
        fprintf(stderr, "Erro! Não existe nenhuma conta com esse número\n");
        fprintf(stderr, "Movimentacao interrompida!\n");
        stay(); /* Simula o system("pause") do windows */
        return;
    }
    else{
        /* Verifica qual a conta em que o usuário deseja
         * realizar a movimentação */
        if(num_conta == bankaccount.num_conta){
            movimentation.num_conta = num_conta;
            printf("\n%s\n\n", bankaccount.nome);
            printf("Data da movimentacao\n");
            printf("--------------------\n");
            printf("Digite a data: ");
            scanf("%d/%d/%d", &movimentation.dt_movimentacao.dia, 
                              &movimentation.dt_movimentacao.mes, 
                              &movimentation.dt_movimentacao.ano);
            clear_buffer();
            printf("Digite o tipo de movimentacao\n(1 - saque, 2 - deposito): ");
            scanf("%d", &tipo);
            
            /* Enquanto o usario não digitar
             * 1 ou 2, será pedido para que
             * digite os valores novamente */
            while(tipo != 1 && tipo != 2){
                fprintf(stderr, "Erro! Digite apenas 1 ou 2\n");
                scanf("%d", &tipo);
            }
            
            movimentation.tipo = tipo;
            
            /* Se o usuario digitou 1
             * então será realizado um saque */
            if(movimentation.tipo == 1){
                printf("Valor da movimentacao: R$ ");
                scanf("%f", &valor);
                /* Caso o usuário digite
                 * um valor menor ou igual
                 * a zero de saque, será
                 * pedido para que digite
                 * um valor válido */
                while(valor <= 0){
                    fprintf(stderr, "Valor inválido!\n");
                    fprintf(stderr, "Por favor, digite um número maior que 0:\n");
                    printf("\nValor da movimentacao: R$ ");
                    scanf("%f", &valor);
                }
                clear_terminal();
                loading("Realizando saque...");
                /* Atribui o conteudo de valor
                 * a estrutura movimentation */
                movimentation.valor = valor;
                /* Muda o valor do saldo na conta */
                bankaccount.saldo -= valor;
                clear_buffer();
                /* Move o indicador de posição para a conta
                 * onde será realizada o saque */
                fseek(arq_conta, -sizeof(conta), SEEK_CUR);
                /* Teste */
                //fseek(arq_mov, sizeof(movimentacao), SEEK_CUR);
                /* Escreve as alterações nos arquivos conta.dat
                 * e movimentacoes.dat */
                fwrite(&bankaccount, sizeof(conta), 1, arq_conta);
                fwrite(&movimentation, sizeof(movimentacao), 1, arq_mov);
                clear_terminal();      // Limpa o terminal após o termino do cadastrado da compra
                puts(SAQ_SUCESS);    // Mostra a mensagem que foi definida em MOV_SUCESS
                stay();             /* Pausa a mensagem que está definida em
                                     * MOV_SUCESS no terminal */
            }
            /* Se o usuário digitar 2
             * será realizado um deposito */
            else if(movimentation.tipo == 2){
                printf("Valor da movimentacao: R$ ");
                scanf("%f", &valor);
                /* Caso o usuário digite
                 * um valor menor ou igual
                 * a zero de saque, será
                 * pedido para que digite
                 * um valor válido */
                while(valor <= 0){
                    fprintf(stderr, "Valor inválido!\n");
                    fprintf(stderr, "Por favor, digite um número maior que 0:\n");
                    printf("\nValor da movimentacao: R$ ");
                    scanf("%f", &valor);
                }
                clear_terminal();
                loading("Realizando deposito...");
                /* Atribui o conteudo de valor
                 * a estrutura movimentation */
                movimentation.valor = valor;
                /* Muda o valor do saldo na conta */
                bankaccount.saldo += valor;
                clear_buffer();
                /* Move o indicador de posição para a conta
                 * onde será realizada o deposito */
                fseek(arq_conta, -sizeof(conta), SEEK_CUR);
                /* Teste */
                //fseek(arq_mov, sizeof(movimentacao), SEEK_CUR);
                /* Escreve as alterações nos arquivos conta.dat
                 * e movimentacoes.dat */
                fwrite(&bankaccount, sizeof(conta), 1, arq_conta);
                fwrite(&movimentation, sizeof(movimentacao), 1, arq_mov);
                clear_terminal();
                puts(DEP_SUCESS); // Mostra que o deposito foi realizado com sucesso
                stay(); /* Simula o system("pause") do windows */
            }
        }
    }
    fclose(arq_conta); // Fecha o arquivo contas.dat
    fclose(arq_mov);  // Fecha o arquivo movimentacoes.dat
}

void listar_movimentacoes(void){
    setlocale(LC_ALL, "");
    
    FILE *arq_conta, *arq_mov;    // Declarando variaveis do tipo arquivo
    conta bankaccount;           // Desclarando uma estrutura do tipo conta
    movimentacao movimentation; // Declarando uma estrutura do tipo movimentacao
    data dt_inicial, dt_final; // Datas a serem digitadas pelo usuário
    
    int num_conta; // Número da conta a ser digitado pelo usuário
    int count;    // Contador
    int r;       // Variavel que pega o retorno da função compara_datas
    /* Dia, mes, ano e data inicial */
    int dia_i, mes_i, ano_i, dt_i;
    /* Dia, mes, ano e data final */
    int dia_f, mes_f, ano_f, dt_f;
    /* Matriz de caracteres que armazena os
     * tipos de movimentações (saque ou deposito) */
    const char tipo[2][8] = { "Saque", "Deposito" };
    
    /* Verifica se o arquivo contas.dat existe e abre
     * para leitura */
    if((arq_conta = fopen(ARQ_CONTA, "rb")) == NULL){
        clear_terminal();
        puts(NOT_MOV);
        stay(); // Pausa a mensagem de erro no terminal
        return;
    }
    
    clear_terminal();
    fprintf(stdout, "********Consultar Movimentacoes********\n");
    fprintf(stdout, "Digite o código da conta: ");
    scanf("%d", &num_conta);
    clear_buffer();
    count = 0;
    /* Lê a estrutura bankaccount */
    while(fread(&bankaccount, sizeof(conta), 1, arq_conta) > 0){
        /* Verifica se o número da conta esta 
         * presente na estrutura. Em caso posi-
         * tivo é somado + 1 a variavel count */
        if(num_conta == bankaccount.num_conta){
            count++;
        }
    }
    
    /* Verifica se a conta digitada pelo 
     * usuário não existe.
     * Caso não exista será mostrada uma
     * mensagem de erro e a consulta será
     * encerrada */
    if(count == 0){
        clear_terminal();
        fprintf(stderr, "Erro: Não existe nenhuma conta cadastrada com esse numero!\n");
        fprintf(stderr, "Consulta encerrada!\n");
        stay();          // Pausa a mensagem de erro no terminal
        return;
    }
    
    fclose(arq_conta); // Fecha o arquivo contas.dat
    
    /* Atribui o valor num_conta à estru-
     * tura movimentation */
    movimentation.num_conta = num_conta;
    
    /* Caso a conta exista o programa pedirá as datas
     * para verificar as movimentações no periodo 
     * especificado */
    fprintf(stdout, "Digite a data inicial: ");
    scanf("%d/%d/%d", &dia_i, &mes_i, &ano_i);
    clear_buffer();
    fprintf(stdout, "Digite a data final: ");
    scanf("%d/%d/%d", &dia_f, &mes_f, &ano_f);
    clear_buffer();
    
    /* Atribui os valores de data especificados pelo usuario nas suas
     * devidas estruturas */
    dt_inicial.dia = dia_i, dt_inicial.mes = mes_i, dt_inicial.ano = ano_i;
    dt_final.dia = dia_f, dt_final.mes = mes_f, dt_final.ano = ano_f;
    
    /* Pega o valor do retorno da função
     * compara_datas */
    r = compara_datas(dt_inicial, dt_final);
    
    /* No caso do retorno ser 1
     * (indicando que a data ini-
     * cial é maior que a final),
     * o programa pedirá para
     * o usuário digitar as datas
     * novamente */
    while(r == 1){
        fprintf(stderr, "Erro! A data inicial e maior que a data final!\n");
        fprintf(stdout, "Por favor digite novamente:\n");
        fprintf(stdout, "Digite a data inicial: ");
        scanf("%d/%d/%d", &dia_i, &mes_i, &ano_i);
        clear_buffer();
        fprintf(stdout, "Digite a data final: ");
        scanf("%d/%d/%d", &dia_f, &mes_f, &ano_f);
        clear_buffer();
        /* Atribui os valores de data especificados pelo usuario nas suas
         * devidas estruturas */
        dt_inicial.dia = dia_i, dt_inicial.mes = mes_i, dt_inicial.ano = ano_i;
        dt_final.dia = dia_f, dt_final.mes = mes_f, dt_final.ano = ano_f;
        /* Pega o valor do retorno da função
         * compara_datas */
        r = compara_datas(dt_inicial, dt_final);
    }
    
            
    /* Verifica se o arquivo movimentacoes.dat exite e
     * abre para leitura */
    if((arq_mov = fopen(ARQ_MOVIMENTACAO, "rb")) == NULL){
        clear_terminal(); // Limpa o terminal ao entrar aqui
        puts(NOT_MOV);   // Mostra mensagem de erro para o usuário
        stay();         /* Simula o system("pause") do windows */
        return;
    }
    
    clear_terminal();
    //printf("Retorno = %d", r);
    fprintf(stdout, "\tMovimentacoes Cadastradas\n");
    fprintf(stdout, "***********************************************\n");
    fprintf(stdout, "#Data             Tipo              Valor      \n");
    fprintf(stdout, "***********************************************\n");
    count = 0;
    // Lê o arquivo e busca pelo codigo digitado
    while(fread(&movimentation, sizeof(movimentacao), 1, arq_mov) > 0){
        /* Verifica se o número da conta é igual ao numero ditidato
         * pelo usuário */
        if((movimentation.num_conta == num_conta) != 0){
            /* Compara a data da movimentacao com a data inicial */
            dt_i = compara_datas(movimentation.dt_movimentacao, dt_inicial);
            /* Compara a data da movimentacao com a data final */
            dt_f = compara_datas(movimentation.dt_movimentacao, dt_final);
            /* Verifica se as datas são
             * iguais ou diferentes */
            if(dt_i == 0 || dt_f == 0 || dt_f == -1){
                /* Se o tipo de movimentacao
                 * for do tipo 1, será mostrado
                 * para o usuario saque */
                if(movimentation.tipo == 1){
                    fprintf(stdout, "%02d/%02d/%02d        %-8.8s          R$%.2f\n",
                                        movimentation.dt_movimentacao.dia, movimentation.dt_movimentacao.mes, movimentation.dt_movimentacao.ano, tipo[0], movimentation.valor);
                }
                /* Se o tipo de movimentacao
                 * for do tipo 2, será mostrado
                 * para o usuário deposito */
                else if(movimentation.tipo == 2){
                    fprintf(stdout, "%02d/%02d/%02d        %-8.8s          R$%.2f\n",
                                        movimentation.dt_movimentacao.dia, movimentation.dt_movimentacao.mes, movimentation.dt_movimentacao.ano, tipo[1], movimentation.valor);
                }
            /* Caso seja encontrado 
             * alguma movimentacao 
             * será adicionado +1 
             * ao contador */
            count++;
            }
        }
    }
    fprintf(stdout, "***********************************************\n");
    
    /* Se o count for 0
     * isso indica que o
     * laço while não encontrou
     * nenhuma movimentação
     * para a conta que o usuário
     * escolheu verificar */
    if(count == 0){
        clear_terminal();
        fprintf(stdout, "ERRO! Não houve nenhuma movimentacao para esta conta nesse periodo\n");
        stay();
        return;
    }
    
    fclose(arq_mov);        // Fecha o arquivo movimentacao.dat
    
    stay();            /* Pausa o arquivo de cadastros 
                        * no terminal para que o usuario
                        * possa ver as compras cadastradas */
}

int compara_datas(data dt1, data dt2){
    int d1, d2;
    
    d1 = dt1.ano * 10000 + dt1.mes * 100 + dt1.dia;
    d2 = dt2.ano * 10000 + dt2.mes * 100 + dt2.dia;
    
    /* Verifica se as datas 
     * são iguais */
    bool dts_iguais = d1 == d2;
    /* Verifica se a primeira 
     * data é menor que a 
     * segunda */
    bool dt1_menor = d1 < d2;
    
    /* Se as datas forem iguais a
     * função retorna 0 */
    if(dts_iguais == true){
        return 0;
    }
    /* Se a primeira data for menor 
     * que a data escolhida pelo
     * usuário a função retorna -1 */
    else if(dt1_menor == true){
        return -1;
    }
    /* Se a primeira data for maior
     * que a segunda data a função
     * retorna 1 */
    else{
        return 1;
    }
}

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
    int cod_bankaccount; /* Codigo da conta que 
                          * o usuário deseja realizar 
                          * uma movimentação */
    int tipo;
    float valor;      /* Valor da movimentação 
                       * escolhido pelo usuário */
    
    // Abre o arquivo movimentacao.dat
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
    
    /* Abre o arquivo contas.dat */
    if((arq_conta = fopen(ARQ_CONTA, "r+b")) == NULL){
        clear_terminal();      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não nenhuma conta cadastrado!");
        stay();          // Pausa a mensagem de erro no terminal
        clear_buffer();
        clear_terminal(); // Limpa o terminal antes de voltar para o menu
        return;
    }
    
    clear_terminal();
    printf("********Nova Movimentacao********\n");
    //printf("Numero da movimentacao: %d\n", movimentation.num_conta);
    printf("Digite o numero da conta: ");
    scanf("%d", &cod_bankaccount);
    fseek(arq_conta, (cod_bankaccount - 1) * sizeof(conta), SEEK_SET);
    fread(&bankaccount, sizeof(conta), 1, arq_conta);
    
    /* Verifica se o usuario digitou um numero 
     * de conta que não existe */
    if(feof(arq_conta) || cod_bankaccount <= 0){
        fprintf(stderr, "Erro! Não existe nenhuma conta com esse número\n");
        fprintf(stderr, "Movimentacao interrompida!\n");
        stay();
        clear_buffer();
        return;
    }
    else{
        //while(fread(&bankaccount, sizeof(conta), 1, arq_conta) > 0){ //Não use isso!!!!
            /* Verifica qual a conta em que o usuário deseja
             * realizar a movimentação */
            if(cod_bankaccount == bankaccount.num_conta){
                movimentation.num_conta = cod_bankaccount;
                printf("\n%s\n\n", bankaccount.nome);
                printf("Data da movimentacao\n");
                printf("--------------------\n");
                printf("Digite a data: ");
                scanf("%d/%d/%d", &movimentation.dt_movimentacao.dia, 
                                  &movimentation.dt_movimentacao.mes, 
                                  &movimentation.dt_movimentacao.ano);
                printf("Digite o tipo de movimentacao\n(1 - saque, 2 - deposito): ");
                scanf("%d", &tipo);
                
                while(tipo != 1 && tipo != 2){
                    fprintf(stderr, "Erro! Digite apenas 1 ou 2\n");
                    scanf("%d", &tipo);
                }
                
                movimentation.tipo = tipo;
                
                if(movimentation.tipo == 1){
                    printf("Valor da movimentacao: R$ ");
                    scanf("%f", &valor);
                    while(valor <= 0){
                        fprintf(stderr, "Valor inválido!\n");
                        fprintf(stderr, "Por favor, digite um número maior que 0:\n");
                        printf("\nValor da movimentacao: R$ ");
                        scanf("%f", &valor); 
                    }
                    movimentation.valor = valor;
                    bankaccount.saldo -= valor;
                    fseek(arq_conta, -sizeof(conta), SEEK_CUR);
                    fwrite(&bankaccount, sizeof(conta), 1, arq_conta);
                    fwrite(&movimentation, sizeof(bankaccount), 1, arq_mov);
                    clear_terminal();      // Limpa o terminal após o termino do cadastrado da compra
                    puts(MOV_SUCESS);    // Mostra a mensagem que foi definida em MOV_SUCESS
                    stay();             /* Pausa a mensagem que está definida em
                                         * MOV_SUCESS no terminal */
                    clear_buffer();   /* Limpamos o buffer aqui pois, caso o usuario 
                                       * digite algo e de enter, o valor digitado não 
                                       * será pego pelo menu */
                }
                else if(movimentation.tipo == 2){
                    printf("Valor da movimentacao: R$ ");
                    scanf("%f", &valor);
                    while(valor <= 0){
                        fprintf(stderr, "Valor inválido!\n");
                        fprintf(stderr, "Por favor, digite um número maior que 0:\n");
                        printf("\nValor da movimentacao: R$ ");
                        scanf("%f", &valor); 
                    }
                    movimentation.valor = valor;
                    bankaccount.saldo += valor;
                    fseek(arq_conta, -sizeof(conta), SEEK_CUR);
                    fwrite(&bankaccount, sizeof(conta), 1, arq_conta);
                    fwrite(&movimentation, sizeof(bankaccount), 1, arq_mov);
                    clear_terminal();        // Limpa o terminal após o termino do cadastrado da compra
                    puts(MOV_SUCESS);       // Mostra a mensagem que foi definida em MOV_SUCESS
                    stay();                /* Pausa a mensagem que está definida em
                                            * MOV_SUCESS no terminal */
                    clear_buffer();      /* Limpamos o buffer aqui pois, caso o usuario 
                                          * digite algo e de enter, o valor digitado não 
                                          * será pego pelo menu */
                }
            }
        //}
    }
    fclose(arq_conta);
    fclose(arq_mov);
}

void listar_movimentacoes(void){
    setlocale(LC_ALL, "Portuguese");
    
    FILE *arq, *arq_conta;        // Declarando variaveis do tipo arquivo
    conta bankaccount;           // Desclarando uma estrutura do tipo conta
    movimentacao movimentation; // Declarando uma estrutura do tipo movimentacao
    data dt_inicial, dt_final; // Datas a serem digitadas pelo usuário
    
    int cod_movimentation; // Número da conta a ser digitado pelo usuário
    int count;            // Contador
    int r;               // Variavel que pega o retorno da função compara_datas
    int dia_i, mes_i, ano_i;
    int dia_f, mes_f, ano_f;
    char tipo[2][8] = { "saque", "deposito" };
    
    if((arq_conta = fopen(ARQ_CONTA, "rb")) == NULL){
        clear_terminal();      // Limpa o terminal ao entrar aqui
        fprintf(stderr, "Erro: não nenhuma conta cadastrado!");
        stay();          // Pausa a mensagem de erro no terminal
        clear_buffer(); // Limpa o buffer caso o usuário digite algo
        return;
    }
    
    clear_terminal();
    fprintf(stdout, "********Consultar Movimentacoes********\n");
    fprintf(stdout, "Digite o código da conta: ");
    scanf("%d", &cod_movimentation);
    count = 0;
	// Le o arquivo de contas
    while(fread(&bankaccount, sizeof(conta), 1, arq_conta) > 0){
		if(cod_movimentation == bankaccount.num_conta){
            count++;
        }
    }
    
    /* Verifica se a conta digitada pelo 
        * usuário não existe */
    if(count == 0){
        fprintf(stderr, "Erro! Não existe nenhuma conta cadastrada com esse numero!\n");
        fprintf(stderr, "Consulta encerrada!\n");
        stay();          // Pausa a mensagem de erro no terminal
        clear_buffer(); /* Limpamos o buffer aqui pois, caso o usuario 
                         * digite algo e de enter, o valor digitado não 
                         * será pego pelo menu */
        return;
    }
    
	/* Caso exista o programa pedira as datas
	 * para verificar o periodo das movimentações */
    fprintf(stdout, "Digite a data inicial: ");
    scanf("%d/%d/%d", &dia_i, &mes_i, &ano_i);
//    scanf("%d/%d/%d", &dt_inicial.dia, &dt_inicial.mes, &dt_inicial.ano);
    fprintf(stdout, "Digite a data final: ");
    scanf("%d/%d/%d", &dia_f, &mes_f, &ano_f);
//    scanf("%d/%d/%d", &dt_final.dia, &dt_final.mes, &dt_final.ano);
    
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
        scanf("%d/%d/%d", &dt_inicial.dia, &dt_inicial.mes, &dt_inicial.ano);
        fprintf(stdout, "Digite a data final: ");
        scanf("%d/%d/%d", &dt_final.dia, &dt_final.mes, &dt_final.ano);
        dt_inicial.dia = dia_i, dt_inicial.mes = mes_i, dt_inicial.ano = ano_i;
        dt_final.dia = dia_f, dt_final.mes = mes_f, dt_final.ano = ano_f;
        r = compara_datas(dt_inicial, dt_final);
    }
    
	/* Abre o arquivo movimentacoes.dat */
    if((arq = fopen(ARQ_MOVIMENTACAO, "rb")) == NULL){
        clear_terminal();  // Limpa o terminal ao entrar aqui
        puts(NOT_MOV);    // Mostra a mensagem que foi definida em NOT_MOV
        stay();          /* Pausa a mensagem que está definida em
                          * NOT_MOV no terminal */
        clear_buffer(); /* Limpamos o buffer aqui pois, caso o usuario 
                         * digite algo e de enter, o valor digitado não 
                         * será pego pelo menu */
        return;
    }
    
    /*
     if(r == 0 || r == -1){
        
     }
     */
    
    clear_terminal();
    fprintf(stdout, "***********************************************\n");
    fprintf(stdout, "#Data             Tipo              Valor      \n");
    fprintf(stdout, "***********************************************\n");
    count = 0;
    // Lê o arquivo e busca pelo codigo digitado
    while(fread(&movimentation, sizeof(movimentacao), 1, arq) != 0){
        if(movimentation.num_conta == cod_movimentation){ // != 0
            /*if(movimentation.dt_movimentacao.dia >= dia_i && movimentation.dt_movimentacao.dia <= dia_f &&
               movimentation.dt_movimentacao.mes >= mes_i && movimentation.dt_movimentacao.mes <= mes_f && movimentation.dt_movimentacao.ano >= ano_i && movimentation.dt_movimentacao.ano <= ano_f){ */
                if(movimentation.tipo == 1){
                    fprintf(stdout, "%02d/%02d/%02d        %-8.8s          R$%.2f\n",
                                        movimentation.dt_movimentacao.dia,movimentation.dt_movimentacao.mes, movimentation.dt_movimentacao.ano, tipo[0], movimentation.valor);
                }
    //            if(movimentation.tipo == 2){
                //else{
                    fprintf(stdout, "%02d/%02d/%02d        %-8.8s          R$%.2f\n",
                                        movimentation.dt_movimentacao.dia,movimentation.dt_movimentacao.mes, movimentation.dt_movimentacao.ano, tipo[1], movimentation.valor);
                //}
            //}
            count++;
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
        fprintf(stdout, "ERRO! Não houve nenhuma movimentacao para esta conta\n");
        return;
    }
    
    fclose(arq);            // Fecha o arquivo compras.dat
    
    stay();            /* Pausa o arquivo de cadastros 
                        * no terminal para que o usuario
                        * possa ver as compras cadastradas */
    clear_buffer(); /* Limpamos o buffer aqui pois, caso o usuario 
                     * digite algo e de enter, o valor digitado não 
                     * será pego pelo menu */
}

int compara_datas(data dt_inicial, data dt_final){
    // Dia, Mes e Ano inicial, Data inicial
	int dt_i_d, dt_i_m, dt_i_a, dt_i;
    
	// Dia, Mes e Ano Inicial, Data final
	int dt_f_d, dt_f_m, dt_f_a, dt_f;
    
    /*  */
    dt_i_d = dt_inicial.dia;
    dt_i_m = dt_inicial.mes * 30;
    dt_i_a = dt_inicial.ano * 12 * 30;
    
	// Calcula a Data inicial 
    dt_i = dt_i_d + dt_i_m + dt_i_a;
    
	/*  */
    dt_f_d = dt_final.dia;
    dt_f_m = dt_final.mes * 30;
    dt_f_a = dt_final.ano * 12 * 30;
    
	// Calcula a Data final
    dt_f = dt_f_d + dt_f_m + dt_f_a;
    
	/* Verifica se a
	 * data inicial é
	 * maior que a final */
    if(dt_i < dt_f){
        return -1;
    }
	/* Verifica se são iguais */
    else if(dt_i == dt_f){
        return 0;
    }
	/* Retorna 1 se a
	 * inicial é maior
	 * que a final */
    else{
        return 1;
    }
}

/* COMENTARIOS COMENTOSSOS
while(fread(&bankaccount, sizeof(conta), 1, arq_conta) > 0){
    if(cod_bankaccount == bankaccount.num_conta){
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
            fwrite(&bankaccount, sizeof(bankaccount), 1, arq_conta);
            fwrite(&movimentation, sizeof(movimentacao), 1, arq_mov);
            fclose(arq_mov);
            clear_terminal();      // Limpa o terminal após o termino do cadastrado da compra
            puts(MOV_SUCESS);    // Mostra a mensagem que foi definida em MOV_SUCESS
            stay();         /* Pausa a mensagem que está definida em
                                * MOV_SUCESS no terminal //
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
            fwrite(&bankaccount.saldo, sizeof(bankaccount), 1, arq_conta);
            fwrite(&movimentation, sizeof(movimentacao), 1, arq_mov);
            fclose(arq_mov);
            clear_terminal();      // Limpa o terminal após o termino do cadastrado da compra
            puts(MOV_SUCESS);    // Mostra a mensagem que foi definida em MOV_SUCESS
            stay();         /* Pausa a mensagem que está definida em
                                * MOV_SUCESS no terminal //
            clear_buffer(); /* Limpamos o buffer aqui pois, caso o usuario 
                                * digite algo e de enter, o valor digitado não 
                                * será pego pelo menu //
            clear_terminal(); // Limpa o terminal antes de voltar para o menu
        }
    }
}
/*    if(cod_bankaccount != bankaccount.num_conta){
    clear_terminal();
    printf("Não existe nenhuma conta com esse código\n");
    printf("Movimentacao interrompida!\n");
//             fclose(arq_cliente);
    stay();
    clear_buffer();    /* Limpamos o buffer aqui pois, caso o usuario 
                        * digite algo e de enter, o valor digitado não 
                        * será pego pelo menu //
    clear_terminal();
}*/

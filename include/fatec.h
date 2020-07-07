/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * fatec.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo das funções e estruturas que
 * foram usadas no primeiro ano do curso
 * 
 * fatec.h é um software livre; você pode redistribui-lo e/ou
 * modificalo sob os termos da Licença GNU Lesser General Public
 * publicada pela Free Software Foundation; ou
 * versão 2 da licença ou (a seu critério) qualquer versão posterior.
 * 
 * Você deve ter recebido uma copia da Licença GNU Lesser General Public
 * junto com o fatec.h; case contrario, veja:
 * <http://www.gnu.org/licenses/>.
 * 
 * Versão: 20.06.15
 * 
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>
 * 
 * Data de início: 02/12/2019
 * Data da última modificação: 07/07/2020 */

// Evita que a biblioteca seja incluida inumeras vezes
#ifndef _FATEC_H
#define _FATEC_H

#include <stdio.h>
#include <stdbool.h>     // Biblioteca usada para manipular variaveis booleanas
#include <locale.h>    /* Biblioteca para poder usar a função setlocale 
                        * usada para colocar acentuação nas palavras */
#include <math.h>    // Biblioteca para usar funções matematicas
#include <limits.h>
#include <string.h> // Biblioteca usada para manipular strings
//#include <strings.h>
#include <ctype.h>

// Verifica se o sistema é do tipo unix like
#ifdef __unix__
    #include <stdlib.h> // Biblioteca usada para ultilizar comandos do Sistema Operacional
    #define clear_terminal() system("clear");
    #define stay() printf("\nPrecione enter para continuar..."); getchar();
// Verificar se o sistema é Windows ou se o programa foi compilado para Windows
#elif defined(_WIN32) || defined(WIN32) || defined(__MINGW32__) || defined(_MCS_VER)
    #include <stdlib.h>
    #define clear_terminal() system("cls");
#endif

/* A seguir definições usadas no trabalho 
 * do professor Ciro Cirne Trindade */

// Definições por Profº Ciro Cirne Trindade

/* Nome do arquivo aonde os clientes são cadastrados */
#define ARQ_CLIENTE "clientes.dat"

/* Nome do arquivo aonde as compras são cadastradas */
#define ARQ_COMPRA "compras.dat"

// Definições por Gustavo Bacagine

/* Mensagem de erro caso 
 * o usuario digite uma 
 * opção inválida */
#define ERROR "ERRO! Opção inválida!"

/* Mensagem a ser 
 * mostrada após o 
 * cadasto do cliente */
#define CLIENT_SUCESS "Cliente cadastrado com sucesso!" 

/* Mensagem a ser 
 * mostrada caso 
 * não haja nenhum
 * cliente cadastrado */
#define NOT_CLIENT "Erro! Não há nenhum cliente cadastrado!"

/* Mensagem a ser 
 * mostrada após o 
 * cadastro da compra */
#define BUY_SUCESS "Compra cadastrada com sucesso!" 

/* Mensagem a ser 
 * mostrada caso 
 * não haja nenhuma
 * compra cadastrada */
#define NOT_BUY "Erro! Não há nenhuma compra cadastrada!" 


/* A seguir definições usadas nas aulas 
 * do professor Ciro Cirne Trindade */

/* Definição criada por Gustavo Bacagine
 * 
 * Nome do arquivo aonde os alunos são cadastrados */
#define ARQ_ALUNOS "alunos.txt"

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Número de carros à ser cadastrados */
#define NUM_CARROS 20

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Definindo um valor para constante PI */
#define PI 3.1415

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Calculo de uma potência de 2 */
#define SQ(x) ((x) * (x))

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Calculo da área */
#define AREA(x) (PI * SQ(x))

/* Definição criada pelo professor
 * Ciro Cirne Trindade
 * 
 * Printa o valor de x */
#define PRN(x) printf("%lf\n", x)

// Definições adicionais

/* Definição criada por Gustavo Bacagine
 * 
 * Diretorio onde se
 * encontra a lisença 
 * do software */
//#define LICENSE "./LICENSE/GPL2/Texto/gpl-2.0.txt"

/* A seguir estruturas usadas no trabalho 
 * do professor Ciro Cirne Trindade */

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * 
 * Ela representa um cliente */
typedef struct {
    int codigo_cliente;
    char nome_cliente[51];
    char telefone[15];
} cliente;

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * 
 * Ela representa uma data */
/*typedef struct {
    int dia;
    int mes;
    int ano;
} data; */

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade.
 * 
 * Ela representa uma compra */
/*typedef struct {
    int numero_compra;
    int codigo_cliente; // código do cliente que realizou a compra
    float valor;
    data dt_compra;
} compra;*/

/* A seguir estruturas usadas nas aulas 
 * do professor Ciro Cirne Trindade */

/*
 * Considere a estrutura struct circulo
 * definida anteriormente e escreva um
 * programa que dados dois círculos,
 * verifique se eles se sobrepõem. Dois
 * círculos se sobrepõem se a distância
 * entre os centros destes círculos é menor
 * que a soma de seus raios. Distância
 * entre dois pontos, (x 1 , y 1 ) e (x 2 , y 2 ):
 * 
 * d = √ ( x 1 − x 2 )^2 +( y 1 − y 2 )^2 */
struct ponto {
	int x;
	int y;
};

struct circulo {
	struct ponto centro;
	int raio;
};

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade 
 * 
 * Ela representa um processador: frequência e fabricante. */
typedef struct {
	float frequencia;
	char fabricante[21];
} processador;
 
/* Estrutura criada pelo professor
 * Ciro Cirne Trindade 
 * 
 * Ela representam um monitor: tamanho, tipo (LCD, CRT, Plasma, Led)
 * e fabricante. */
typedef enum { LCD, CRT, PLASMA, LED } tipo_monitor;
typedef struct {
	int tamanho;
	tipo_monitor tipo;
	char fabricante[21];
} monitor;  
 
/* Estrutura criada pelo professor
 * Ciro Cirne Trindade 
 * 
 * Ela serve para representar um computador: processador, monitor, capacidade de
 * disco rígido e memória RAM. */
typedef struct {
	processador proc;
	monitor tela;
	int capacidade_hd;
	int ram;
} computador;

/* Estrutura criada pelo professor
 * Ciro Cirne Trindade 
 * 
 * Ela serve para o cadastro 
 * de funcionarios */
struct funcionario {
	char nome[41];
	int departamento;
	float salario;
};

/* Considere as declarações a seguir para representar o cadastro de alunos de uma
 * disciplina e implemente uma função que imprima o número de matrícula, o nome, a
 * turma e a média de todos os alunos aprovados na disciplina.
 * 
 * typedef struct {
 *  char nome[40];
 *  int matricula;
 *  char turma; 
 *  float provas[3];
 * } aluno;
 * 
 * Considere que o critério de aprovação é que a média aritmética das 3 provas seja
 * maior ou igual a 6.
 * A função deve receber como parâmetros o número de alunos da disciplina e um vetor com os
 * dados dos alunos. */
typedef struct {
	char nome[40];
	int matricula;
	char turma;
	float provas[3];
} aluno;

/* Seja uma estrutura para descrever os carros de uma determinada revendedora, contendo os
 * seguintes campos:
 * • marca : string de tamanho 20
 * • ano : inteiro
 * • cor : string de tamanho 10
 * • preco : real
 * a) Escrever a definição da estrutura carro .
 * b) Declarar o vetor vetcarros do tipo da estrutura definida acima, de tamanho 20.
 * Crie um menu para:
 * c) Cadastrar um carro no vetor vetcarros .
 * d) Listar todos os carros com preço menor ou igual a um valor fornecido pelo usuário;
 * e) Listar todos os carros de uma determinada marca fornecida pelo usuário; */

struct carro {
	char marca[21];
	int ano;
	char cor[11];
	float preco;
};

/* A seguir as funções mais usadas pelos alunos 
 * de ADSM da FATEC de Carapicuíba */

/* Função usada para evitar 
 * Buffer Overflow
 * 
 * Você pode se perguntar o motivo
 * para se usar uma função propia para
 * limpar o buffer do terminal ao invés
 * de usar uma função já pronta encontrada
 * na propia linguagem
 * 
 * Existem muitas funções que poderiamos
 * usar como: fflush(), setbuf(), etc...
 * 
 * O motivo para usarmos essa função está
 * no fato de que as funções listadas acima
 * não funcionam em todos os Sistemas Operacionais.
 * O fflush() funciona no Windows mas não funciona no
 * Linux e no MasOS; já o setbuf() funciona tanto no
 * Linux como no Windows, porém não funciona no MasOS.
 * 
 * Está função que usamos funciona em todos os
 * Sistemas Operacionais. Por isso achamos que essa seja
 * a melhor opção a ser usada.
 * 
 * OBS: Essa função não foi 
 * desenvolvida por nós. Percebemos 
 * que muitos programadores 
 * se utilizam dessa função e 
 * passamos a usa-lá em nossos programas */
void clear_buffer(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela printa um menu no terminal
 * Foi feita como um exemplo apenas pois,
 * o menu normalmente fica na função main.
 * Você pode usa-lá para criar seus propios menus */
void menu(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela printa no terminal o conteudo
 * do arquivo README.md */
void sobre(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela printa no terminal a licença 
 * do software */
int license(const char *l);

/* Função criado pelo Profº Ciro Cirne Trindade
 * 
 * Ela converte os atalhos de itálico do texto passado
 * como argumentos para as tags HTML <i> e </i> */
void italico(char *str);

/* Função criado pelo Profº Ciro Cirne Trindade
 * 
 * Ela converte os atalhos de negrito do texto passado
 * como argumentos para as tags HTML <b> e </b> */
void negrito(char *str);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * 
 * Essa função é baseada na função criada por isrnick
 * O código original pode ser encontrado em:
 * https://www.clubedohardware.com.br/forums/topic/1402340-substituir-um-car%C3%A1cter-por-uma-palavra-em-c/ 
 * 
 * Essa função substitui o caractere da posição dada pelo 2o argumento
 * no texto dado pelo 1o argumento pela tag passada como 3o
 * argumento */
void replace(char *str, int i, const char *newStr);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função cadastra um novo cliente no arquivo clientes.dat */
void cadastrar_cliente(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função exibe uma listagem no formato de tabela
 * mostrando o código, nome e telefone de todos os
 * clientes cadastrados */
void listar_clientes(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função consulta os clientes por nome */
void consultar_cliente(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função cadastra uma nova compra no arquivo compras.dat */
void cadastrar_compra(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função lista todas as compras feitas em uma data
 * 
 * OBS: em andamento */
void listar_compras_data(void);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função devolve verdadeiro se as duas datas passadas
 * como argumentos são iguais, ou falso, caso contrário.
 * Usada na função listar_compras_data()
 * 
 * OBS: em andamento */
//bool datas_iguais(data, data);

/* Prototipo criado pelo Profº Ciro Cirne Trindade
 * E desenvolvida pelos alunos da FATEC de Carapicuíba
 * 
 * Essa função lista todas as compras feitas por um cliente */
void listar_compras_cliente(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela é usada para mostrar
 * os desenvolvedores da 
 * aplicação */
void developers(void);

/* A seguir funções e estruturas usadas nas aulas 
 * e listas de exercicios do professor 
 * Ciro Cirne Trindade */

// Aula 1 Vetores e Matrizes

/* Função criada pelo Profº Ciro Cirne Trindade
 * 
 * Essa função cria uma matriz 4x6 através dos
 * valores passado pelo usuário */
void matriz(void);

/* Função criada pelo Profº Ciro Cirne Trindade
 * 
 * Essa função tratasse de um jogo de batalha
 * naval criado pelo professor Ciro Cirne Trindade 
 * para poder mostrar o uso de matrizes na línguagem
 * C */
void naval(void);

/* Função criada pelo Profº Ciro Cirne Trindade
 * 
 * Essa função simula um caixa eletronico e
 * mostra as notas sacadas pelo usuário 
 * de acordo com o valor desejado */
void notas(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função pega uma sequência de n 
 * números inteiros e os imprime em ordem
 * inversa. */
void inverse_num(void);

// Aula 2 Strings

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string de 0s e 1s, interprete
 * essa string como um número binário e 
 * informe o valor desse número na base decimal. */
void binario_decimal(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe n strings e determina quantas dessas 
 * strings contém uma string qualquer 
 * dada pelo usuário. */
void conta_str(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string do teclado e 
 * informe quantas letras maiúsculas
 * ela possui. */
void maiusculas(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string do teclado e informe se 
 * ela é palíndromo ou não. Uma string é 
 * palíndromo quando pode ser lida tanto de 
 * trás para frente quanto de frente para trás 
 * e possui exatamente a mesma sequência de 
 * caracteres. Por exemplo: “ASA”, “SUBI NO 
 * ONIBUS”.
 * 
 * OBS: Desconsidera os espaços. */
void palindromo(void);

// Aula 3 Funções

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função calcula a area de uma esfera */
void area(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função imprime uma matriz no terminal */
void imprime_matriz(int, int, int [][*]);
 
/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função cria uma matriz com os valores
 * recebidos pelo usuário */
void recebe_matriz(int, int, int [][*]);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma matriz A bidimensional
 * de valores reais e um valor real x,
 * e multiplique todos os elementos de A por x. */
 void multiplica_matriz(int, int, double (*)[*], double);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função calcula o dobro de um valor x */
void dobro(int);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função */
int maior(int, int);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função desenha no vídeo um retângulo 
 * formado por asteriscos (*) com a linhas de 
 * altura e c colunas de comprimento. Por exemplo, 
 * se for feita a seguinte chamada a função: retangulo(5, 10);
 * A função deve desenhar no vídeo o seguinte retângulo:
 * **********
 * **********
 * **********
 * **********
 * ********** */
void retangulo(int, int);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe por parâmetro o raio de uma 
 * esfera (um int ) e calcula e devolve 
 * o seu volume ( 4PIR³/3). */
double volume(int);

// Aula 4 Modulos

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função devolve o fatorial de um número 
 * natural passado como argumento */
long long fatorial (int);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função devolve o número real passado como 
 * argumento arredondado para o inteiro mais próximo */
int arredondar_para_int (double);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função devolve o número real passado como 
 * 1o. argumento arredondado com uma precisão dada
 * pelo número inteiro passado como 2o. argumento da função */
double arredondar(double, int);

// Aula 5 Ponteiros

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe uma data no formato ddmmaaaa, 
 * e devolve o dia, o mês e o ano separadamente. */
void separa_data(int, int *, int *, int *);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe o tamanho de um arquivo em bytes e devolve 
 * o tamanho desse arquivo em KB e MB. */
void file_size(int, float *, float *);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe um número decimal e o converte para binário. */
void dec2bin(int *);

// Lista 5 Ponteiros 2019 2º Semestre

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função transforma o tempo digitado pelo usuario em
 * segundos para o formato 00h:00min:00s */
void transforma_segundos(int, int *, int *, int *);

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função calcula o diâmetro, perímetro e área de uma 
 * circunferência. */
void circunferencia(float, float *,float *,float *);

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função recebe como parâmetro uma distância 
 * em metros a devolve, também através de seus parâmetros,
 * essa distância em polegadas, jardas e milhas. */
void converte(float, double *, double *, double *);

// Aula 6 Estruturas

/* Função criada pelo Profº Ciro Cirne Trindade
 * 
 * Essa função serve para verificar se
 * um aluno foi aprovado ou reprovado */
void aprovados(int, aluno []);

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para o cadastro de carros */
void cadastrar_carro(int *, struct carro []);

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para listar os carros
 * cadastrados */
void listar_por_preco(int, struct carro[], float);

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para listar os carros
 * cadastrados por marca */
void listar_por_marca(int, struct carro[], const char *);

// Aula 8 Arquivos

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para o cadastro de alunos */
void cadastrar_aluno(void);
 
/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função serve para listar os alunos
 * cadastrados */
void listar_alunos(void);

/* Função criada pelo Profº Ciro Cirne Trindade
 *
 * Essa função exibe um arquivo */
int exibe_arq(void);

/* A seguir algumas funções adicionais que não
 * foram usadas no curso mas que achamos interessante
 * adicionar */

/* Function created by Anuj Chauhan 
 * (geeksforgeeks.org/c-program-replace-word-text-another-given-word/)
 * 
 * This function replace a string with 
 * another string */
char *replaceWord(const char *str, const char *oldW, const char *newW);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros inteiros */
int Soma(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros inteiros */
int Subtracao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros inteiros */
int Multiplicacao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros inteiros */
int Divisao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros do tipo ponto flutuante */
int Fsoma(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros numeros do tipo ponto flutuante */
int Fsubtracao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros numeros do tipo ponto flutuante */
int Fmultiplicacao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros numeros do tipo ponto flutuante */
int Fdivisao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros do tipo double */
int Dsoma(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros numeros do tipo double */
int Dsubtracao(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros numeros do tipo double */
int Dmultiplicacao(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros numeros do tipo double */
int Ddivisao(double n1, double n2);


/* Função criada por Gustavo Bacagine.
 *
 * Essa função remove um cliente cadastrado no sistema */
void remover_cliente(void);

/* Função criada por Gustavo Bacagine.
 * 
 * Essa função faz um calculo de um número fatorial
 * de maneira recursiva */
int recorsive_fatorial(int n);

/* Função cirada pelo professor Ciro Crine Trindade
 * 
 * Outra maneira de limpar o buffer
 * do terminal. */
void buffer_clean(void);

/* Essa função foi criada por Herbert Schildt
 * Pegamos ela de seu livro "C Completo e Total"
 * 
 * Essa função funciona semelhante à puts
 * printando uma string na saída do terminal. */
void my_puts(char *s);

/* Essa função foi criada por Herbert Schildt
 * Pegamos ela de seu livro "C Completo e Total"
 * 
 * Essa função funciona semelhante à função pow
 * calculando o expoente (e) de um número (n) */
int my_pow(int n, int e);

#endif // _FATEC_H

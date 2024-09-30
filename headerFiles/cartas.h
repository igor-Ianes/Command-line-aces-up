#ifndef CARTAS_H
#define CARTAS_H
#include "cartas.h"
#include "pilha.h" 
#include "iteradores.h" 
#include "graficos.h"

#define MAX 14
#define rangeMAX 14
#define rangeMIN 1
#define MAXCARTAS 51

#define COPAS 3
#define OUROS 4
#define ESPADAS 6
#define PAUS 5


void printQuatro(pilha p1, pilha p2, pilha p3, pilha p4);
void deck(pilha *p1, pilha *p2, pilha *p3, pilha *p4, dado var, iterador auxiliar);
void shuffle(int copas[], int ouros[], int paus[], int espadas[], int chave[], lista primos);
int  comparador(int monte, pilha p1, pilha p2, pilha p3, pilha p4, int mov, int descartados);
int  comparadorV(pilha p1, pilha p2, pilha p3, pilha p4, int mov, int mov2);
dado construtor(char suite, int peso);
iterador removerQuatro(lista *primos);
void jogada1(pilha *remocao, pilha *p1, pilha *p2, pilha *p3, pilha *p4, int monte, int descartados);
void jogada2(pilha *move1, pilha *move2, pilha *p1, pilha *p2, pilha *p3, pilha *p4, int monte, int descartados);
void jogada3(pilha *p1, pilha *p2, pilha *p3, pilha *p4, int monte, int descartados, lista *primos, iterador *auxiliar);
void ramdomChave(int arr[], int maximo, int minimo);
void printDescarte(dado item2);
void printMov(dado item2);
int printMonte(int monte);
void inputs(int *rotulo, int *movimento1, int *movimento2);

#endif
#ifndef GRAFICOS_H
#define GRAFICOS_H

#include "pilha.h" 
#include "lista.h" 

void red();
void green();
void blue();
void white();
void cabecalho();
void cartaAsc(int valor, char naipe);
void resultadoAposJogada(int comp, int compv, int mov, int descartados, int monte, char rotulo);
void printP(pilha *p1, pilha *p2, pilha *p3, pilha *p4);
dado printT(pilha *p1, dado *item);
void printCard(dado item2);
void vitoria();
void fimDeJogo(int descartados);
void proxJogada();
void cabecalho2(int descartados);


#endif
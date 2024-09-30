#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h" 
#include "pilha.h" 
#include "iteradores.h" 
#include "cartas.h"
#include "graficos.h"

int main(void) {

    lista baralho;
    pilha p1, p2, p3, p4;

    iterador auxiliar;
    int op = 1, copas[MAX], ouros[MAX], paus[MAX], espadas[MAX], chave[MAXCARTAS], movimento = 10, movimento2, comparaCartas, comparaPilhas;
    static int monte = 48, descartados= 0;
    char rotulo;

    p1 = cria(100);
    p2 = cria(100);
    p3 = cria(100);
    p4 = cria(100);

 
    inicializar(&baralho);
   
    time_t t;
    srand(time(&t)); 
    ramdomChave(copas, rangeMAX, rangeMIN);
    ramdomChave(ouros, rangeMAX, rangeMIN);
    ramdomChave(paus, rangeMAX, rangeMIN);
    ramdomChave(espadas, rangeMAX, rangeMIN);
    ramdomChave(chave, 52, 1);
    
    shuffle(copas, ouros, paus, espadas, chave, baralho);

    auxiliar = primeiro(&baralho);

    cabecalho();

    jogada3(&p1, &p2, &p3, &p4, monte, descartados, &baralho, &auxiliar);

    cabecalho2(descartados);

  while(op == 1){

   proxJogada();
   scanf(" %c", &rotulo);
   if(rotulo != 'A'){
   scanf("%d", &movimento);}
   if(rotulo == 'M'){
   scanf("%d", &movimento2);}

   printf("\n");

  comparaCartas = comparador(monte, p1, p2, p3, p4, movimento, descartados);
  comparaPilhas = comparadorV(p1, p2, p3, p4, movimento, movimento2);
    
    // retira cartas
     if(movimento == 1 && comparaCartas == 1){
       descartados +=1;
      jogada1(&p1, &p1, &p2, &p3, &p4, monte, descartados);
    }

     if(movimento == 2 && comparaCartas == 2){
       descartados +=1;
      jogada1(&p2, &p1, &p2, &p3, &p4, monte, descartados);
    }
  
     if(movimento == 3 && comparaCartas == 3){
       descartados +=1;
      jogada1(&p3, &p1, &p2, &p3, &p4, monte, descartados);
    }

     if(movimento == 4 && comparaCartas == 4){
       descartados +=1;
      jogada1(&p4, &p1, &p2, &p3, &p4, monte, descartados);
    }

    // movimenta cartas
     if(movimento == 1 && movimento2 == 2 && comparaPilhas == 1){
      jogada2(&p1, &p2, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 1 && movimento2 == 3 &&  comparaPilhas == 2){
      jogada2(&p1, &p3, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 1 && movimento2 == 4 && comparaPilhas == 3){
      jogada2(&p1, &p4, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 2 && movimento2 == 1 && comparaPilhas == 4){
      jogada2(&p2, &p1, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 2 && movimento2 == 3 && comparaPilhas == 5){
      jogada2(&p2, &p3, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 2 && movimento2 == 4 && comparaPilhas == 6){
      jogada2(&p2, &p4, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 3 && movimento2 == 1 && comparaPilhas == 7){
      jogada2(&p3, &p1, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 3 && movimento2 == 2 && comparaPilhas == 8){
      jogada2(&p3, &p2, &p1, &p2, &p3, &p4, monte, descartados);
    }
    
    if(movimento == 3 && movimento2 == 4 && comparaPilhas == 9){
      jogada2(&p3, &p4, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 4 && movimento2 == 1 && comparaPilhas == 10){
      jogada2(&p4, &p1, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 4 && movimento2 == 2 && comparaPilhas == 11){
      jogada2(&p4, &p2, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(movimento == 4 && movimento2 == 3 && comparaPilhas == 12){
      jogada2(&p4, &p3, &p1, &p2, &p3, &p4, monte, descartados);
    }

    if(rotulo == 'A' && monte > 0){  
      monte -= 4;
      jogada3(&p1, &p2, &p3, &p4, monte, descartados, &baralho, &auxiliar);
    }

    resultadoAposJogada(comparaCartas, comparaPilhas, movimento, descartados, monte, rotulo);

    scanf("%d", &op);
 }
    fimDeJogo(descartados);

    destruir(&baralho);
    destroi(&p1);
    destroi(&p2);
    destroi(&p3);
    destroi(&p4);

 return 0;
}


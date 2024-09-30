#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cartas.h"
#include "pilha.h" 
#include "iteradores.h" 
#include "lista.h" 
#include "graficos.h"

dado construtor(char suite, int peso){
    dado carta;
        carta.naipe = suite;
        carta.valor = peso;
 return carta;
}

void ramdomChave(int arr[], int maximo, int minimo){
  int get, c, i, chk, x;
  c = i = 0;
  dado aux;

  while(c < maximo){
    get = ((rand() % (maximo - minimo +1)) + minimo); 
    
    for(i=0; i<=c; i++){
        if(arr[i] == get){
          chk = 0;
          break;}
        else if(arr[i] != get){
          chk = 1;}
     }
  
    if(chk==1){
      arr[c]=get;
      c++;}
    }
}

void printQuatro(pilha p1, pilha p2, pilha p3, pilha p4){
    printP(&p1, &p2, &p3, &p4);
}

void deck(pilha *p1, pilha *p2, pilha *p3, pilha *p4, dado var, iterador auxiliar){
 
   var = elemento(auxiliar);
   insere(p1, var);
   proximo(&auxiliar);

   var = elemento(auxiliar);
   insere(p2, var);
   proximo(&auxiliar);

   var = elemento(auxiliar);
   insere(p3, var);
   proximo(&auxiliar);

   var = elemento(auxiliar);
   insere(p4, var);

}

iterador removerQuatro(lista *primos){
   iterador aux;
   removerInicio(primos);
   removerInicio(primos);
   removerInicio(primos);
   removerInicio(primos);
   return aux = primeiro(primos);
}

int comparador(int monte, pilha p1, pilha p2, pilha p3, pilha p4, int mov, int descartados){
  dado item1, item2, item3, item4;
  char c1, c2, c3, c4;
  int  v1, v2, v3, v4;
   topo(&p1, &item1);
   c1 = item1.naipe;
   v1 = item1.valor;
   topo(&p2, &item2);
   c2 = item2.naipe;
   v2 = item2.valor;
   topo(&p3, &item3);
   c3 = item3.naipe;
   v3 = item3.valor;
   topo(&p4, &item4);
   c4 = item4.naipe;
   v4 = item4.valor;

   if(mov == 1 && (c1 == c2 && v1 < v2 || c1 == c3 && v1 < v3 || c1 == c4 && v1 < v4)){
      return 1;
   }

   if(mov == 2 && (c2 == c1 && v2 < v1 || c2 == c3 && v2 < v3 || c2 == c4 && v2 < v4)){
      return 2;
   }
   if(mov == 3 && (c3 == c1 && v3 < v1 || c3 == c2 && v3 < v2 || c3 == c4 && v3 < v4)){
      return 3;
   }
   if(mov == 4 && (c4 == c1 && v4 < v1 || c4 == c2 && v4 < v2 || c4 == c3 && v4 < v3)){
      return 4;
   }
  if(c1 == 14 && c2 == 14 && c3 == 14 && c4 == 14 && monte == 0 && descartados == 48){
    return 9;
  }
  if(mov == 5 || mov == 6 || mov ==7 || mov ==8 || mov == 10 || mov == 11 || mov == 12){
    return -66;
  }
  return -1;
}

int comparadorV(pilha p1, pilha p2, pilha p3, pilha p4, int mov, int mov2){
  if(vazia(&p1) && !vazia(&p2) && mov == 1 && mov2 == 2){
    return 1;
  }
  if(vazia(&p1) && !vazia(&p3) && mov == 1 && mov2 == 3){
    return 2;
  }
  if(vazia(&p1) && !vazia(&p4) && mov == 1 && mov2 == 4){
    return 3;
  }

  if(vazia(&p2) && !vazia(&p1) && mov == 2 && mov2 == 1){
    return 4;
  }
  if(vazia(&p2) && !vazia(&p3) && mov == 2 && mov2 == 3){
    return 5;
  }
  if(vazia(&p2) && !vazia(&p4) && mov == 2 && mov2 == 4){
    return 6;
  }

  if(vazia(&p3) && !vazia(&p1) && mov == 3 && mov2 == 1){
    return 7;
  }
  if(vazia(&p3) && !vazia(&p2) && mov == 3 && mov2 == 2){
    return 8;
  }
  if(vazia(&p3) && !vazia(&p4) && mov == 3 && mov2 == 4){
    return 9;
  }

  if(vazia(&p4) && !vazia(&p1) && mov == 4 && mov2 == 1){
    return 10;
  }
  if(vazia(&p4) && !vazia(&p2) && mov == 4 && mov2 == 2){
    return 11;
  }
  if(vazia(&p4) && !vazia(&p3) && mov == 4 && mov2 == 3){
    return 12;
  }
return -1;
}

void shuffle(int copas[], int ouros[], int paus[], int espadas[], int chave[], lista primos){
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    dado aux;
    
    int rand_num = chave[i];
  
      for(int i = 0; i <= 51; i++){
      if(rand_num <= 13){
        aux = construtor(COPAS, copas[j++]);
        inserirInicio(&primos, aux);}

      if(rand_num > 13 && rand_num <= 26){
        aux = construtor(OUROS, ouros[k++]);
        inserirInicio(&primos, aux);}

      if(rand_num > 26 && rand_num <= 39){
        aux = construtor(PAUS, paus[l++]);
        inserirInicio(&primos, aux);}
      
      if(rand_num > 39 && rand_num <= 52){
        aux = construtor(ESPADAS, espadas[m++]);
        inserirInicio(&primos, aux);}
      aux.valor = 0;
  
      rand_num = chave[i];
    }
}

void jogada1(pilha *remocao, pilha *p1, pilha *p2, pilha *p3, pilha *p4, int monte, int descartados){
       green();printf("remover carta\n\n");white();
      dado ajuda;
      topo(remocao, &ajuda);
      retira(remocao);
      printQuatro(*p1, *p2, *p3, *p4);
      printMonte(monte);
      printDescarte(ajuda);
      descartados +=1;
}

void jogada2(pilha *move1, pilha *move2, pilha *p1, pilha *p2, pilha *p3, pilha *p4, int monte, int descartados){
      green();printf("mover cartas\n\n");white();
      dado ajuda;
      topo(move2, &ajuda);
      insere(move1, ajuda);
      retira(move2);
      printQuatro(*p1, *p2, *p3, *p4);
      printMonte(monte);
      printMov(ajuda);
}

void jogada3(pilha *p1, pilha *p2, pilha *p3, pilha *p4, int monte, int descartados, lista *primos, iterador *auxiliar){
      green();printf("adicionar cartas\n\n");white();
      dado var, aux;
      aux.naipe = '0';
      aux.valor =  0 ;
      deck(p1, p2, p3, p4, var, *auxiliar);
      printQuatro(*p1, *p2, *p3, *p4);
      *auxiliar = removerQuatro(primos);

      if(aux.naipe == 3 || aux.naipe == 4){red();}
      printf("                      monte    | %2d |\n", monte);
      printf("                      descarte |%c %d | \n", aux.naipe, aux.valor);
      white();
}

void printDescarte(dado item2){
          if(item2.naipe == 3 || item2.naipe == 4){red();}
          if(item2.valor != 11 && item2.valor != 12 && item2.valor != 13  && item2.valor != 14){
                                printf("                      descarte |%c %2d|\n", item2.naipe, item2.valor);}
          if(item2.valor == 11){printf("                      descarte |%c  J|\n", item2.naipe);}
          if(item2.valor == 12){printf("                      descarte |%c  Q|\n", item2.naipe);}
          if(item2.valor == 13){printf("                      descarte |%c  K|\n", item2.naipe);}
          if(item2.valor == 14){printf("                      descarte |%c  A|\n", item2.naipe);}
          white();
}

void printMov(dado item2){
          if(item2.naipe == 3 || item2.naipe == 4){red();}
          if(item2.valor != 11 && item2.valor != 12 && item2.valor != 13  && item2.valor != 14){
                                printf("                      mudanca  |%c %2d|\n", item2.naipe, item2.valor);}
          if(item2.valor == 11){printf("                     mudanca   |%c  J|\n", item2.naipe);}
          if(item2.valor == 12){printf("                     mudanca   |%c  Q|\n", item2.naipe);}
          if(item2.valor == 13){printf("                     mudanca   |%c  K|\n", item2.naipe);}
          if(item2.valor == 14){printf("                     mudanca   |%c  A|\n", item2.naipe);}
          white();
}

int printMonte(int monte){
   printf("                      monte    | %2d |\n", monte);
   return -1;
}

void inputs(int *rotulo, int *movimento1, int *movimento2){
   printf("faca sua jogada\n");
   scanf("%d", &rotulo);
   if(*rotulo == 'R'){
   scanf("%d", &movimento1);}
   if(*rotulo == 'M'){
   scanf("%d", &movimento1);
   scanf("%d", &movimento2);}
   if(*rotulo == 'A')
     return;
   printf("\n");
}
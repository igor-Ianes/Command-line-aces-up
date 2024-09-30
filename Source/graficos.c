#include <stdio.h>
#include <stdlib.h>
#include "graficos.h"
#include "pilha.h" 
#include "lista.h" 

  void red(){
  printf("\033[1;31m");
  }
  void blue(){
  printf("\033[1;34m");
  }
  void white(){
  printf("\033[1;37m");
  }
  void green(){
  printf("\033[1;32m");
  }

void cabecalho(){
   char copas = 3, ouros = 4, paus = 5, espadas = 6;
   red();
   printf("   ________  ________  _______   ________    \n");
   printf("  |\\   __  \\|\\   ____\\|\\  ___ \\ |\\   ____\\  \n");
   printf("  \\ \\  \\|\\  \\ \\  \\___|\\ \\   __/|\\ \\  \\___|_    \n");
   printf("   \\ \\   __  \\ \\  \\    \\ \\  \\_|/_\\ \\_____  \\ \n");
   printf("    \\ \\   __  \\ \\  \\ __ \\ \\  \\_|/_\\ \\_____  \\   \n");
   printf("     \\ \\__\\ \\__\\ \\_______\\ \\_______\\____\\_\\  \\ \n");
   printf("      \\|__|\\|__|\\|_______|\\|_______|\\_________\\  \n");
   printf("                                   \\|_________|\n");
   printf("                    ___  ___  ___  ________  ___  ___   \n");
   printf("                   |\\  \\|\\  \\|\\  \\|\\   ____\\|\\  \\|\\  \\    \n");
   printf("                   \\ \\  \\\\  \\ \\  \\ \\  \\___|\\ \\   \\\\   \\ \n");
   printf("     %c    %c         \\ \\  __  \\ \\  \\ \\  \\  __\\ \\   __   \\  \n", copas, ouros);
   printf("     %c    %c          \\ \\ \\ \\  \\ \\  \\ \\  \\|\\  \\ \\  \\  \\  \\ \n", paus, espadas);
   printf("                      \\ \\__\\ \\__\\ \\__\\ \\_______\\ \\__\\ \\__\\ \n");
   printf("                       \\|__|\\|__|\\|__|\\|_______|\\|__|\\|__|\n");
   printf("\n");
   printf("\n");

   green();      
                                                                                                                                           
     printf("|*| ==================================================  |*|\n");
     printf("\n|*|  movimentos: R + numero da pilha para remocao       |*|\n");
     printf("\n|*|  movimentos: M + numeros da pilhas a movimentar     |*|\n");
     printf("\n|*|  movimentos: A para adicionar cartas nas pilhas     |*|\n");
     printf("\n|*|    *pressione 1 para continuar e 0 para sair*       |*|\n\n");
     printf("|*| ==================================================  |*|\n\n");

   white(); 
}

void resultadoAposJogada(int comp, int compv, int mov, int descartados, int monte, char rotulo){
     int var = 1;

     red();
    if(comp == -1 &&( mov >= 1 && mov <= 4 && rotulo == 'R')){
      printf("movimento invalido\n");
      var++;
    }
    
    if(compv == -1 &&( mov >= 1 && mov <= 14 && rotulo == 'M')){
      printf("movimento invalido\n");
      var++;
    }
    
    if((mov < 1 || mov > 4) && rotulo != 'A'){ // era &&
      printf("jogada invalida*\n");
      var++;
    }
    if(rotulo == 'A' && (monte < 0 || monte == 0)){
      printf("jogada invalida\n");
      var++;
    }
    green();
    if(descartados == 24){
      blue();
      printf("  score: %2d                          \n", descartados);
      white();
      printf("=======================================\n");
      
      green();
      printf("\n    ***VITORIA!***   \n");
      vitoria();
      white();
      exit(EXIT_SUCCESS);
    }

    if(var == 1){
      blue();
      printf("  score: %2d                          \n", descartados);
      white();
      printf("=======================================\n");
    }

    white();
    printf("\ndeseja continuar?\n");
}

void printCard(dado item2){
          if(item2.naipe == 3 || item2.naipe == 4){red();}
          if(item2.valor != 11 && item2.valor != 12 && item2.valor != 13  && item2.valor != 14){
          printf("|%c %2d| ", item2.naipe, item2.valor);}
          if(item2.valor == 11){printf("|%c  J| ", item2.naipe);}
          if(item2.valor == 12){printf("|%c  Q| ", item2.naipe);}
          if(item2.valor == 13){printf("|%c  K| ", item2.naipe);}
          if(item2.valor == 14){printf("|%c  A| ", item2.naipe);} 
          white();
}

void printP(pilha *p1, pilha *p2, pilha *p3, pilha *p4) {
     pilha pp  = *p1;
     pilha pp2 = *p2;
     pilha pp3 = *p3;
     pilha pp4 = *p4;
     printf("=======================================\n");
     dado item1, item2, item3, item4;
      while(pp.topo != 0 || pp2.topo != 0 || pp3.topo != 0 || pp4.topo != 0){
          
          if(pp.topo != 0){
               item1 = pp.v[pp.topo-1];
               printCard(item1);
               pp.topo--;}
          else{printf("       ");}

           if(pp2.topo != 0){
               item2 = pp2.v[pp2.topo-1];
               printCard(item2);
               pp2.topo--;}
          else{printf("       ");}

          if(pp3.topo != 0){
               item3 = pp3.v[pp3.topo-1];
               printCard(item3);
               pp3.topo--;}
          else{printf("       ");}

          if(pp4.topo != 0){
               item4 = pp4.v[pp4.topo-1];
               printCard(item4);
               pp4.topo--;}
          else{printf("       ");}

        printf("\n");
     }
     printf("\n");
}

dado printT(pilha *p, dado *item){
     pilha pp = *p;
     dado item2;
     int espaco = 1;
      if(pp.topo != 0){
        item2 = pp.v[pp.topo-1];
          if(item2.naipe == 3 || item2.naipe == 4){red();}
          if(item2.valor != 11 && item2.valor != 12 && item2.valor != 13  && item2.valor != 14){
                                printf("                      descarte |%c %2d|\n", item2.naipe, item2.valor);}
          if(item2.valor == 11){printf("                      descarte |%c  J|\n", item2.naipe);}
          if(item2.valor == 12){printf("                      descarte |%c  Q|\n", item2.naipe);}
          if(item2.valor == 13){printf("                      descarte |%c  K|\n", item2.naipe);}
          if(item2.valor == 14){printf("                      descarte |%c  A|\n", item2.naipe);}
          white();
      }
     printf("\n");
  return item2;
}

void vitoria(){
 printf(" ___      ___ ___  _________  ________  ________  ___  ________     \n");
 printf("|\\  \\    /  /|\\  \\|\\___   ___\\   __  \\|\\   __  \\|\\  \\|\\   __   \\    \n");
 printf("\\ \\  \\  /  / | \\  \\|___ \\  \\_\\ \\  \\|\\ \\ \\  \\|\\  \\ \\  \\ \\  \\|\\   \\ \n");
 printf(" \\ \\  \\/  / / \\ \\  \\   \\ \\ \\  \\ \\  \\\\  \\ \\   _  _\\ \\  \\ \\   __   \\  \n");
 printf("  \\ \\    / /   \\ \\  \\   \\ \\  \\ \\ \\  \\\\  \\ \\  \\  \\ \\ \\  \\ \\  \\ \\   \\ \n");
 printf("   \\ \\__/ /     \\ \\__\\   \\ \\__\\ \\ \\_______\\ \\__\\ _\\  \\__\\ \\__\\ \\__ \\\n");
 printf("    \\|__|/       \\|__|    \\|__|  \\|_______|\\|__|\\|__|\\|__|\\|__|\\|__|\n");                                                        
}

void fimDeJogo(int descartados){
  printf("\nFIM DE JOGO\n");
  blue();
  printf("\nSCORE: %d\n", descartados);
  white();
}

void proxJogada(){
  printf("faca sua jogada\n");
}

void cabecalho2(int descartados){
  blue();
  printf("  score: %2d                          \n", descartados);
  white();
  printf("=======================================\n");
}
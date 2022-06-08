#include <stdio.h>
#include <locale.h>
#define vertices 7
void imprimirMatriz();
void inicializarMatriz();
void caminhos();
int matriz [vertices][vertices], i, j; //matriz 7x7
partida, chegada,varAux = -1;
void main(void){
 setlocale(LC_ALL,"Portuguese");
 inicializarMatriz();
 printf(" \t\t Preenchendo a Matriz:");
//primeiro vértice
 matriz [0][1] = 1;
 matriz [0][3] = 1;
//segundo vértice
 matriz [1][0] = 1;
 matriz [1][2] = 1;
//terceiro vértice
 matriz [2][1] = 1;
 matriz [2][6] = 1;
//quarto vértice
 matriz [3][0] = 1;
 matriz [3][4] = 1;
//quinto vértice
 matriz [4][3] = 1;
 matriz [4][5] = 1;
//sexto vértice
 matriz [5][4] = 1;
//sétimo vértice
 matriz [6][2] = 1;
 imprimirMatriz();
 printf("\n\n \t\t Digite o vértice de partida: ");
 scanf("%d", &partida);
 printf(" \t\t Digite o vértice de chegada: ");
 scanf("%d", &chegada);
 printf("\n\n===========================CAMINHO============================\n");
 caminhos(partida - 1, chegada - 1);
 imprimirMatriz();
 return 0;
}
void imprimirMatriz(){
 printf("\n\n===========================Matriz============================");
 int i, j;
 for(i = 0;i < vertices;i++){
  printf("\n |");
  for(j = 0;j < vertices; j++){
   printf("\t%d",matriz[i][j]);
  }
  printf(" |");
 }
 printf("\n=============================================================");
}
void inicializarMatriz(){
 int i, j;
 for(i = 0;i < vertices;i++){
  for(j=0;j < vertices;j++){
   matriz[i][j] = 0;
  }
 }
}
void caminhos(int vPartida, int vChegada){
 printf("\t%d",vPartida-varAux);
 int i, j, encontrado = 0, alicerce = 0;
 for(i = 0;i < vertices; i++){
  matriz[i][vPartida] = 0;
 }
 if(matriz[vPartida][vChegada] == 1){
  printf(" -> %d", vChegada-varAux);
  for(i = 0; i < vertices; i++){
   matriz[i][vChegada] = 0;
  }
 }
 else{
  while(encontrado == 0){
   if(vPartida==0 && vChegada ==7){
    for(j = 0;j < vertices; j++){
     if(matriz[vPartida][i] == 1 ){

      if(j == vChegada){
       printf("-> %d", j - varAux);
       for(i = 0;i < vertices; i++){
        matriz[i][j] = 0;
       }
      }
      else {
       for(i = 0; i < vertices ; i++){
        matriz[i][j] = 0;
       }
       vPartida = j;
      }
     }
    }
   }

   else{
    for(j = 0; j < vertices; j++){

     if(matriz[vPartida][j] == 1 ){


      if(j == vChegada){


       printf(" -> %d", j - varAux);
       for(i = 0;i < vertices; i++){
        matriz[i][j] = 0;
        encontrado = 1;
       }


      }
      else {
       printf(" -> %d", j - varAux);
       for(i = 0;i < vertices; i++){
        matriz[i][j] = 0;
       }
       vPartida = j;
      }
     }
    }
   }
  }
 }
}


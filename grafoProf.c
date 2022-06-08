#include <stdio.h>
#include <locale.h>

#define VERTICE 7

int matriz[VERTICE][VERTICE]; 

void popular();
void imprimir();
void vizinho(int v);
void caminho(int v, int d);


int main(void){
	setlocale(LC_ALL, "Portuguese");
		
	popular();
	imprimir();
	int v,p,d;
	printf("\nInsira um vértice de:");
	printf(" 1 ate %d para encontrar seus vizinhos\n",VERTICE);
	scanf("%d",&v);
	
	vizinho(v);	
	for(p=1;p<7;p++){
		printf(" \nOrigim:");
			scanf("%d",&v);
		printf("\nDestino:");
			scanf("%d",&d);
		caminho(v,d);
		   }
   
}



void popular(){
	//vertice 1
	matriz[0][1] = 1;
	matriz[0][3] = 1;
	
	//vertice 2
	matriz[1][0] = 1;
	matriz[1][2] = 1;

	//vertice 3
	matriz[2][1] = 1;
	matriz[2][6] = 1;
	
	//vertice 4
	matriz[3][0] = 1;
	matriz[3][4] = 1;
	
	//vertice 5
	matriz[4][3] = 1;
	matriz[4][5] = 1;
	
	//vertice 6
	matriz[5][4] = 1;

	
	matriz[6][2] =1;	
}

void imprimir(){
	printf("\n");
	int i,j;
	for(i=0;i<VERTICE;i++){
		for(j=0;j < VERTICE;j++){
			printf("%d  ",matriz[i][j]);
		}
		printf("\n");
	}
}

void vizinho(int v){
	printf("\nO(s) vizinho(s) do vértice %d é(são): ",v);
	
	v = v - 1;
	
	int j;
	for(j = 0;j < VERTICE;j++){
		if(matriz[v][j] == 1){
			printf("%d, ",		j+1		);
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



#include <stdio.h>
#include <locale.h>
#define V 7
#define MAX 8

int matriz[V][V];
int caminho[100];
int reset[100];
int mostrarCaminho = 0;
int ini = 0;


void inicializar();

void popular();
void vizinho(int v);
int EncontrarCaminho(int vOrigem, int vDestino, int caminho[]);
void acharPontes();


int main(void){
	setlocale(LC_ALL,"portuguese");
 	acharPontes();	
}

struct listaAresta{
	int verticeOrigem;
	int verticeDestino;
	float peso;
}aresta[MAX];

//Popula o gráfico de arestas
void inicializar(){
	
	aresta[0].verticeOrigem = 1;
	aresta[0].verticeDestino = 4;

	
	aresta[1].verticeOrigem = 4;
	aresta[1].verticeDestino = 6;
	
	aresta[2].verticeOrigem = 6;
	aresta[2].verticeDestino = 2;
	
	aresta[3].verticeOrigem = 2;
	aresta[3].verticeDestino = 1;
	
	aresta[4].verticeOrigem = 2;
	aresta[4].verticeDestino = 7;
	
	aresta[5].verticeOrigem = 6;
	aresta[5].verticeDestino = 3;
	
	aresta[6].verticeOrigem = 5;
	aresta[6].verticeDestino = 3;
	
	aresta[7].verticeOrigem = 6;
	aresta[7].verticeDestino = 5;
	
	aresta[8].verticeOrigem = 8;
	aresta[8].verticeDestino = 3;
	
}

// Popula a matriz com os valores das conexões entre os vertices
void popular(){
  
  //vertíce 1
  matriz[0][3] = 4;
  matriz[0][1] = 2;
    
  //vertíce 2
  matriz[1][0] = 1;
  matriz[1][5] = 6;
  
  //vertíce 3
  matriz[2][5] = 6;
  matriz[2][4] = 5;
  
  
  //vertíce 4
  matriz[3][5] = 6;
  matriz[3][0] = 1;
  
  //vertíce 5
  matriz[4][5] = 6;
  matriz[4][2] = 3;

  //vertíce 6
  matriz[5][3] = 4;
  matriz[5][1] = 2;
  matriz[5][2] = 3;
  matriz[5][4] = 5;
  
  //vertice 7 
  matriz[1][6] =7; 
}

// Volta o caminho pesquisado caso chege em um dead-end
void voltarCaminho(){
  int r;
  for(r = 0; r < 100;r++){
    if(caminho[r] == 0){
      caminho[r-1] = 0;
    }
  }
}

// Imprime o caminho sendo pesquisado atualmente
void MostrarCaminho(int c[]){
  int x =0;
  if(c[x] == 0){printf("Não há caminho a ser mostrado.");}
  else{
   
    x ++;
    if(c[x] == 0){}
    else{
      do{
       
        x = x+1;
      }
      while(c[x] != 0);
    }
  }
}

// Acredito que mostra o(s) vertice(s) vizinho(s) ao selecionado
void zerarCaminho(){
  int x;
  for(x = 0;x < 100;x++){
    caminho[x] = 0;
  }
}

// Encontra o caminho de qualquer vertice para qualquer vertice
int encontrarCaminho(int vOrigem, int vDestino, int caminho[]){
  
  vDestino --;
  vOrigem --;
  int estaNoCaminho = 0;
  int i,x,c,ca;

 
 
  
  
  //Adiociona o numero origem ao final da lista ciminho
  for(ca = 0;ca<100;ca++){
    if(caminho[ca] == 0){
      caminho[ca] = vOrigem+1;
      if(vDestino != vOrigem){
        
        //printf("\nCaminho alterado, ");
        // printf("%d foi adicionado ao caminho que agora é ", vOrigem+1);
        // MostrarCaminho(caminho);
        // printf(".");
      }
      break;
    }
  }

  // Confere se o numero atualmente sendo analisado é o desejado
  for(x = 0; x<100; x++){
    
    if(vDestino+1 == caminho[x]){
      

      MostrarCaminho(caminho);

      mostrarCaminho = 1;
      zerarCaminho();
      ini = 0;
      return 1;
      
    }
  }

  // printf("\n\nMostrar Caminho: %d\n\n", mostrarCaminho);
  for(i = 0; i < MAX; i++){
    // printf("\nAtualmente analisando %d na coluna de %d ", grafo[vOrigem][i],vOrigem);
    estaNoCaminho = 0;
    
    // Define se o vertice que esta atualmente em pesquisa ja esta no caminho passado
    for(c = 0; c < 100;c++){
      if(matriz[vOrigem][i] == caminho[c]){
        estaNoCaminho = 1;
      }
    }
    
    // Testa a fileira do vertice em quesão, se não é um zero e não estiver no caminho passado, toma como alvo
    if(matriz[vOrigem][i] != 0 && estaNoCaminho == 0){
      //printf("\nAchou um novo vertice, o %d", grafo[vOrigem][i]);
      if(encontrarCaminho(matriz[vOrigem][i],vDestino+1,caminho) == 1){
        return 1;
      }
      else{
        voltarCaminho();
        //printf("\nVoltou um Vertice");
      }
    }
  }
  return 0 ;
}

//Acha pontes dentro do grafo
void acharPontes(){
  inicializar();
  popular();
  int i, j;
  int oa;
  int da;
  for(i = 0; i < MAX; i++){
    oa = aresta[i].verticeOrigem - 1;
    da = aresta[i].verticeDestino - 1;
    matriz[oa][da] = 0;
    matriz[da][oa] = 0;
    if(encontrarCaminho(oa+1, da+1, caminho) == 0 || encontrarCaminho(da+1, oa+1, caminho) == 0){
      zerarCaminho();
      aresta[i].peso = 100;
    }
    matriz[oa][da] = da+1;
    matriz[da][oa] = oa+1;
    
  }
  for(j = 0; j < MAX; j++){
    if(aresta[j].peso == 100){
      printf("A aresta N %d do vertice %d ao %d é uma ponte\n", j+1, aresta[j].verticeOrigem, aresta[j].verticeDestino );
    }
  }
}



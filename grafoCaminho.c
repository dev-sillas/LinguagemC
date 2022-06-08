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

// imprimi a matriz
void imprimir(){
		printf("\n");
    int i,j,k,l;
    printf("\t\t");
    for(k=0;k< V ;k++){
      printf("%d\t",k+1);
    }
  printf("\n\t  ");
    for(l=0;l<V;l++){
      printf("____");
    }
  printf("\n");
    for(i=0;i < V;i++){
      printf("%d\t|   ", i+1);
        for(j=0;j < V; j++){
            printf("%d\t",grafo[i][j]);
        }
        printf("\n");
    }
}

//imprime arestas com indice, origem e destino
void imprimir1(){
	printf("\n------Lista de Aresta------\n");
	printf(" nº aresta\tOrigem\tDestino\n");
	int i;
	for(i = 0; i < MAX; i++){
    printf("    %d    \t  %d  \t   %d  \n", i+1, aresta[i].verticeOrigem, aresta[i].verticeDestino);
	}
}

//imprime arestas com indice, origem e destino de forma amis simples
void imprimir2(){
	printf("\n  INDEX   Origem   Destino\n");
	int i;                   
	for(i = 0; i < MAX; i++){
    printf("\t%d\t\t%d\t<=>\t %d  \n", i+1, aresta[i].verticeOrigem, aresta[i].verticeDestino);
	}
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



// Acredito que mostra o(s) vertice(s) vizinho(s) ao selecionado
void vizinho(int v){
    printf("\nO(s) vizinho(s) do vértice %d é(são): ", v);
    v = v - 1;
    int j;
    for(j = 0; j < MAX; j++){
        if(grafo[v][j] == 1){ 
            printf("%d, ",  j+1  );
        }
    }
}

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

  if(ini == 0){
    //printf("\nProcurando o caminho do vértice %d a partir do vertice %d", vDestino+1, vOrigem+1);
    ini = 1;
  }
  
  //Adiociona o numero origem ao final da lista ciminho
  for(ca = 0;ca<100;ca++){
    
    if(caminho[ca] == 0){
      
      caminho[ca] = vOrigem+1;
      if(vDestino != vOrigem){
        
        //printf("\nCaminho alterado, ");
        //printf("%d foi adicionado ao caminho que agora é ", vOrigem+1);
        //MostrarCaminho(caminho);
        //printf(".");
      }
      break;
    }
  }

  // Confere se o numero atualmente sendo analisado é o desejado
  for(x = 0; x<100; x++){
    
    if(vDestino+1 == caminho[x]){
      
      //printf("\nCaminho encontrado, o caminho é:");
      //MostrarCaminho(caminho);
      //printf("\n\n");
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
      if(grafo[vOrigem][i] == caminho[c]){
        estaNoCaminho = 1;
      }
    }
    
    // Testa a fileira do vertice em quesão, se não é um zero e não estiver no caminho passado, toma como alvo
    if(grafo[vOrigem][i] != 0 && estaNoCaminho == 0){
      //printf("\nAchou um novo vertice, o %d", grafo[vOrigem][i]);
      if(encontrarCaminho(grafo[vOrigem][i],vDestino+1,caminho) == 1){
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
    grafo[oa][da] = 0;
    grafo[da][oa] = 0;
    //printf("\n----------------Buscando caminho na aresta N %d entre os vertices %d e %d----------------\n", i+1, aresta[i].verticeOrigem, aresta[i].verticeDestino);
    if(encontrarCaminho(oa+1, da+1, caminho) == 0 || encontrarCaminho(da+1, oa+1, caminho) == 0){
      zerarCaminho();
      aresta[i].peso = 100;
    }
    grafo[oa][da] = da+1;
    grafo[da][oa] = oa+1;
    
  }
  for(j = 0; j < MAX; j++){
    if(aresta[j].peso == 100){
      printf("\nA aresta N %d do vertice %d ao %d é uma ponte", j+1, aresta[j].verticeOrigem, aresta[j].verticeDestino );
    }
  }
}



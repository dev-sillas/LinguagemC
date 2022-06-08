from collections import defaultdict
class Grafo:
  
    def __init__(iniciar,vertices):
        iniciar.V= vertices
        iniciar.Grafo = defaultdict(list) 
        iniciar.Time = 0
        
    def aresta(iniciar,u,v):
        iniciar.Grafo[u].append(v)
        iniciar.Grafo[v].append(u)
    
    def Pontes(iniciar,u, visitou, Vtual, temp2, temp):
        children = 0
        visitou[u]= True
        temp[u] = iniciar.Time
        temp2[u] = iniciar.Time
        iniciar.Time += 1

        for v in iniciar.Grafo[u]:
            if visitou[v] == False :
                Vtual[v] = u
                children += 1
                iniciar.Pontes(v, visitou, Vtual, temp2, temp)
                temp2[u] = min(temp2[u], temp2[v])
  
                if temp2[v] > temp[u]:
                    print ("%d--%d" %(u,v))
                          
            elif v != Vtual[u]: 
                temp2[u] = min(temp2[u], temp[v])
  
    def encontrarPonte(iniciar):
        visitou = [False] * (iniciar.V)
        temp = [float("Inf")] * (iniciar.V)
        temp2 = [float("Inf")] * (iniciar.V)
        Vtual = [-1] * (iniciar.V)
        
        for i in range(iniciar.V):
            if visitou[i] == False:
                iniciar.Pontes(i, visitou, Vtual, temp2, temp)

if __name__ == '__main__':  
    g = Grafo(7)
    g.aresta(0, 3)
    g.aresta(3, 5)
    g.aresta(5, 1)
    g.aresta(1, 0)
    g.aresta(1, 6)
    g.aresta(5, 2)
    g.aresta(4, 2)
    g.aresta(5, 4) 
   
    print("\nAs pontes são:")
    g.encontrarPonte()

def Arestas(grafo, v, u): 
    grafo[v].append(u)
    grafo[u].append(v) 
    return grafo
def Colorir(grafo, V):
    cor = [-1] * V
    cor[0] = 0;
    Aux = [False] * V
    for u in range(1, V):
        for i in grafo[u]:
            if (cor[i] != -1):
                Aux[cor[i]] = True
        cr = 0
        while cr < V:
            if (Aux[cr] == False):
                break 
            cr += 1
        cor[u] = cr
        for i in grafo[u]:
            if (cor[i] != -1):
                Aux[cor[i]] = False
    for u in range(V):
        print("vertice", u, " ---> Esta com a color", cor[u])

if __name__ == '__main__':
     
    l1 = [[] for i in range(7)]
    l1 = Arestas(l1, 0, 3)
    l1 = Arestas(l1, 3, 5)
    l1 = Arestas(l1, 5, 1)
    l1 = Arestas(l1, 1, 0)
    l1 = Arestas(l1, 1, 6)
    l1 = Arestas(l1, 5, 2)
    l1 = Arestas(l1, 4, 2)
    l1 = Arestas(l1, 5, 4)
    print("Coloração do grafo:")
Colorir(l1, 7)

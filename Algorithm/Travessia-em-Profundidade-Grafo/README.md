# README.md

ℹ️ **Descrição:**

Este código em C implementa um grafo e a travessia em profundidade (DFS) em um grafo não direcionado. O grafo é representado por uma estrutura de lista de adjacências e a DFS começa a partir de um vértice inicial especificado.

📄 **Estruturas de Dados:**

O código utiliza duas estruturas de dados principais:

1. `struct Node`: Representa um nó em um grafo e contém um campo de dados inteiro e um ponteiro para o próximo nó na lista de adjacências.

2. `struct Graph`: Representa o grafo e contém o número de vértices, uma lista de listas de adjacências e um vetor para rastrear os vértices visitados.

🔨 **Funções:**

O código contém as seguintes funções:

- `createNode(int data)`: Cria um novo nó com o valor `data`.

- `createGraph(int vertices)`: Cria um grafo com o número especificado de vértices.

- `addEdge(struct Graph* graph, int src, int dest)`: Adiciona uma aresta entre os vértices `src` e `dest` no grafo. Para um grafo não direcionado, a função adiciona a aresta no sentido contrário também.

- `DFS(struct Graph* graph, int vertex)`: Realiza a travessia em profundidade (DFS) a partir do vértice especificado, imprimindo os vértices visitados.

🚀 **Execução:**

O código cria um grafo com 5 vértices e adiciona algumas arestas. Em seguida, inicia uma travessia em profundidade (DFS) a partir do vértice 0 e imprime os vértices visitados.

🏃 **Instruções de Compilação e Execução:**

Para compilar e executar o código, siga os passos a seguir:

```shell
gcc main.c -o nome_do_programa
./nome_do_programa

👏 Contribuições:

Contribuições são bem-vindas! Sinta-se à vontade para melhorar este código ou adicionar recursos adicionais.

📜 Licença:

Este código é distribuído sob a licença MIT. Consulte o arquivo LICENSE para obter detalhes.

📧 Contato:

Para qualquer dúvida ou sugestão, sinta-se à vontade para entrar em contato.
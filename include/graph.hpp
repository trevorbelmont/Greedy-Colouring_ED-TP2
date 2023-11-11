#ifndef GRAPH_HPP
#define GRAPH_HPP

// #include <iostream>

#include "lista_adjacencia.hpp"
/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Nenhuma outra alteração neste arquivo é permitida
 */

class Grafo {
 public:
  // Cria grafo sem alocar memória ou limitar número de vértices.
  Grafo();
  // Cria grafo com capacidade inicial para "n" vértices (alocados e instanciados, PORÉM NÃO INICIALIZADOS).
  Grafo(int n);

  // Chama destrutor da Lista de Adjacênias.
  ~Grafo();

  void allocate(int n);

  int size();

  // Insere vértice no grafo com chave de valor k
  void InsereVertice(int k);
  // cria aresta entre os vértices v e w. (apenas atualiza a lista de adjacência do vértice v. É preciso atualizar a lista do vértice w também)
  void InsereAresta(int v, int w);

  // Número de vértices/nodos no grafo
  int QuantidadeVertices();

  // Retorna o número de arestas total do grafo. Tenda em vista uma lista de adjacências de um grafo não dirigido, i.e:   (Arestas Totais)/2;
  int QuantidadeArestas();    // COMPROMISSO: Durante a inicialização do grafo as arestas devem ser definidas de forma redundante - como definido na especificação.
  // Ou seja, é preciso informar na criaçao de cada vértice quais são seus vizinhos para que uma arestas seja criada de maneira precisa.
  // A implementação atual de AdjList suporta "grafos não dirigidos degenerado". Isso foi uma opção de arquitetura, de maneira que esta classe pudesse também comportar grafos dirigidos.
  // Ainda mais, durante a ordenação countingSort aqui apresentada, AdjLists (que poderiam ser vistas como grafos degenerados) são usadas como estrutura de dados auxiliar.
  

  // Retorna o id do nodo/vértice de MENOR grau (leia-se, número de vizinhos) no grafo.
  int GrauMinimo();
  // Retorna o id do nodo/vértice de MAIOR grau (leia-se, número de vizinhos) no grafo.
  int GrauMaximo();

  // Listas todos os vizinhos do Nodo v em uma linha.
  void ImprimeVizinhos(int v);

  // Dado uma matriz ordenada do grafo atual em de ids (ordered[*][0]) por cor (ordered[*][1]]), checa se este grafo é colorido por um algoritmo guloso.
  // COMPROMISSO: a matriz ordenada tem o mesmo número de linhas que o número de vértices do grafo - afinal essa matriz é uma representação ordenada deste mesmo grafo.
  bool CheckGreedy(int ordered[][2]);

  AdjList* vertices;  // ENCAPSULAR Lista de adjacência dinâmicamente alocada ¬¬¬ ¬ ¬ ¬
  // Talvez usar private, para que apenas a classe Grafo tenha acesso a lista. ¬
 private:
  
  int size_;    // tamanho atual do grafo  - equivale a Grafo.QuantidadeVertices().
  // Número máximo de vértices comportados no Grafo atual. Ainda (¬) não há função get.
  // É definido durante a alocação dinâmica do ponteiro único de AdjList "vertices" durante a inicialização do grafo.
  int maxVertex_; 
};

#endif
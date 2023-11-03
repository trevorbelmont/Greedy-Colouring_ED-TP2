#ifndef GRAPH_HPP
#define GRAPH_HPP

// #include <iostream>

#include "lista_adjacencia.hpp"
/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Nenhuma outra alteração neste arquivo é permitida
 */

class Grafo {
 public:
  // Cria grafo sem alocar ou limitar número de vértices.
  Grafo();
  // Cria grafo com n vértices;
  Grafo(int n);
  ~Grafo();

  void allocate(int n);

  int size();

  // Insere vértice no grafo com chave de valor k
  void InsereVertice(int k);
  // cria aresta entre os vértices v e w. (apenas atualiza a lista de adjacência do vértice v. É preciso atualizar a lista do vértice w também)
  void InsereAresta(int v, int w);

  int QuantidadeVertices();
  int QuantidadeArestas();

  int GrauMinimo();
  int GrauMaximo();

  void ImprimeVizinhos(int v);

  AdjList* vertices;  // Lista de adjacência dinâmicamente alocada encapusular

 private:
  int size_;
  int maxVertex_;
};

#endif
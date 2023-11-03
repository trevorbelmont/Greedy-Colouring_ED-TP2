#ifndef LISTA_ADJACENCIA_HPP
#define LISTA_ADJACENCIA_HPP

#include "lista_encadeada.hpp"

struct NodeList {
  int id = -1;
  int colour = -1;

  List l;
};

class AdjList {
 public:
  // Cria lista de adjacência sem alocar memória
  AdjList();
  // Cria lista de Adjacência de tamanho máximo igual a n;
  AdjList(int n);

  // Realoca n Nodelists no array de da lista de adjacência. Preser
  void reallocate(int n);

  // Insere n vértices sem atribuir valores
  void multInsert(int n);
  void insert(int k);
  void update(int vertex, int value);
  bool empty();
  int size();
  List* get(int vertex);
  int getId(int vertex);
  void setId(int vertex, int k);
  void setColour(int vertex, int colour);
  int getColour(int vertex);
  void removeLast();


  // Desaloca memória
  ~AdjList();

 private:
  int size_;
  int maxSize_;
  NodeList* adj_;  // Array dinâmicamente alocado de nodeLists (vértices/listas de adjacências);
};

#endif
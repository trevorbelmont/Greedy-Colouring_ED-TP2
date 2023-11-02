#ifndef LISTA_ADJACENCIA
#define LISTA_ADJACENCIA

#include "lista_encadeada.hpp"

struct NodeList {
  int key = -1;
  int colour = 0;

  List l;
  NodeList* prev;
  NodeList* next;
};

class AdjList {
 public:
  AdjList();

  ~AdjList();

  void multInsert(int n);
  void insert(int k);
  void update(int vertex, int value);
  bool empty();
  int size();
  List* get(int vertex);
  int getKey(int vertex);
  void setColour(int vertex, int colour);
  int getColour(int vertex);
  void removeLast();

 private:
  int size_;
  NodeList* first_;
  NodeList* last_;
};

#endif
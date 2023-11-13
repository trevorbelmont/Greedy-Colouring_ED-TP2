#ifndef LISTA_ADJACENCIA_HPP
#define LISTA_ADJACENCIA_HPP

#include "lista_alocada.hpp"

// Essa estrutura, NodeList, é aquela que representa cada vértice, 
// Essa implement. de lista de adjcência é básicamente um array sequencial e dinâmico de NodeLists.
struct NodeList {
  int id = -1;
  int colour = -1;

  List l;
};

// A classe Lista de Adjacências em si.
class AdjList {
 public:
  // Instancia uma Lista de Adjacências sem alocar memória
  AdjList();
  // Instancia E INICIALIZA uma Lista de Adjacências de tamanho máximo igual a n;
  AdjList(int n);

  // Realoca n Nodelists no array de da lista de adjacência. Preser
  void reallocate(int n);

  // Insere n vértices sem atribuir valores
  void multInsert(int n);
  
  // Insere um novo vértice na última posiçaõ disponível com o id passado coo parâmetro, k.
  void insert(int k);
  // Atualiza a lista de vizinhos do "vertex" (já existente) com o vizinho "value"
  void update(int vertex, int value);
  // Checa vacuidade.
  bool empty();
  // Devolve o tamanho atual - número de elementos válidos e alcançáveis.
  int size();
  // Devolve o ponteiro para o vértice (Nodelist) da posição "vertex".
  List* get(int vertex);
  // Devolve o id do vértice na posição "vertex".
  int getId(int vertex);
  // Atualiza o id do vértice na posição "vertex", para o valor "k".
  void setId(int vertex, int k);
  // Atualiza a cor do vértice "vertex" para o valor "colour".
  void setColour(int vertex, int colour);
  // Devolve a cor do vértice "vertex". 
  int getColour(int vertex);
  // Remove (torna inacessível) o último vértice (NodeList) na Lista de adjcência, retornando seu id (ou -404, caso falhar).
  int removeLast();


  // Desaloca toda memória (destruindo cada lista de vizinhos) e liberando o ponteiro do array de NodeList (explicitamente).
  ~AdjList();

 private:
  int size_;
  int maxSize_;
  NodeList* adj_;  // Array dinâmicamente alocado de nodeLists (vértices/listas de adjacências);
};

#endif
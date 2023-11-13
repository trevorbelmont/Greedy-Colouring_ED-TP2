#include "lista_adjacencia.hpp"

#include "lista_alocada.hpp"

AdjList::AdjList() {
  maxSize_ = 0;
  size_ = 0;
}
AdjList::AdjList(int n) {
  size_ = 0;
  adj_ = new NodeList[n];
  maxSize_ = n;

  // Inicializa todas as sublistas com tamanho máximo igual ao número de vértices (para grafos completos);
  for (int i = 0; i < maxSize_; i++) {
    adj_[i].l.reallocate(n);
  }
}

void AdjList::reallocate(int n) {
  if (empty()) {
    if (maxSize_ > 0) {
      delete[] adj_;
    }
    adj_ = new NodeList[n];
  } else {
    NodeList aux[size_];
    for (int i = 0; i < size_; i++) {
      aux[i] = adj_[i];
    }
    delete[] adj_;
    adj_ = new NodeList[n];
    maxSize_ = n;
    for (int i = 0; i < size_; i++) {
      adj_[i] = aux[i];
    }
  }
}

int AdjList::size() {
  return size_;
}

bool AdjList::empty() {
  return size_ == 0;
}

void AdjList::insert(int k, int subList_size) {
  // Se alista de adjacências não foi inicializada,
  // inicializa alocando 100 nodelists
  if (maxSize_ == 0) {
    reallocate(100);
    maxSize_ = 100;
  }
  // Insere o novo elemento na última posição - com o id designado, k;
  if (size_ < maxSize_) {
    adj_[size_].id = k;
    if (subList_size > 0) {
     adj_ [size_].l.reallocate(subList_size);
    }
    size_++;
  }
}

void AdjList::multInsert(int n, int subList_sizes) {
  int i = 0;
  while (i < n && size_ < maxSize_) {
    insert(i, subList_sizes);
    i++;
  }
}

void AdjList::update(int vertex, int value) {
  if (vertex < size_ && vertex >= 0) {
    adj_[vertex].l.insert(value);
  }
}

List* AdjList::get(int vertex) {
  if (empty()) {
    return nullptr;
  } else if (vertex >= 0 && vertex < size_) {
    return &adj_[vertex].l;
  }
  return nullptr;
}
int AdjList::getId(int vertex) {
  if (empty()) {
    return -1;
  } else if (vertex >= 0 && vertex < size_) {
    return adj_[vertex].id;
  }
  return -1;
}

void AdjList::setId(int vertex, int k) {
  if (empty()) {
    return;
  } else if (vertex >= 0 && vertex < size_) {
    adj_[vertex].id = k;
  }
}

void AdjList::setColour(int vertex, int colour) {
  if (empty()) {
    return;
  } else if (vertex >= 0 && vertex < size_) {
    adj_[vertex].colour = colour;
  }
}

int AdjList::getColour(int vertex) {
  if (empty()) {
  } else if (vertex >= 0 && vertex < size_) {
    return adj_[vertex].colour;
  }
  return -1;
}

int AdjList::removeLast() {
  // Se não estiver vazia retorna o id do vértice a ser removido.
  if (size_ > 0) {
    int idRemoved = getId(size_ - 1);
    size_--;
    return idRemoved;

  }  // Caso a AdjList esteja vazia, retorna "-404",
  // assumindo que os ids dos vértices são, por definição, números naturais.
  else {
    return -404;
  }
  // =============== NOTA sobre o método removeLast():  ====================//
  //
  // Este método não devolve uma CÒPIA do vértice removido.
  // Por cuidado uma cópia deste nodo poderia ser retornado, aumentando a complexidade da função de remoção.
  // Ainda que o vértice "removido" não é de fato apagado (apenas se torna inacessível),
  // este vértice não necessariamente poderia ser devolvido por ponteiro ou referência.
  // Isso porque essa seria uma escolha perigosa no manuseio de vértices em operações sequenciais.
  // Dito isso, sobrecarregar este método com um de natureza NodeList que devolvesse uma CÓPIA daquilo que se tornou inacessível,
  // poderia ser bastante útil. Porém não é necessariamente uma demanda - uma vez que pode ser feito usando a interface pública em 2 linhas de código.
}

AdjList::~AdjList() {
  // Libera e destrói todas as listas de vizinhos em cada NodeList
  for (int i = 0; i < maxSize_; i++) {
    adj_[i].l.~List();
  }
  // Libera o ponteiro  adj_, destuindo todos os NodeLists.
  delete[] adj_;

  // Retorna a AdjList para forma não inicializada.
  size_ = maxSize_ = 0;
}

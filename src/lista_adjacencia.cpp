#include "lista_adjacencia.hpp"

#include "lista_encadeada.hpp"

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

void AdjList::insert(int k) {
  if (maxSize_ == 0) {  // Se alista de adjacências não foi inicializada, inicializa alocando 100 nodelists
    reallocate(100);
    maxSize_ = 100;
  }
  if (size_ < maxSize_) {
    adj_[size_].id = k;
    size_++;
  }
}

void AdjList::multInsert(int n) {
  int i = 0;
  while (i < n && size_ < maxSize_) {
    insert(i);
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
AdjList::~AdjList() {
  for (int i = 0; i < maxSize_; i++) {
    adj_[i].l.~List();
  }
  delete[] adj_;

  size_ = maxSize_ = 0;
}

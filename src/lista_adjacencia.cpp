#include "lista_adjacencia.hpp"

#include "lista_encadeada.hpp"

AdjList::AdjList() {
  size_ = 0;
  first_ = last_ = nullptr;
}
AdjList::~AdjList() {
  while (size_ > 0) {
    removeLast();
  }
  first_ = last_ = nullptr;
}

int AdjList::size() {
  return size_;
}

bool AdjList::empty() {
  return size_ == 0;
}

void AdjList::insert(int k) {
  NodeList* no = new NodeList;
  no->key = k;


  if (empty()) {
    first_ = last_ = no;
    size_++;
  } else {
    no->prev = last_;
    last_->next = no;
    last_ = no;
    size_++;
  }
}

void AdjList::multInsert(int n) {
  int i = 0;
  while (i < n) {
    insert(i);
    i++;
  }
}

void AdjList::update(int vertex, int value) {
  if (vertex < size_ && vertex >= 0) {
    NodeList* aux = first_;
    for (int i = 0; i < vertex; i++) {
      aux = aux->next;
    }
    aux->l.insert(value);
  }
}

List* AdjList::get(int vertex) {
  if (empty()) {
    return nullptr;
  } else {
    NodeList* aux = first_;
    for (int i = 0; i < vertex; i++) {
      aux = aux->next;
    }
    return &(aux->l);
  }
}
int AdjList::getKey(int vertex) {
  if (empty()) {
    return -1;
  } else {
    NodeList* aux = first_;
    for (int i = 0; i < vertex; i++) {
      aux = aux->next;
    }
    return aux->key;
  }
}
void AdjList::setColour(int vertex, int colour) {
  if (vertex < size_ && vertex >= 0) {
    NodeList* aux = first_;
    for (int i = 0; i < vertex; i++) {
      aux = aux->next;
    }
    aux->colour = colour;
  }
}

int AdjList::getColour(int vertex) {
  if (empty()) {
    return -1;
  } else {
    NodeList* aux = first_;
    for (int i = 0; i < vertex; i++) {
      aux = aux->next;
    }
    return aux->colour;
  }
}


void AdjList::removeLast() {
  if (size() > 0) {
    NodeList* aux = last_;
    aux->l.~List();
    last_ = last_->prev;
    delete aux;
    size_--;
  }
}
#include "lista_encadeada.hpp"

#include <iostream>

using namespace std;

List::List() {
  size_ = 0;
  first_ = last_ = nullptr;
}

int List::size() {
  return size_;
}

bool List::empty() {
  return (size_ == 0);
}

void List::insert(int key) {
  Node* no = new Node;
  no->key = key;

  if (empty()) {
    first_ = last_ = no;
  } else {
    last_->next = no;
    no->prev = last_;
    last_ = no;
  }
  size_++;
}

int List::get(int i) {
  Node* x = first_;

  if (i >= 0 && i < size_) {
    for (int j = 0; j < i; j++) {
      x = x->next;
    }
  }
  return x->key;
}

void List::print() {
  Node* x = first_;

  for (int j = 0; j < size_; j++) {
    cout << x->key << " ";
    x = x->next;
  }
  cout << endl;
}
void List::removeLast() {
  if (size() > 0) {
    Node* aux = last_;
    last_ = last_->prev;
    delete aux;
    size_--;
  }
}

List::~List() {
  while (size_ > 0) {
    removeLast();
  }
  last_ = first_ = nullptr;
}

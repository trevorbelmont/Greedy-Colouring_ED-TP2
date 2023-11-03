#include "lista_encadeada.hpp"

#include <iostream>

List::List() {
  size_ = 0;
  maxSize_ = 100;
  keys_ = new int[100];
}

List::List(int n) {
  size_ = 0;
  keys_ = new int[n];
  maxSize_ = n;
}

void List::reallocate(int n) {
  if (empty()) {
    if (maxSize_ > 0) {
      delete[] keys_;
    }
    keys_ = new int[n];
    maxSize_ = n;
  } else {  // faz back up dos dados, realoca e recarrega o array adj_;
    // max é o número máximo de elementos que devem ser preservados - em função do novo tamanho do array
    int max = (n < size_) ? n : size_;
    int aux[max];
    for (int i = 0; i < max; i++) {
      aux[i] = keys_[i];
    }
    delete[] keys_;
    keys_ = new int[n];
    maxSize_ = n;

    for (int i = 0; i < max; i++) {
      keys_[i] = aux[i];
    }
  }
}

int List::size() {
  return size_;
}

bool List::empty() {
  return (size_ == 0);
}

void List::insert(int key) {
  if (size_ < maxSize_) {
    keys_[size_] = key;
    size_++;
  }
}

int List::get(int i) {
  if (i >= 0 && i < size_) {
    return keys_[i];
  } else {
    return -1;
  }
}

void List::print() {
  for (int j = 0; j < size_; j++) {
    std::cout << keys_[j] << " ";
  }
  std::cout << std::endl;
}
void List::removeLast() {
  if (size() > 0) {
    size_--;
  }
}

List::~List() {
  if (maxSize_ == 0) {
    return;
  }
  delete[] keys_;
  size_ = maxSize_ = 0;
}
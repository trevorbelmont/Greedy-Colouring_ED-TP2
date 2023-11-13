#include "lista_alocada.hpp"

#include <iostream>

List::List() {
  size_ = 0;
  maxSize_ = 0;
}

List::List(int n) {
  size_ = 0;
  keys_ = new int[n];
  maxSize_ = n;
}

bool List::forceSet(int index, int value) {
  if (index >= 0 && index < maxSize_) {
    keys_[index] = value;
    if (index < size_) {
      return true;  // Se alguma informação previamente inicializada foi ALTERADA
    } else {
      size_ = index + 1;  // Atualiza tamanho. !!! Pode tornar lixo de memória acessível.
      return false;       // Se nenhuma informação foi ALTERADA.
    }
  }
  return false;  // Índice inválido. Não houve alterações
}

bool List::update(int index, int value) {
  if (index >= 0 && index < size_) {
    keys_[index] = value;
    return true;
  }
  return false;  // Índice inválido. Não houve alterações
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

bool List::insert(int key) {
  if (size_ < maxSize_) {
    keys_[size_] = key;
    size_++;
    return true;
  }
  return false;  // Caso não haja espaço alocado disponível.
}

// defaultValue assume o valor zero, quando não explicitado na chamada.
int List::multInsert(int n, int defaultValue = 0) {
  int sucess = 0;
  while (sucess < n && insert(defaultValue)) {  // Tenta inserir os n elementos enquanto for possível inserir elementos.
    sucess++;
  }
  return sucess;  // Retorna o número de elementos inseridos com sucess;
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
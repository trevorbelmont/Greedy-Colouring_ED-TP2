#include "graph.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Grafo::Grafo() {
  size_ = 0;
  maxVertex_ = 0;
}

Grafo::Grafo(int n) {
  size_ = 0;
  vertices = new AdjList(n);
  maxVertex_ = n;
}

Grafo::~Grafo() {
  vertices->~AdjList();
  delete[] vertices;
}


void Grafo::allocate(int n) {
  if(maxVertex_ > 0){
    delete [] vertices;
  }
  vertices = new AdjList(n);
  maxVertex_ = n;
  size_ = 0;
}

int Grafo::size() {
  return size_;
}

void Grafo::InsereVertice(int k) {
  vertices->insert(k);
  size_++;
}

void Grafo::InsereAresta(int v, int w) {
  if (v < size_ && w < size_ && v >= 0 && w >= 0) {
    vertices->update(v, w);
    // vertices.update(w, v); //a especificação da pa é redundante na entrada de arestas, por isso essa linha foi omitida.
  } else {
    cout << "Vértice ainda não foi criado! Há " << size_ << endl;
    cout << "Porém o programa está tentando criar arestas entre os vértices " << v << " e " << w << "." << endl;
  }
}

int Grafo::QuantidadeVertices() {
  return size_;
}

int Grafo::QuantidadeArestas() {
  int doubleEdges = 0;
  for (int i = 0; i < size_; i++) {
    doubleEdges += vertices->get(i)->size();
  }
  return doubleEdges / 2;
}

int Grafo::GrauMinimo() {
  int min = vertices->get(0)->size();
  for (int i = 0; i < size_; i++) {
    min = (vertices->get(i)->size() < min) ? vertices->get(i)->size() : min;
  }
  return min;
}

int Grafo::GrauMaximo() {
  int max = vertices->get(0)->size();
  for (int i = 0; i < size_; i++) {
    max = (vertices->get(i)->size() > max) ? vertices->get(i)->size() : max;
  }
  return max;
}

void Grafo::ImprimeVizinhos(int v) {
  cout << vertices->getId(v) << " (c-" << vertices->getColour(v) << "):  ";
  vertices->get(v)->print();
}

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
  // vertices->~AdjList();
  delete vertices;

  // Valgrind apontou que apenas liberando a Lista de Adjcência é minimiza o tanto de memória vazando. Foi tetado apenas liberação da AdjList, "vertice", explicitamente e usando as duas linhas - essa foi a solução melhor.
}

void Grafo::allocate(int n) {
  if (maxVertex_ > 0) {
    delete[] vertices;
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
  cout << vertices->getId(v) << " (c" << vertices->getColour(v) << "):  ";
  vertices->get(v)->print();
}

bool Grafo::CheckGreedy(int ord[][2]) {
  int i = 0;
  while (i < QuantidadeVertices()) {         // checa se todos os vértices ordenados satisfazem condição
    int corMax = ord[i][1];                  // a cor máxima (a cor do vértice i)
    List* vizin = vertices->get(ord[i][0]);  // ponteiro para a lista de adjacência do i-ésimo vértice no array ordenado
                                             // checa se todas as cores  inferiores a cor do vértice i, estão presentes nos vizinhos de i
                                             // Se qualquer uma das cores inferiores não estiver presente, retorna falso imediatamente e cessa a checagem

    bool neighborColours[corMax];  // array de booleanas para check-list de cada cor inferior

    for (int j = 0; j < corMax; j++) {
      neighborColours[j] = false;  // inicializa toda a checklist de cores com falso;
    }

    // Itera pela lista de adjacência do vértice i, através do ponteiro de lista "vizin".
    for (int j = 0; j < vizin->size(); j++) {
      int corVizin = vertices->getColour(vizin->get(j));  // recebe a cor do vizinho que se está checando

      // Checa se a cor do vértice vizinho é menor que a cor do vértice atual, corMax.
      // caso sim, marca essa cor na check-list booleana.
      if (corVizin < corMax) {
        neighborColours[corVizin] = true;
      }
    }

    for (int j = 0; j < corMax; j++) {
      if (neighborColours[j] == false) {
        cout << "vertice: " << ord[i][0] << "   " << j << "/" << corMax << endl;
        return false;
      }
    }
    i++;
  }
  return true;
}

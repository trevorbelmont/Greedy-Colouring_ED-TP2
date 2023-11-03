#include <iostream>
#include <sstream>
#include <string>

#include "graph.hpp"
#include "muita_Sort.hpp"

using namespace std;

// cria o grafo g a partir da entrada padrão.
void createGraph(Grafo* g);

int main() {
  string function = "-n";

  Grafo g;

  createGraph(&g);
  if (function == "-d") {
    //   cout << "Testes básicos: " << endl;
    cout << g.QuantidadeVertices() << endl;
    cout << g.QuantidadeArestas() << endl;
    cout << g.GrauMinimo() << endl;
    cout << g.GrauMaximo() << endl;
  } else if (function == "-n") {
    //   cout << " Imprime vizinhos: " << endl;
    for (int i = 0; i < g.QuantidadeVertices(); i++) {
      g.ImprimeVizinhos(i);
    }

    // Cria lista paralela de vértices por coloração
    int cor[g.QuantidadeVertices()][2];
    for (int i = 0; i < g.size(); i++) {
      cor[i][1] = g.vertices->getColour(i);
      cor[i][0] = g.vertices->getId(i);
    }

    bubbleSort(cor, g.size());

    for (int i = 0; i < g.QuantidadeVertices(); i++) {
      g.ImprimeVizinhos(cor[i][0]);
    }
    cout << "";

  } else if (function == "-k") {
    cout << (g.QuantidadeArestas() == (g.QuantidadeVertices() * (g.QuantidadeVertices() - 1)) / 2) << endl;
  }
  cout << " fim ";
  return 0;
}

void createGraph(Grafo* g) {
  int n;
  string nn;

  getline(cin, nn);
  n = stoi(nn);

  g->allocate(n);

  for (int i = 0; i < n; i++) {
    g->InsereVertice(i);
  }

  // for pra criar as arestas de cada veŕtice.
  for (int j = 0; j < n; j++) {
    string v;
    getline(cin, v);  // pega a string inteira até a quebra de linha.

    stringstream stream(v);  // cria um stream de string.
    string word;             // a string que comportará a string  do get line picotada - uma palavra por vez

    int i = 0;
    while (getline(stream, word, ' ')) {
      if (i > 0) {  // pula a primeira entrada da linha (pois essa é a entrada do número de vizinhos)
        g->InsereAresta(j, stoi(word));
      }
      i++;
    }
  }

  string colours;
  getline(cin, colours);  // pega a string de colorações inteira até a quebra de linha.

  stringstream stream(colours);  // cria um stream de string.
  string word;                   // a string que comportará a string  do get line picotada - uma palavra por vez

  int i = 0;                            // índice para indereçar a cor i ao vértice i
  while (getline(stream, word, ' ')) {  // quebra a string de colorações "colours" em palavras
    g->vertices->setColour(i, stoi(word));
    i++;
  }
}

// testa as implementações das listas
int checkLists() {
  List l;
  cout << "size inicial = " << l.size() << endl;
  for (int i = 0; i < 13; i++) {
    l.insert(i);
  }

  cout << "size = " << l.size() << endl;
  cout << endl;
  l.print();
  cout << endl;

  l.removeLast();
  cout << "size = " << l.size() << endl;
  cout << endl;
  l.print();

  cout << endl;

  cout << "get(6) = " << l.get(6) << endl;

  l.~List();
  l.insert(-400);
  cout << l.get(0) << endl;

  cout << "---------------------------------------" << endl;
  cout << endl;

  AdjList adj;
  adj.insert(6);
  adj.update(1, 4);
  adj.update(4, 0);
  adj.update(5, 1);
  adj.update(4, 3);

  for (int i = 0; i < adj.size(); i++) {
    cout << i << ": ";
    adj.get(i)->print();
    cout << endl;
  }
  adj.~AdjList();
  return 0;
}

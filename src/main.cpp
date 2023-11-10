#include <iostream>
#include <sstream>
#include <string>

#include "graph.hpp"
#include "muita_Sort.hpp"

using namespace std;

// cria o grafo g a partir da entrada padrão.
int createGraph(Grafo* g);

int main() {
  Grafo g;
  int n;   // receberá o número de vértices no grafo
  char sort;  // receberá o identificador de ordenador
  string header;
  getline(cin, header);  // pega a string inteira até a quebra de linha.

  stringstream headStream(header);  // cria um stream de string.
  string w;                         // a string que comportará a string  do get line picotada - uma palavra por vez

  int k = 0;
  while (getline(headStream, w, ' ')) {
    if (k == 0) sort = w[0];
    if (k == 1) n = stoi(w);
    k++;
  }
  
  g.allocate(n);

  for (int i = 0; i < n; i++) {
    g.InsereVertice(i);
  }

  int maxColour = createGraph(&g);

  // Cria matriz de id por coloração para ordenação indireta dos vértices
  int cor[g.QuantidadeVertices()][2];

  // atribui cada id e coloração dos vértices a uma entrada do array/matriz "cor" a ser ordenado
  for (int i = 0; i < g.size(); i++) {
    cor[i][1] = g.vertices->getColour(i);
    cor[i][0] = g.vertices->getId(i);
  }
  //  0 4 5 1 3 2

  switch (sort) {
    case 'b':
      bubbleSort(cor, g.QuantidadeVertices());
      break;
    case 's':
      selectionSort(cor, g.QuantidadeVertices());
      break;
    case 'i':
      insertionSort(cor, g.QuantidadeVertices());
      break;
    case 'm':
      mergeSort(cor, 0, g.QuantidadeVertices()-1);
      break;
    case 'q':
      quickSort(cor, 0, g.QuantidadeVertices()-1);
      break;
    case 'p':
      heapSort(cor, g.QuantidadeVertices());
      break;

    default:
      heapSort(cor, g.QuantidadeVertices());
      break;
  }
 
  bool greedy = g.CheckGreedy(cor);
  cout << greedy;
  if (greedy) {
    cout << " ";
    for (int j = 0; j < g.QuantidadeVertices(); j++) {
      cout << cor[j][0] << " ";
    }
  }
  cout << endl;

  return 0;
}

int createGraph(Grafo* g) {
  

  // for pra criar as arestas de cada veŕtice.
  for (int j = 0; j < g->QuantidadeVertices(); j++) {
    string v;
    getline(cin, v);  // pega a string inteira até a quebra de linha.

    stringstream stream(v);  // cria um stream de string.
    string word;             // a string que comportará a string  do get line picotada - uma palavra por vez

    int i = 0;
    while (getline(stream, word, ' ')) {
      if (i > 0) {  // pula a primeira entrada da linha (pois essa é a entrada do número de vizinhos)
        g->InsereAresta(j, stoi(word));
      } else {
        g->vertices->get(i)->reallocate(stoi(word));
      }
      i++;
    }
  }

  string colours;
  getline(cin, colours);  // pega a string de colorações inteira até a quebra de linha.

  stringstream stream(colours);  // cria um stream de string.
  string word;                   // a string que comportará a string  do get line picotada - uma palavra por vez

  int maxColour = 0; // armazena a maior cor presente no grafo (para retornar na fuanção).

  int i = 0;                                    // índice para indereçar a cor i ao vértice i
  while (getline(stream, word, ' ')) {          // quebra a string de colorações "colours" em palavras
    int colour = stoi(word) - 1;
    g->vertices->setColour(i,colour );  // colore o vértice com a cor da entrada com offset de -1 (uma vez que a entrada inicia na cor 1)
    maxColour = (colour > maxColour) ? colour : maxColour; // Testa e atualiza maxColour
    i++;
  }
  return maxColour;
  
}

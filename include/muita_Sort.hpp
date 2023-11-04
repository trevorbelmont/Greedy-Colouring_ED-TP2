#ifndef MUITA_SORT_HPP
#define MUITA_SORT_HPP

// Método que troca elementos de lugar. Só pra facilitar leitura.
void swap(int a[2], int b[2]) {
  int aux0 = a[0];
  int aux1 = a[1];
  a[0] = b[0];
  a[1] = b[1];
  b[0] = aux0;
  b[1] = aux1;
}

// Ordena as linhas da matriz de duas colunas por bubbleSort tomando a segunda entrada (coluna) por parâmetro
void bubbleSort(int v[][2], int rows) {
  // Passa por todas as entradas do array (menos a última) para comparar com a próxima
  for (int i = 0; i < rows - 1; i++) {
    // Neste loop o maior número é "bubbled" para a posição mais a direita que ainda não foi organizada
    for (int j = 0; j < rows - i - 1; j++) {
      if (v[j][1] > v[j + 1][1]) {  // Troca os subarrays apenas se a segunda entrada for maior
        swap(v[j], v[j + 1]);
      }
    }
  }
}

// Ordena via Insertion Sort as linhas da matriz de duas colunas tomando a segunda entrada (coluna) por parâmetro
void insertionSort(int v[][2], int rows) {
  // Loop que passa por todas as entradas
  for (int i = 0; i < rows; i++) {
    int j = i;
    // Checa as entradas anteriores a atual, i.
    while (j > 0 && v[j][1] < v[j - 1][1]) {  // Enquanto a entrada atual for menor que a anterior, troca as duas
      swap(v[j], v[j - 1]);
      j--;
    }
  }
}

// Ordena via Selection Sort as linhas da matriz de duas colunas tomando a segunda entrada (coluna) por parâmetro
void selectionSort(int v[][2], int rows) {
  // Loop que passa pela partição não ordenada, pegando inicialmente a primeira entrada por mínimo
  for (int i = 0; i < rows - 1; i++) {
    int min = i;
    // percorre a partição não ordenada selecionando o menor elemento
    for (int j = i + 1; j < rows; j++) {
      if (v[j][1] < v[min][1]) {  // Atualiza o menor elemento, se necessário
        min = j;
      } else if (v[j][1] == v[min][1]) {
        min = (v[min][0] < v[j][0]) ? min : j;
      }
      // ao fim do loop, se o menor elemento não era o primeiro da partição não ordenada, troca os dois
      if (min != i) {
        swap(v[i], v[min]);
      }
    }
  }
}
#endif
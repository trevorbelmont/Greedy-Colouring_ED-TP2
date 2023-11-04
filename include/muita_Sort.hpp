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
        min = (v[j][0] < v[min][0]) ? j : min;
      }
    }
    // ao fim do loop interno, se o menor elemento não era o primeiro da partição não ordenada, troca os dois
    if (min != i) {
      swap(v[i], v[min]);
    }
  }
}

// MERGE SORT
// Faz a junção de dois arrays (virtuais) ordenando-os e devolvendo ao array original
void merge(int v[][2], int left, int middle, int right) {
  int n1 = middle - left + 1;  // tamanho do array temporário da esquerda
  int n2 = right - middle;     // tamanho do array temporário da direita

  // Cria subarrays temporários
  int leftArray[n1][2];
  int rightArray[n2][2];

  // Copia os dados para os subarrays temporários leftArray e rightArray
  for (int i = 0; i < n1; i++) {
    leftArray[i][0] = v[left + i][0];
    leftArray[i][1] = v[left + i][1];
  }
  for (int i = 0; i < n2; i++) {
    rightArray[i][0] = v[middle + 1 + i][0];
    rightArray[i][1] = v[middle + 1 + i][1];
  }

  int i = 0;     // índíce do array temporaŕio da esquerda
  int j = 0;     // índice do array temporário da direita
  int k = left;  // índice do array efetivo original

  // Mescla os subarrays de volta no array original
  while (i < n1 && j < n2) {
    if (leftArray[i][1] <= rightArray[j][1]) {
      v[k][0] = leftArray[i][0];
      v[k][1] = leftArray[i][1];
      i++;
    } else {
      v[k][0] = rightArray[j][0];
      v[k][1] = rightArray[j][1];
      j++;
    }
    k++;
  }

  // Copia os elementos restantes, se houver
  while (i < n1) {
    v[k][0] = leftArray[i][0];
    v[k][1] = leftArray[i][1];
    i++;
    k++;
  }
  while (j < n2) {
    v[k][0] = rightArray[j][0];
    v[k][1] = rightArray[j][1];
    j++;
    k++;
  }
}
// Parte recursiva da ordenação via Merge Sort das linhas matriz de duas colunas basead0-se na segunda coluna
void mergeSort(int v[][2], int begin, int end) {
  end -= 1;
  // Condição de parada da recursão.
  if (begin < end) {  // Garante que o array a ser ordenado tenha tamanho mínimo >=2

    int middle = begin + (end - begin) / 2;  // divisão inteira
    mergeSort(v, begin, middle);
    mergeSort(v, middle + 1, end);
    merge(v, begin, middle, end);
  }
}

// QUICK SORT
//  Função para particionar o array usando a última entrada (coluna) como pivô
int partition(int arr[][2], int low, int high) {
  int pivot = arr[high][1];  // Escolhe o pivô como a última entrada da coluna
  int i = low - 1;           // Índice do menor elemento

  // percorrer a partição coloando as entradas do vetor no lado certo em relação ao pivot
  for (int j = low; j < high; j++) {
    // Se a seguda coluna é menor que o pivot ou se é igual mas a primeira coluna é menor
    if (arr[j][1] < pivot || (arr[j][1] == pivot && arr[j][0] < arr[high][0])) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  // Troca o pivô com o elemento na posição correta
  swap(arr[i + 1], arr[high]);

  return i + 1;  // Retorna a posição do pivô após a partição
}

// Parte recursiva do do Quick Sort
void quickSort(int arr[][2], int low, int high) {
  high -= 1;

  // Condição de parada
  if (low < high) {  // Garante que o subarray a ser particionado tenha tamanho mínimo >= 2;
    // Encontra a posição do pivô após a partição
    int pi = partition(arr, low, high);

    // Chama recursivamente quickSort para as duas metades
    quickSort(arr, low, pi - 1);   // Subarray esquerdo
    quickSort(arr, pi + 1, high);  // Subarray direito
  }
}

// HEAP SORT (heap mínimo)
// Função para ajustar o heap máximo (inversão das condições)
void heapify(int arr[][2], int col, int root, int n) {
  int largest = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;

  // Verifica se a segunda entrada do filho esquerdo é maior que a do pai - ou ambas são iguais mas primeira entrada do filho esquerdo é maior
  if (left < n && (arr[left][1] > arr[largest][1] || (arr[left][1] == arr[largest][1] && arr[left][0] > arr[largest][0]))) {
    largest = left;
  }

  // Verifica se a segunda entrada do filho direito é maior que a maior dos dois (filho esquerdo e pai) - ou se é igual à maior dos dois, porém tem primeira entrada maior.
  if (right < n && (arr[right][1] > arr[largest][1] || (arr[right][1] == arr[largest][1] && arr[right][0] > arr[largest][0]))) {
    largest = right;
  }
  // Se o maior não for o pai, troca os elementos e continua o ajuste
  if (largest != root) {
    swap(arr[root], arr[largest]);  // Troca os elementos usando a função swap
    heapify(arr, col, largest, n);
  }
}

// Função principal do Heap Sort
void heapSort(int arr[][2], int col) {
  int n = col;

  // Constrói o heap máximo
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, col, i, n);
  }

  // Extrai os elementos do heap um por um e os coloca em ordem crescente
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    // Chama heapify na raiz reduzida
    heapify(arr, col, 0, i);
  }
}

#endif
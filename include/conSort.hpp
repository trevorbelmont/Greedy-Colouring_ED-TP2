#ifndef MUITA_SORT_HPP
#define MUITA_SORT_HPP

#include "lista_adjacencia.hpp"

// Método que troca elementos de lugar. Utilizado por quase todas as ordenções presentes neste header.
void swap(int a[2], int b[2]);

// Ordena as linhas da matriz de duas colunas por bubbleSort tomando a segunda entrada (coluna) por parâmetro
void bubbleSort(int v[][2], int rows);

// Ordena via Insertion Sort as linhas da matriz de duas colunas tomando a segunda entrada (coluna) por parâmetro
void insertionSort(int v[][2], int rows);

// Ordena via Selection Sort as linhas da matriz de duas colunas tomando a segunda entrada (coluna) por parâmetro
void selectionSort(int v[][2], int rows);

// MERGE SORT
// Faz a junção de dois arrays (virtuais) ordenando-os e devolvendo ao array original
void merge(int v[][2], int left, int middle, int right);

// Parte recursiva da ordenação via Merge Sort das linhas matriz de duas colunas basead0-se na segunda coluna
void mergeSort(int v[][2], int begin, int end);

// QUICK SORT
//  Função para particionar o array usando a última entrada (coluna) como pivô
int partition(int arr[][2], int low, int high);

// Parte recursiva do do Quick Sort
void quickSort(int arr[][2], int low, int high);

// HEAP SORT (heap mínimo)
// Função para ajustar o heap máximo (inversão das condições)
void heapify(int arr[][2], int nRows, int root);

// Função principal do Heap Sort
void heapSort(int arr[][2], int nRows);

// Adaptação de Counting Sort
int countingSort(int arr[][2], int nRows, int nColours);

#endif

#ifndef MUITA_SORT_HPP
#define MUITA_SORT_HPP

void bubbleSort(int v[][2], int col) {
  for (int i = 0; i < col - 1; i++) {
    for (int j = 0; j < col - i - 1; j++) {
      if (v[j][1] > v[j + 1][1]) {
        // Troca os subarrays se a segunda entrada for maior
        int temp0 = v[j][0];
        int temp1 = v[j][1];
        v[j][0] = v[j + 1][0];
        v[j][1] = v[j + 1][1];
        v[j + 1][0] = temp0;
        v[j + 1][1] = temp1;
      }
    }
  }
}

#endif
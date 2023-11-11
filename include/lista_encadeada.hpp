#ifndef LIST_HPP
#define LIST_HPP

class List {
 public:
  // cria lista sem alocar memória
  List();
  // cria lista dinâmicamente alocada de tamanho n
  List(int n);
  // desaloca memória
  ~List();

  // Aloca memória. Se a lista estiver preenchida, faz back up e realloca.
  void reallocate(int n);
  int size();
  // Sempre insere no final (desde que haja espaço).
  void insert(int n);
  int get(int i);
  void print();
  bool empty();
  // Remove (torna inacessível) a última entrada da lista sem retornar seu valor.
  void removeLast();

 private:
  int size_;
  int maxSize_;
  int* keys_;
};

#endif

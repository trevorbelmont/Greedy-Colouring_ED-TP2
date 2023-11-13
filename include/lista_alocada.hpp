#ifndef LIST_HPP
#define LIST_HPP

class List {
 public:
  // Instancia lista sem alocar memória.
  List();
  // Cria lista dinâmicamente alocada de tamanho n.
  List(int n);
  // Libera memória.
  ~List();

  // Força a atualização de uma posição alocada na lista, atualizando se necessário o tamanho da lista.
  // Retorna false se o índice for inválido ou se não houve alteração de dados previamente definidos.
  bool forceSet(int index, int value);

  // Atualiza uma posição na lista apenas se ela já estiver sido inicializada (index < size_).
  // Retorna um float com o do valor inteiro antigo armazenado ou -404.00404, caso falhar.
  bool update(int index, int value);

  // Aloca memória. Se a lista estiver preenchida, faz back up e realloca.
  void reallocate(int n);
  // Retorna o tamanho da lista.
  int size();
  // Insere elemento (sempre no final) desde que haja espaço.
  bool insert(int key);


  // Insere n inteiros na lista inicializando-os com o valor "constantValue". Retorna o número de inteiros inseridos.
  // Obs: Quando "constantValeu" é omitido na chamada da função, todos os inteiros são inseridos com o valor padrão, zero.
  int multInsert(int n, int constantValue);

  // Retona o inteiro na posição i;
  int get(int i);

  // Lista todos os elementos da lista - em uma linha.
  void print();

  // Checa vacuidade.
  bool empty();
  // Remove (torna inacessível) a última entrada da lista sem retornar seu valor.
  void removeLast();

 private:
  // Desloca a partição designada pelo intervalo fechado [id0,list.size()] em "offset" casas/índices no array.
  // Não altera o array e false se não for possível deslocar todos os índices da partição.
  bool arreda(int id0, int offset);
  int size_;     // Tamanho atual da lista.
  int maxSize_;  // Tamanho máximo da lista.
  int* keys_;    //  Ponteiro que armazena o array de inteiros dinamicamente alocado.
};

#endif

#ifndef LIST_HPP
#define LIST_HPP

struct Node {
  int key;
  Node* next = nullptr;
  Node* prev = nullptr;
};

class List {
 public:
  List();
  ~List();

  int size();
  void insert(int n);
  int get(int i);
  void print();
  bool empty();
  void removeLast();

 private:
  int size_;
  Node* first_;
  Node* last_;
};

#endif

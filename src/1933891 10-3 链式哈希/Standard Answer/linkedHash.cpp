#include <iostream>

struct Node {
  int number;
  Node* next; 
  Node(int num = 0, Node* ptr = NULL) : number(num), next(ptr) {} 
};

int main() {
  int n;
  std::cin >> n;
  while (n) {
    Node *hash_ptr[13];
    for (int i = 0; i < 13; i++) {
      hash_ptr[i] = NULL;
    }
    int* num;
    num = new int[n];
    for (int i = 0; i < n; i++) {
      std::cin >> num[i];
    }
    Node* ptr = NULL, *ptr_get = NULL;
    for (int i = 0; i < n; i++) {
      int m = 0;
      m = num[i] % 13;
      ptr = new Node;
      ptr->number = num[i];
      if (hash_ptr[m] == NULL) {
        hash_ptr[m] = ptr;
      } else {
        ptr_get = hash_ptr[m];
        while (ptr_get->next != NULL) {
        ptr_get = ptr_get->next;
      }
      ptr_get->next = ptr;
      }
    }
    for (int i = 0; i < 13; i++){
      std::cout << i << "#";
      if (hash_ptr[i] == NULL) {
        std::cout << "NULL\n";
      } else {
        int flag = 0;
        ptr = hash_ptr[i];
        while (ptr != NULL) {
          if (flag == 0) {
            flag = 1;
          } else {
            std::cout << " ";
          }
          std::cout << ptr->number;
          ptr = ptr->next;
        }
        std::cout << "\n";
      }
    }
    for (int i = 0; i < 13; i++) {
      ptr = hash_ptr[i];
      while (ptr != NULL){
        Node* pre = ptr;
        ptr = ptr->next;
        delete pre;
      }
    }
    std::cin >> n;
  }
  return false;
}                                 
#include <iostream>
#define ignore_TEST
#include "linked_list.hpp"
using namespace std;

class Queue {
  LinkedList l;

  /* back/rear(enque) [1,2,3] front(deque) */
  /* enque:4 [4,1,2,3] */
  /* [4,1,2] dequeu:3 */
  /* FILO */

public:
  int size() { return l.size(); }
  bool is_empty() { return l.is_empty(); }

  void enque(int elem) {
    l.insert_at_tail(elem);
  }

  int deque() {
    return l.remove_at_head();
  }

  int front() {
    return l.get_head();
  }
};


int test() {

  Queue q1;

  q1.enque(1);
  q1.enque(2);
  q1.enque(3);
  q1.enque(4);
  q1.enque(5);
  q1.enque(6);

  while (!q1.is_empty()) {
    int elem = q1.deque();
    cout << elem << endl;
  }

  return 0;
}

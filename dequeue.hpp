#include <iostream>

using namespace std;

/*
ABBR
// title
# subtitle
-> definition
- subtopics
: subtree
-x- end of topic with 1 line gap
=> meaning
*notes

-x-

Queue
FIFO -> FIRST IN FIRST OUT
  front:remove [4,6,8,5] insert:back/rear
   insert and remove at opposite ends

  enque-> insert at rear/back
  deque -> remove at front
  size
  isEmpty
  isFilled
  front -> peek

 */

class Dequeue {
public:
  static const int CAPACITY = 100;
  int array[CAPACITY];
  int elem_count = 0;

  int size() { return elem_count; }

  bool isEmpty() { return elem_count == 0; }

  bool isFilled() { return elem_count == CAPACITY; }

  int front(int *elem) {
    if (isEmpty()) {
      return -1;
    }
    *elem = array[0];
    return 0;
  }

  int back(int *elem) // peek from back side
  {
    if (isEmpty()) {
      return -1;
    }

    *elem = array[elem_count - 1];

    return 0;
  }

  int enque_back(int elem) {
    if (isFilled()) {
      return -1;
    }

    array[elem_count] = elem;
    elem_count += 1;

    return 0;
  }

  int enque_front(int elem) {
    if (isFilled()) {
      return -1;
    }

    for (int i = elem_count; i > 0; i--) {
      array[i] = array[i - 1];
    }

    array[0] = elem;
    elem_count -= 1;

    return 0;
  }

  int deque_front(int *front_elem) {
    if (isEmpty()) {
      return -1;
    }

    // *front_elem = array[0];
    front(front_elem);

    for (int i = 0; i < elem_count - 1; i++) {
      array[i] = array[i + 1];
    }
    elem_count -= 1;

    return 0;
  }

  int deque_back(int *back_elem) // remove from back
  {
    if (isEmpty()) {
      return -1;
    }

    back(back_elem);
    elem_count--;

    return 0;
  }
};

void test() {

  Dequeue d;

  d.enque_back(10);
  d.enque_back(20);
  d.enque_front(30);
  d.enque_front(40);

  while (!d.isEmpty()) {
    int elem;
    d.deque_back(&elem);
    cout << elem << endl;
  }
}

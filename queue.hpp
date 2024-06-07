// header file
// pragma once /* advanced */

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

class Queue {
public:
  static const int CAPACITY = 100;
  int array[CAPACITY];
  int elem_count = 0;

  int size() { return elem_count; }

  bool is_empty() { return elem_count == 0; }

  bool is_filled() { return elem_count == CAPACITY; }

  int front(int *elem) { /* front:1 -> [1,2,3] */
    if (is_empty()) {
      return -1;
    }
    *elem = array[0];
    return 0;
  }

  int enque(int elem) { /* [1,2,3] */
    if (is_filled()) {
      return -1;
    }
/* elem_count */
    array[elem_count] = elem; /* [1,2,3,4] enque:4 */
    elem_count += 1;

    return 0;
  }

  int deque(int *front_elem) {
    if (is_empty()) {
      cout << "queue empty" << endl;
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
};

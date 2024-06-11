// header file
// pragma once /* advanced */

#pragma once

#include <iostream>

using namespace std;

/*
ABBR
title
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
  static const int CAPACITY = 100;
  int array[CAPACITY];
  int elem_count = 0;

public:
  int size() { return elem_count; }
  bool is_empty() { return elem_count == 0; }
  bool is_filled() { return elem_count == CAPACITY; }

  /* bound checking imp */
  int front(int* elem) {  // front:1 -> [1,2,3]
    if (is_empty()) {
      return -1;
    }
    /* todo why not &array[0] */
    *elem = array[0];
    return 0;
  }

  int enque(int elem) { /* [1,2,3] */
    if (is_filled())
    {
      return -1;
    }
    /* elem_count */

    array[elem_count] = elem; /* [1,2,3,4] enque:4 */
    elem_count += 1;

    return 0;
  }

  int deque(int* front_elem) {
    if (is_empty())
    {
      return -1;
    }

    // *front_elem = array[0];
    front(front_elem);
    /* [1,2,3,4] elem_count:4 */
    /* [0 1 2 3] index */

    /* [2,3,4] elem_count:3 */
    /* [0 1 2]  index */

    elem_count -= 1;
    for (int i = 0; i < elem_count; i++) {
      array[i] = array[i + 1];
    }

    return 0;
  }
};

int test() {
  // solved: resolve segmentation fault
  Queue q;
  q.enque(3);
  q.enque(4);
  cout << q.is_empty() << endl;
  cout << q.is_filled() << endl;
  cout << q.size() << endl;

  while (!q.is_empty()) {
    // int* p; /* reseaon for segmentation fault */
    int a;
    q.deque(&a);
    cout << a;
  }
  return 0;
};
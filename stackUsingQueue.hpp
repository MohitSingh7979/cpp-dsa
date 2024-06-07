#pragma once
/* import system installed header file using < > */
#include "queue.hpp" /* import local file using "" */
using namespace std;
/* absolutes path not included in local file*/
/* use -I for dirtory in console */
/* imported file must not have main function */

/*
  operations:
   push
   pop
   is_empty
   is_filled
   size
   peek
*/

class Stack {

  static const int CAPACITY = 100;
  int array[CAPACITY];

  Queue queue;

public:
  int is_empty() { return queue.is_empty(); }
  int is_filled() { return queue.is_filled(); }
  int size() { return queue.size(); }

  /* stack => [1,2,3,4] -> top:4 */
  int top() {
    while (!is_empty()) {

    }
    return 0;
  }
  int push(int elem) { return queue.enque(elem); }

  // int pop() {}
};

void test() {
  Stack s;
  cout << s.is_empty();
  cout << s.is_filled();
  cout << s.size();

}

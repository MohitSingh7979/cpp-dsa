
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
// ADT (Abstract Data Type)
  array -> static homogenous collection
  homogenous => same data type
 -x-

// stack
  * follows FILO operation
    FILO => first in last out

  implementation:
    # array -> static
    # linked_list -> dynamic

  - push -> insert
  - pop -> delete
  - peek -> top elem
  - size -> length
  - isEmpty -> total elem = 0
  - isFull -> space remaining = 0
-x-

// SHORT-FORMS
  arr = array
  elem = element

 */

#pragma once

#include <iostream>

using namespace std;
/* namespace => use to avoid std in cout */

class Stack
{
public:
  static const int CAPACITY = 100; /* # of elem can be stored */
  int array[Stack::CAPACITY];      /* where elem will be stored */
  int elems_count = 0;             /* count of elem in arr */

  /* Stack(){}; */
  int size() { return elems_count; }

  bool is_empty() { return elems_count == 0; }

  bool is_filled() { return elems_count == Stack::CAPACITY; }

  // to insert element to the top
  int push(int elem)
  {
    if (is_filled())
    {
      cout << "overflow stack";
      return -1;
    }

    int next_to_last = elems_count;

    array[next_to_last] = elem;
    elems_count += 1;

    return 0;
  }

  int pop(int* removed_elem)
  { // to remove item from top
    if (is_empty())
    {
      cout << "underflow stack";
      return -1;
    }

    /* peek(removed_elem); */
    *removed_elem = array[elems_count - 1];

    array[elems_count] = 0; // optional
    elems_count -= 1;
    return 0;
  }

  int peek(int* top_elem)
  { /* to retrieve top elem */
    /* return array[elems_count - 1]; */
    if (is_empty())
    {
      return -1;
    }
    *top_elem = array[elems_count - 1];
    /*
      * -> to dereference
        dereference => to retrieve the value from address
      & -> to specify address
    */
    return 0;
  }
};

void test()
{
  Stack s;

  s.push(34);
  s.push(341);
  s.push(343);
  s.push(344);
  s.push(3234);
  s.push(354);

  while (!s.is_empty())
  {
    int elem;
    s.pop(&elem);
    cout << elem << endl;
  }
}

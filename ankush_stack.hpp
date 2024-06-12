#pragma once
class Stack
{
  static const int CAPACITY = 1000;
  int array[CAPACITY];
  int elems_count = 0;

public:
  int size() { return elems_count; }

  bool is_empty() { return elems_count == 0; }

  bool is_filled() { return elems_count == CAPACITY; }

  void push(int elem)
  {
    int next_to_top = elems_count;
    array[next_to_top] = elem;
    elems_count++;

  }

  int pop()
  {

    int last = peek();
    elems_count--;
    array[elems_count] = 0;

    return last;
  }

  int peek()
  {
    return array[elems_count - 1];
  }
};
#pragma once
#include <iostream>
using namespace std;

// todo insert at any point / ARBITRARY POINT / index
// todo remove at any point / ARBITRARY POINT / index

/*
 * LinkedList
 * dynamic sizing
 *
 * insert
 *  begin
 *  end
 *  (advance) at any point
 *
 *
 * remove
 *  begin
 *  end
 *  (advance) at any point
 *
 * size
 *
 * search/find
 * traverse
 * is_empty (header = NULL)
 *
 *
 * header (pointer of first node)
 *
 *
 * Node
 *  data
 *  address (next or NULL)
 *
 *
 * */


struct Node {
  int data;
  Node* next = nullptr;
};

class LinkedList {
  Node* head = nullptr; // first item
  Node* tail = nullptr; // last item
  int item_count = 0;

public:
  int get_head() {
    return head->data;
  }
  int get_tail() {
    return tail->data;
  }

  int size() { return item_count; }

  bool is_empty() { return head == nullptr; }

  void insert_at_head(int val) { // insert
    head = new Node{ val, head };/* must */
    if (tail == nullptr) {
      tail = head;
    }
    /*Node node;*/
    /*node.data = val;*/

    /*Node *node = new Node{val, head};*/
    /*head = node; // assigning new_node to head*/
    item_count++;
  }

  int remove_at_head() {
    Node* tmp = head;
    head = head->next;
    item_count--;
    int val = tmp->data;
    delete tmp; // freeing memory
    return val;
  }

  void insert_at_tail(int val) {
    if (tail == nullptr) {
      insert_at_head(val);
      return;
    }

    Node* node = new Node{ val, nullptr };
    tail->next = node;
    tail = node;

    item_count++;
  }

  int remove_at_tail() {
    if (head->next == nullptr) {
      int val = remove_at_head();
      tail = nullptr;
      return val;
    }

    Node* tmp = head;

    /* ignore bcoz of O(n) loop */
    while (tmp->next->next != nullptr) {
      tmp = tmp->next;
    }
    int val = tmp->next->data;
    delete tmp->next; // freeing memory
    tail = tmp;
    item_count--;
    return val;
  }

  void traverse() {
    Node* tmp = head;
    while (tmp != nullptr) {
      cout << tmp->data << "->";
      tmp = tmp->next;
    }
    cout << "nullptr\n";
  }
};

#ifndef ignore_TEST

void test() {
  LinkedList l1;
  l1.insert_at_head(5);
  l1.insert_at_tail(9);
  l1.insert_at_head(3);
  l1.remove_at_head();
  l1.insert_at_head(2);
  l1.remove_at_tail();
  l1.insert_at_tail(6);

  l1.traverse();
}

#endif
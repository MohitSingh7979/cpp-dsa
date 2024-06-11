/*
  is_empty
  size

  get_head
  get_tail

  insert_at_head
  insert_at_tail

  remove_at_head
  remove_at_tail

  traverse

  head // reference of entry point i.e. first node
    |> Node:
    wrapper{
      <- previous node pointer
      - data
      -> next node pointer
    }

 */

#include <iostream>
using namespace std;

struct Node
{
  Node *pre_node;
  int data;
  Node *next_node;
};

class Doubly_ll
{
  int item_count = 0;

public:
  Node *head = nullptr;
  Node *tail = nullptr;

  bool is_empty()
  {
    return head == nullptr;
  }
  int size()
  {
    return item_count;
  }

  int get_head()
  {
    return head->data;
  }
  int get_tail()
  {
    return tail->data;
  }

  void insert_at_head(int elem)
  {
    if (head == nullptr && tail == nullptr)
    {
      tail = head = new Node{nullptr, elem, head};
    }
    else
    {

      head->pre_node = new Node{nullptr, elem, head};
      ;
      head = head->pre_node;

      /*
      Node* old_head = head;
      head = new Node{ nullptr,elem,old_head};
      old_head->pre_node = head;
       */
    }
    /*
    {n<-5<-4->3->n},h={n,4,{n,3,n}},t={n,3,n}
    {n,5,{n,4,{n,3,n}}}*/

    /* {n,3,n} h={n,3,n} t= {n,3,n}
        {n,4,{{n,4,{recursion,3,n}},3,n}}
     */

     /* {n,3,n} h={r=3,3,n} t={r=3,3,n}
         {r=3,3,}
        4: {n,4,{r=3,3,n}}
      */
  }

  // todo
  int remove_at_head() {}

  // todo
  void insert_at_tail() {}

  // todo
  void remove_at_tail() {}
};

void test() {
  Doubly_ll dll;

  dll.insert_at_head(3);
  dll.insert_at_head(4);

  cout << dll.head->data << endl;//4
  cout << dll.head->next_node->data << endl;//3
  cout << dll.head->next_node->pre_node->data << endl;//4

  cout << dll.head << endl;
  cout << dll.tail << endl;

}
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
  Node *head = nullptr;
  Node *tail = nullptr;
  int item_count = 0;

public:
  
  bool is_empty() {
    // todo changed back
    return head == nullptr && tail == nullptr;
  }
  int size() { return item_count; }

  int get_head() { return head->data; }
  int get_tail() { return tail->data; }

  void insert_at_head(int elem) {
    if (is_empty()) {
      tail = head = new Node{nullptr, elem, nullptr/* why head, not nullpointer */};
      item_count += 1;
    }
    else {
      head->pre_node = new Node{nullptr, elem, head};
      head = head->pre_node;
      item_count += 1;

      /* // optional verbose
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

  void remove_at_head() {
    if (!is_empty()){
      head = head->next_node;
      head->pre_node = nullptr;
      item_count -= 1;
    };
    /*
    {n,3,{r=3,2,n}}, h={n,3,{r=3,2,n}} t={{n,3,r=2},2,n}
    {n,3,n}
    */
  };

  void insert_at_tail(int elem) {
    if (is_empty()){
      insert_at_head(elem);

    }
    else{
      tail = tail->pre_node = new Node{tail, elem, nullptr};
      item_count += 1;
    }
  }

  // 
  void remove_at_tail() {
    if (!is_empty()){
      tail = tail->pre_node;
      tail->next_node = nullptr;
      item_count -= 1;
    };
  }
};


void test() {
  Doubly_ll dll;
  /*
    dll.insert_at_head(3);
    dll.insert_at_head(4);

    cout << dll.head->data << endl;//4
    cout << dll.head->next_node->data << endl;//3
    cout << dll.head->next_node->pre_node->data << endl;//4

    cout << dll.head << endl;
    cout << dll.tail << endl;
  */
  /*
    dll.insert_at_head(3);
    dll.insert_at_head(4);
    dll.remove_at_head();
    cout << dll.head->data << endl;//3
  */
  /*
  dll.insert_at_tail(3);
  cout << dll.get_head() << endl;
  cout << dll.get_tail() << "\n\n";

  dll.insert_at_tail(4);
  cout << dll.get_tail() << endl;

  dll.insert_at_tail(5);
  cout << dll.get_tail() << endl;
  */
  // /*
  // todo fix this
  dll.insert_at_tail(3);
  dll.insert_at_tail(4);
  dll.insert_at_tail(5);
  dll.insert_at_tail(6);

  cout << dll.get_head() << endl;
  cout << dll.get_tail() << "\n\n";
  dll.remove_at_tail();

  cout << dll.get_tail() << endl;
  dll.remove_at_tail();

  cout << dll.get_tail() << endl;
  dll.remove_at_tail();

  cout << dll.get_tail() << endl;
  cout << dll.get_tail() << endl;

  // while (!is_empty()) {
  // }

  // */

}
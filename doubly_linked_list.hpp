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
#include<sstream>
#include <assert.h>
using namespace std;
#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

struct Node {
  Node *pre_node;
  int data;
  Node *next_node;
};

class Doubly_ll {
  int item_count = 0;

public:
  Node *head = nullptr;
  Node *tail = nullptr;

  bool is_empty() {
    // todo changed back optional
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

  void remove_at_tail() {
    if (!is_empty()){
      tail = tail->pre_node;
      tail->next_node = nullptr;
      item_count -= 1;
    };
  }

  // todo traverse
};

void assert_linked_list(Doubly_ll *dll, int *expected_arr, int expected_length){
  Node *temp = dll->head;
  int i = 0;
  while (temp != nullptr){
    int output = temp->data;
    int expected = expected_arr[i++];

    ASSERT(output == expected, "expected:" << expected << "\toutput:" << output);
    temp = temp->next_node;
  }
  
  ASSERT(i == expected_length, "elem count mismatch");
}


void test_insert_at_head(){
  Doubly_ll dll;

  dll.insert_at_head(3);
  dll.insert_at_head(4);
  dll.remove_at_head();


  int *expected = new int[1]{3};
  assert_linked_list(&dll, expected, 1);

  cout << "successful insert at head\n";
}

void test_remove_at_head(){
  Doubly_ll dll;
  int expected[] = {1, 4, 1};
  int output[3] = {};

  dll.insert_at_head(1);
  output[0] = dll.get_head();

  dll.insert_at_head(4);
  output[1] = dll.get_head();

  dll.remove_at_head();
  output[2] = dll.get_head();


  /*
  for (int i = 0;i < 5;i++){
    output[i] = dll.get_head();
  }
   */

  for (int i = 0;i < 3;i++){
    ASSERT(output[i] == expected[i], "\texpected:" << expected[i] << " output:" << output[i]);
  }
  cout << "successful remove at head\n";

}

void test_insert_at_tail(){
  Doubly_ll dll;

  int expected[] = {3, 4, 5, 6, 7};
  int output[5] = {};

  dll.insert_at_tail(3);
  output[0] = dll.get_tail();
  dll.insert_at_tail(4);
  output[1] = dll.get_tail();
  dll.insert_at_tail(5);
  output[2] = dll.get_tail();
  dll.insert_at_tail(6);
  output[3] = dll.get_tail();
  dll.insert_at_tail(7);
  output[4] = dll.get_tail();

  /* for (int i = 0;i < 5;i++){
    output[i] = dll.get_tail();
  } */

  for (int i = 0;i < 5;i++){
    ASSERT(output[i] == expected[i], "\texpected:" << expected[i] << " output:" << output[i]);
  }
  cout << "successful insert at tail\n";

}

void test_remove_at_tail(){
  Doubly_ll dll;

  int expected[] = {3, 4, 5, 6, 5, 4, 3};
  int output[5] = {};

  // todo fix this
  dll.insert_at_tail(3);
  output[0] = dll.get_tail();
  dll.insert_at_tail(4);
  output[1] = dll.get_tail();
  dll.insert_at_tail(5);
  output[2] = dll.get_tail();
  dll.insert_at_tail(6);
  output[3] = dll.get_tail();
  dll.remove_at_tail();
  output[4] = dll.get_tail();
  dll.remove_at_tail();
  output[5] = dll.get_tail();
  dll.remove_at_tail();
  output[6] = dll.get_tail();

  /* for (int i = 0;i < 5;i++){
    output[i] = dll.get_tail();
  } */

  for (int i = 0;i < 5;i++){
    ASSERT(output[i] == expected[i], "\texpected:" << expected[i] << " output:" << output[i]);
  }
  cout << "successful remove at tail\n";

}

void test() {
  test_insert_at_head();
  // test_remove_at_head();
  // test_insert_at_tail();
  // test_remove_at_tail();
}
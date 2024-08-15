#include<iostream>
#include "assert.h"

// todo insert at any point / ARBITRARY POINT / index
// todo remove at any point / ARBITRARY POINT / index

struct Node {
	Node *next_node = nullptr;
	int data;
};

class circular_linked_list {
	// todo move head here
public:
	Node *head = nullptr;
	// construction
	// circular_linked_list() : head(nullptr) {};

	int elem_count = 0;
	//Node* tail = nullptr;

	const bool is_empty() {
		return elem_count == 0;
	}

	int get_head(){
		if (is_empty()) {
			return 0;
		}
		return head->data;
	}

	int size() const { return elem_count; }

	void insert_at_head(int elem) {
		//head->data = elem;
		if (!is_empty()){
			Node *temp = new Node;
			temp->data = elem;
			temp->next_node = head;
			head = temp;
		}
		else {
			head = new Node;
			head->data = elem;
			head->next_node = head;
		}
		elem_count += 1;
	}

	int remove_at_head() {
		Node *temp = head;
		head = head->next_node;
		elem_count--;
		delete temp;
		return 0;
	}
};

void assert_circular_linked_list(circular_linked_list *cll, int *expected_ll, int expected_length){
	// todo make it work while head is not in public
	Node *temp = cll->head;
	int index = 0;

	while (temp != nullptr){
		int output = temp->data;
		int expected = expected_ll[index++];

		ASSERT(output == expected, "expected:" << expected << "\toutput:" << output);
		temp = temp->next_node;
	}

	ASSERT(index == expected_length, "elem count mismatch");
}

void test_insert_at_head(){
	circular_linked_list cll;
	cll.insert_at_head(11);
	cll.insert_at_head(21);
	cll.insert_at_head(31);

	int size = 3;
	int *expected = new int[size]{31, 21, 11};
	assert_circular_linked_list(&cll, expected, size);

	std::cout << "successful insertion at head\n";
}

void test_remove_at_head(){
	circular_linked_list cll;
	cll.insert_at_head(11);
	cll.insert_at_head(21);
	cll.insert_at_head(31);
	cll.remove_at_head();
	cll.remove_at_head();

	int size = 1;

	//todo use vector 
	// std::vector<int> expected = {11};

	int *expected = new int[size]{11};
	assert_circular_linked_list(&cll, expected, size);

	std::cout << "successful removal at head\n";
}

void test(){
	circular_linked_list cll;

	cll.insert_at_head(11);
	cll.insert_at_head(21);
	cll.insert_at_head(31);
	std::cout << cll.head->next_node->next_node->next_node->next_node->data<<std::endl;
	// std::cout << cll.get_head();


	// test_insert_at_head();
	// test_remove_at_head();

}
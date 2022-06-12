#include<iostream>
using namespace std;


template<class type>
class Node {
public:
	type data;
	Node<type> * next;

	Node()
	{ next = NULL; }
	Node(type val, Node<type> * nptr = 0) {
		data = val;
		next = nptr;
	}};template<class type>
class List {
private:
	Node<type> * head;
public:
	List()
	{
		head = 0; 
	}

	void addtostart(type val)
	{
		head = new Node<type>(val, head);	}
	Node* reverse(Node* node)
	{
		if (node == NULL)
			return NULL;
		if (node->next == NULL) {
			head = node;
			return node;
		}
		Node* node1 = reverse(node->next);
		node1->next = node;
		node->next = NULL;
		return node;
	}
	void recursiveReverse()
	{
		reverse(head);
	}
	
	bool areequal(Node* a, Node* b){
		if (a->data != b->data)
			return false;
		else if (a->next == NULL && b->next == NULL)
			return true;
		else if (a->data == b->data)
			return true;
		else
			return areIdentical(a->next, b->next);
	}
	bool isEqual(List const& obj) {
		return areequal(obj.head, this->head)
	}

	void copy(Node*& tmp1, Node*& tmp2)
	{
		if (tmp1 == nullptr)
			return;
		if (tmp1->next == nullptr){
			tmp2 = new Node();
			tmp2->data = tmp1->data;
			tmp2->next = nullptr;
			return;
		}
		Node* cursor = tmp1->next;
		copy(cursor, tmp2->next);
	}
	void deepCopy(List const& obj)
	{
		Node<type>* tmp1 = head;
		Node<type>* tmp2 = head;
		this->copy(tmp1, tmp2);
	}
	
	void print()
	{
		Node<type> * tmp;
		for (tmp = head; tmp != 0; tmp = tmp->next)
		{
			cout << tmp->data << " ";
		}
		cout << endl;
	}
	~List()
	{
		Node<type> * p = head;
		for (;p != 0; p = p->next) {
			delete head;
			head = p;
		}
	}};int main(){	List<int> L1;	L1.addtostart(10);	L1.addtostart(9);	L1.addtostart(7);	L1.addtostart(5);	List<int> L2;	L1.deepCopy(L2);	//L1.print();	//L2.print();	L1.isEqual(L2);	L1.recursiveReverse();	L1.isEqual(L2);	system("pause");	return 0;}
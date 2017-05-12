/*
Created by 梁星(2017-03-17)
*/
#include<iostream>
using std::cout;
using std::endl;

template<class T>
struct Node{
	T value;
	Node *next;
};
template<class T> class forward_list {	
private:
	typedef T ValueType;
	typedef Node<T> NodeType;
	NodeType *front;
public:
	forward_list() {
		front = nullptr;
	}
	class iterator {
		friend forward_list;
	private:
		NodeType* iter;
	public:
		iterator& operator++() { //前置++
			iter = iter->next;
			return *this;
		}
		iterator operator++(int) { //后置++
			iterator temp = *this;
			++*this;
			return temp;
		}
		ValueType& operator*() {
			return iter->value;
		}
		bool operator!=(const iterator& iter2) {
			return !(iter == iter2.iter);
		}
	};
	iterator begin() {
		iterator itr;
		itr.iter = front;
		return itr;
	}
	iterator end() {
		iterator itr;
		itr.iter = nullptr;
		return itr;;
	}
	void push_front(const ValueType &value) {  //区分空列表和非空列表两种情况
		if (front == nullptr) {
			NodeType *newNode = new NodeType;
			newNode->value = value;
			newNode->next = nullptr;
			front = newNode;
		}
		else {
			NodeType *newNode = new NodeType;
			newNode->value = value;
			newNode->next = front;
			front = newNode;
		}
	}
	void pop_front() {  //首先判断列表是否为空
		if (!front) {
			cout << "empty list!" << endl;
			exit(-1);
		}
		else {
			NodeType *temp = front;
			front = front->next;
			delete temp;
		}
	}
	void insert_after(iterator &itr,const ValueType &value) {
		NodeType *newNode = new NodeType;
		newNode->value = value;
		newNode->next = itr.iter->next;
		itr.iter->next = newNode;	
	}
	void erase_after(iterator &itr) {
		if (!itr.iter->next) {
			cout << "nullptr" << endl;
			exit(-1);
		}
		else {
			NodeType *temp = itr.iter->next;
			itr.iter->next = temp->next;
			delete temp;
		}
	}
	int size() {
		int count = 0;
		NodeType *current = front;
		while (current) {
			count++;
			current = current->next;
		}
		return count;
	}
	void clear() {
		while (front) {
			NodeType *temp = front;
			front = front->next;
			delete temp;
		}
	}
	bool empty() {
		return front == nullptr;
	}
	void remove(const ValueType &value) {
		NodeType *current = front;
		NodeType *previous = front;
		while (current) {
			if (current->value == value)
				break;
			previous = current;
			current = current->next;
		}
		if (!current) {
			cout << "no such value" << endl;
			exit(-1);
		}
		else {
			if (current == front) 
				front = front->next;
			else
				previous->next = current->next;
			delete current;
		}
	}
	template<class UnaryPredicate>
	void remove_if(UnaryPredicate p) {
		NodeType *current = front, *previous = front;
		while (current) {			
			if (p(current)) {
				if (current == front)
					front = front->next;
				else
					previous->next = current->next;
				NodeType* temp = current;
				current = current->next;
				delete temp;
				continue;
			}
			previous = current;
			current = current->next;
		}
	};
	void reverse() {
		NodeType *current = front;
		NodeType *previous = nullptr;
		while (current) {
			NodeType *temp = current->next;
			current->next = previous;
			previous = current;
			current = temp;
		}
		front = previous;
	}
	template<class BinaryPredicate>
	void sort(BinaryPredicate cmp) {  //冒泡排序
		bool exchange = true;
		for (int i = 1; i < size() && exchange;i++) {
			exchange = false;
			NodeType *current = front;
			for(int j = 0;j < size() - i;j++) {
				if (!cmp(current->value,current->next->value)) {
					exchange = true;
					ValueType temp = current->value;
					current->value = current->next->value;
					current->next->value = temp;
				}
				current = current->next;
			}
		}
	};
	template<class BinaryPredicate>
	void merge(forward_list<T> &list2,BinaryPredicate cmp) {
		NodeType *current1 = front;
		NodeType *current2 = list2.front;
		NodeType *newFront = nullptr;			//新链表头指针
		NodeType *newBack = nullptr;			//新链表尾指针
		while (current1 != nullptr && current2 != nullptr) {
			if (cmp(current1->value , current2->value)) {   //依次比较两节点值大小，根据谓词，将符合条件的节点移到新链表
				NodeType * temp1 = current1->next;
				current1->next = nullptr;
				if (newBack != nullptr)
					newBack->next = current1;
				if (newFront == nullptr)
					newFront = current1;
				newBack = current1;
				current1 = temp1;
			}
			else {				
				NodeType * temp2 = current2->next;
				current2->next = nullptr;
				if (newBack != nullptr)
					newBack->next = current2;
				if (newFront == nullptr)
					newFront = current2;
				newBack = current2;
				current2 = temp2;
			}
		}
		if (current1 == nullptr)
			newBack->next = current2;
		else
			newBack->next = current1;
		front = newFront;
	};
};
bool cmp(int a, int b) {
	return a < b;
}
bool pre(Node<int> *n) {
	return n->value % 2 == 0;
}
int main() {
	forward_list<int> list1,list2;

	list1.push_front(4);	
	list1.push_front(5);
	list1.push_front(2);
	list1.push_front(15);
	list1.push_front(10);
	list1.push_front(9);

	list2.push_front(17);
	list2.push_front(12);
	list2.push_front(11);
	list2.push_front(8);
	list2.push_front(5);
	list2.push_front(2);

	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//push_front
	cout << "operation: list1.push_front(16)" << endl;
	list1.push_front(16);
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//pop_front
	cout << "operation: list1.pop_front()" << endl;
	list1.pop_front();
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//insert_after
	cout << "operation: insert_after(list1.begin(),7)" << endl;
	list1.insert_after(list1.begin(), 7);
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//erase_after
	cout << "operation: erase_after(++list1.begin())" << endl;
	list1.erase_after(++list1.begin());
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//reverse
	cout << "operation: list1.reverse()" << endl;
	list1.reverse();
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//sort
	cout << "operation: list1.sort(cmp)" << endl;
	list1.sort(cmp);
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//merge
	cout << "list2: ";
	for (forward_list<int>::iterator iter = list2.begin(); iter != list2.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	cout << "operation: list1.merge(list2,cmp)" << endl;
	list1.merge(list2,cmp);
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//size
	cout << "operation: list1.size()" << endl;
	cout << list1.size() << "\n" << endl;

	//remove
	cout << "operation: list1.remove(15)" << endl;
	list1.remove(15);
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//remove_if
	cout << "operation: remove all the even numbers in list1 by remove_if" << endl;
	list1.remove_if(pre);
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//clear
	cout << "operation: list1.clear()" << endl;
	list1.clear();
	cout << "list1: ";
	for (forward_list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;

	//empty
	cout << "operation:list1.empty()" << endl;
	if (list1.empty())
		cout << "list1 is empty!" << endl;
	
	return 0;
}
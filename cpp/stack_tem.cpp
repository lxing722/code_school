#include<iostream>
#include<string>
#include<vector>
#include"stack.h"
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
template<class T> class stack {
private:
	vector<T> a;
public:
template<class T>
	void stack<T>::push(T b) {
		a.push_back(b);
	};
	template<class T>
	T stack<T>::pop() {
		if (!a.empty()) {
			T temp = a.back();
			a.pop_back();
			return temp;
		}
		else {
			cout << "empty stack!" << endl;
			exit(-1);
		}
	};
	template<class T>
	unsigned long stack<T>::size() {
		return a.size(); //unsigned long type
	};
	template<class T>
	T stack<T>::top() {
		if (!a.empty()) 
			return a.back(); //*a.rbegin() or v[v.size()-1]
		else {
			cout << "empty stack!" << endl;
			exit(-1);
		}
	};
	template<class T>
	bool stack<T>::isEmpty() {
		return a.empty();
	};


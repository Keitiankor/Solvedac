#pragma once
#include "Node.hpp"

template<typename T> class Stack {
	private:
	Node<T>* head;
	int length;
	void init(Node<T>* node);

	public:
	Stack();
	int size();
	bool empty();
	void push(T data);
	void pop();
	T back();
};

#include "Stack.tpp"

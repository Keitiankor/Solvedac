#pragma once

#include "Node.hpp"

template<typename T> class Queue {
	private:
	Node<T>* head;
	Node<T>* tail;
	int length;
	void init(Node<T>* node);

	public:
	Queue();
	int size();
	bool empty();
	void push(T data);
	void pop();
	T front();
	T back();
};

#include "../tpp/Queue.tpp"
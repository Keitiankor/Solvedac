#pragma once

#include "../hpp/Node.hpp"

template<typename T> class Deque {
	private:
	Node<T>* head;
	Node<T>* tail;
	int length;

	public:
	Deque();
	void init(Node<T>* node);
	bool empty();
	void push_front(T data);
	void push_back(T data);
	T front();
	T back();
	void pop_back();
	void pop_front();
	int size();
};

#include "../tpp/Deque.tpp"
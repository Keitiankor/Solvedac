#pragma once

template<typename T> class Node {
	Node* front;
	Node* before;
	T data;

	public:
	Node(T data);
	void setFront(Node* n);
	void setBefore(Node* n);
	T getData();
	Node* getFront();
	Node* getBefore();
};

#include "../tpp/Node.tpp"
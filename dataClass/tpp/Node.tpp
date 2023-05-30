#include "Node.hpp"

template<typename T> Node<T>::Node(T data) {
	this->front	 = nullptr;
	this->before = nullptr;
	this->data	 = data;
}

template<typename T> void Node<T>::setFront(Node* n) {
	this->front = n;
	n->before	= this;
}

template<typename T> void Node<T>::setBefore(Node* n) {
	this->before = n;
	n->front	 = this;
}

template<typename T> T Node<T>::getData() {
	return data;
}

template<typename T> Node<T>* Node<T>::getBefore() {
	return this->before;
}

template<typename T> Node<T>* Node<T>::getFront() {
	return this->front;
}
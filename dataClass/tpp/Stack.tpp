#include "Stack.hpp"

template<typename T> void Stack<T>::init(Node<T>* node) {
	this->head	 = node;
	this->length = 1;
}
template<typename T> Stack<T>::Stack() {
	this->head	 = nullptr;
	this->length = 0;
}
template<typename T> int Stack<T>::size() {
	return this->length;
}
template<typename T> bool Stack<T>::empty() {
	if(this->length == 0)
		return true;
	else
		return false;
}
template<typename T> void Stack<T>::push(T data) {
	Node<T>* node = new Node<T>(data);
	switch(this->length) {
	case 0:
		this->init(node);
		break;
	default:
		this->head->setFront(node);
		this->head	 = node;
		this->length = this->length + 1;
		break;
	}
}
template<typename T> void Stack<T>::pop() {
	switch(this->length) {
	case 0:
		break;
	case 1:
		this->head	 = nullptr;
		this->length = this->length - 1;
	default:
		this->head	 = this->head->getBefore();
		this->length = this->length - 1;
	}
}
template<typename T> T Stack<T>::back() {
	return this->head->getData();
}
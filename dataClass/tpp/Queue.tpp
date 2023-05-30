#include "Queue.hpp"

template<typename T> Queue<T>::Queue() {
	this->head	 = nullptr;
	this->tail	 = nullptr;
	this->length = 0;
}

template<typename T> void Queue<T>::init(Node<T>* node) {
	this->head	 = node;
	this->tail	 = node;
	this->length = 1;
}

template<typename T> int Queue<T>::size() {
	return this->length;
}

template<typename T> bool Queue<T>::empty() {
	if(this->length == 0)
		return true;
	else
		return false;
}

template<typename T> void Queue<T>::push(T data) {
	Node<T>* node = new Node<T>(data);
	switch(this->length) {
	case 0:
		this->init(node);
		break;
	default:
		this->tail->setBefore(node);
		this->tail	 = node;
		this->length = this->length + 1;
		break;
	}
}

template<typename T> void Queue<T>::pop() {
	switch(this->length) {
	case 0:
		break;
	case 1:
		this->head	 = nullptr;
		this->tail	 = nullptr;
		this->length = this->length - 1;
		break;
	default:
		this->tail	 = tail->getFront();
		this->length = this->length - 1;
		break;
	}
}

template<typename T> T Queue<T>::front() {
	return this->head->getData();
}

template<typename T> T Queue<T>::back() {
	return this->tail->getData();
}
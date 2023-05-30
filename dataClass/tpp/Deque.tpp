#include "../hpp/Deque.hpp"

template<typename T> Deque<T>::Deque() {
	this->head	 = nullptr;
	this->tail	 = nullptr;
	this->length = 0;
}

template<typename T> void Deque<T>::init(Node<T>* node) {
	this->head	 = node;
	this->tail	 = node;
	this->length = 1;
}

template<typename T> bool Deque<T>::empty() {
	if(this->length == 0)
		return true;
	else
		return false;
}

template<typename T> void Deque<T>::push_front(T data) {
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

template<typename T> void Deque<T>::push_back(T data) {
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

template<typename T> T Deque<T>::front() {
	return this->head->getData();
}

template<typename T> T Deque<T>::back() {
	return this->tail->getData();
}

template<typename T> void Deque<T>::pop_front() {
	switch(this->length) {
	case 0:
		break;
	case 1:
		this->head = nullptr;
		this->tail = nullptr;
		length--;
		break;
	default:
		this->head = head->getBefore();
		length--;
		break;
	}
}

template<typename T> void Deque<T>::pop_back() {
	switch(this->length) {
	case 0:
		break;
	case 1:
		this->head = nullptr;
		this->tail = nullptr;
		length--;
		break;
	default:
		this->tail = tail->getFront();
		length--;
		break;
	}
}

template<typename T> int Deque<T>::size() {
	return this->length;
}
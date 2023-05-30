/**
 * push X: 정수 X를 스택에 넣는 연산이다.
 * pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * size: 스택에 들어있는 정수의 개수를 출력한다.
 * empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
 * top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 **/
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
#include "../hpp/CloseList.hpp"

template<typename T> CloseList<T>::CloseList(T v) {
    this->nodeNum = v;
    this->lst     = new std::list<T>[v];
}

template<typename T> void CloseList<T>::addEdge(T node1, T node2) {
    lst[node1] = node2;
    lst[node2] = node1;
}
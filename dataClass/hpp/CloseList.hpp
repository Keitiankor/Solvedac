#pragma once

#include "list"

template<typename T> class CloseList {
    private:
    std::list<T> lst;
    T nodeNum;

    public:
    bool visit;
    CloseList(T v);
    void addEdge(T node1, T node2);
    std::list<T> getList();
    T getNode;
};

#include "../tpp/CloseList.tpp"
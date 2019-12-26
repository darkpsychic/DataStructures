#pragma once
#include <initializer_list>
#include <memory>

template <typename T>
class ArrayList
{
public:
    //explicit-default constructor
    ArrayList();

    //construct an ArrayList using an initialzier list
    ArrayList(const std::initializer_list<T> &list);

    //capacity
    size_t size() const;
    void resize(size_t n);
    size_t capacity() const;
    bool empty();
    void reserve();

    //element access
    T &operator[](const size_t ind);
    T &at(const size_t ind);
    T &front();
    T &back();

    //modifiers
    void push_back(const T &elem);
    void pop_back();
    void insert(const T &elem, const size_t ind);
    void erase(const size_t ind);
    void clear();

private:
    std::unique_ptr<T[]> m_arr;
    size_t m_curSize;
};

#include "ArrayList.hpp"

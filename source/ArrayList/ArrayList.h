#pragma once
#include <initializer_list>
#include <stdexcept>
#include <memory>

template <typename T>
class ArrayList
{
public:
    //explicit-default constructor
    ArrayList();

    //construct an ArrayList using an initialzier list
    ArrayList(const std::initializer_list<T> &list);

    //relational operators
    bool operator==(const ArrayList<T> &list);

    //capacity
    size_t size() const;
    void resize(size_t n);
    size_t capacity() const;
    bool empty() const;
    void shrink_to_fit();

    //element access
    T &operator[](const long long ind) const;
    T &at(const long long ind);
    T &front();
    T &back();

    //modifiers
    void push_back(const T &elem);
    void pop_back();
    void insert(const T &elem, const long long ind);
    void erase(const long long ind);
    void clear();

private:
    std::unique_ptr<T[]> m_arr;
    size_t m_allocatedSize;
    size_t m_curSize;
};

#include "ArrayList.hpp"

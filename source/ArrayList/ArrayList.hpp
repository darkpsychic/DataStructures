#include "ArrayList.h"

template <typename T>
ArrayList<T>::ArrayList()
{
    m_curSize = 32;
    m_arr = std::make_unique<T[]>(32);
}

template <typename T>
ArrayList<T>::ArrayList(const std::initializer_list<T> &list)
{
    size_t list_size = list.size();
    m_curSize = list_size;
    m_arr = std::make_unique<T[]>(m_curSize);
}
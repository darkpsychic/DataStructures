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

template <typename T>
size_t ArrayList<T>::size() const
{
    return m_curSize;
}

template <typename T>
void ArrayList<T>::resize(size_t n)
{
    if (n == m_curSize)
    {
        return;
    }

    auto newArr = std::make_unique<T[]>(n);
    for (size_t i = 0; i < n; ++i)
    {
        if (i >= m_curSize)
        {
            newArr[i] = T{};
        }
        else
        {
            newArr[i] = m_arr[i];
        }
    }

    m_arr.reset(newArr.release());
    m_curSize = n;
}
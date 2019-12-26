#include "ArrayList.h"

template <typename T>
ArrayList<T>::ArrayList()
{
    m_allocatedSize = 32;
    m_curSize = 0;
    m_arr = std::make_unique<T[]>(32);
}

template <typename T>
ArrayList<T>::ArrayList(const std::initializer_list<T> &list)
{
    m_curSize = list.size();
    m_allocatedSize = 2 * m_curSize;
    m_arr = std::make_unique<T[]>(m_allocatedSize);

    size_t i = 0;
    for (auto const &it : list)
    {
        m_arr[i] = it;
        ++i;
    }
}

template <typename T>
size_t ArrayList<T>::size() const
{
    return m_curSize;
}

template <typename T>
void ArrayList<T>::resize(size_t n)
{
    if (n == m_allocatedSize)
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
    m_allocatedSize = n;
}

template <typename T>
size_t ArrayList<T>::capacity() const
{
    return sizeof(T) * m_allocatedSize;
}

template <typename T>
bool ArrayList<T>::empty() const
{
    return m_curSize == 0;
}

template <typename T>
void ArrayList<T>::shrink_to_fit()
{
    resize(m_curSize);
}

template <typename T>
T &ArrayList<T>::operator[](const size_t ind)
{
}
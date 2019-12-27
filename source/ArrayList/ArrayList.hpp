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
bool ArrayList<T>::operator==(const ArrayList<T> &list)
{
    if (list.size() != size())
    {
        return false;
    }

    for (size_t i = 0; i < size(); ++i)
    {
        if (at(i) != list[i])
        {
            return false;
        }
    }

    return true;
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
    if (m_curSize > n)
    {
        m_curSize = n;
    }
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
T &ArrayList<T>::operator[](const long long ind) const
{
    if (ind < 0 || ind >= (long long)(m_curSize))
    {
        throw std::out_of_range("invalid index" + __LINE__);
    }

    return m_arr[ind];
}

template <typename T>
T &ArrayList<T>::at(const long long ind)
{
    return (*this)[ind];
}

template <typename T>
T &ArrayList<T>::front()
{
    return at(0);
}

template <typename T>
T &ArrayList<T>::back()
{
    return at((long long)(m_curSize)-1);
}

template <typename T>
void ArrayList<T>::push_back(const T &elem)
{
    if (size() + 1 >= m_allocatedSize)
    {
        resize(2 * m_allocatedSize);
    }

    m_curSize += 1;
    at(size() - 1) = elem;
}

template <typename T>
void ArrayList<T>::pop_back()
{
    if (size() == 0)
    {
        throw std::out_of_range("invalid index" + __LINE__);
    }

    back() = T{};
    m_curSize -= 1;
}

template <typename T>
void ArrayList<T>::insert(const T &elem, const long long ind)
{
    if (ind < 0 || ind > (long long)(size()))
    {
        throw std::out_of_range("invalid index" + __LINE__);
    }

    m_curSize += 1;
    if (size() >= m_allocatedSize)
    {
        resize(2 * m_allocatedSize);
    }

    T last = elem;
    for (size_t i = ind; i < size(); ++i)
    {
        T cur = last;
        last = at(i);
        at(i) = cur;
    }
}

template <typename T>
void ArrayList<T>::erase(const long long ind)
{
    if (ind < 0 || ind >= (long long)(size()))
    {
        throw std::out_of_range("invalid index" + __LINE__);
    }

    if (ind == (long long)(size()) - 1)
    {
        pop_back();
    }
    else
    {
        for (size_t i = ind; i < size() - 1; ++i)
        {
            at(i) = at(i + 1);
        }

        m_curSize -= 1;
    }
}

template <typename T>
void ArrayList<T>::clear()
{
    m_curSize = 0;
}
#include "ArrayList.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    ArrayList<int> list;
    ArrayList<int> list2({1, 2, 3, 4, 5});

    assert(list.size() == 0);
    assert(list2.size() == 5);

    list2.resize(7);
    assert(list2.size() == 5);

    list2.resize(4);
    assert(list2.size() == 4);

    assert(list2.capacity() == list2.size() * sizeof(int));

    assert(list2[0] == 1);

    try
    {
        //list2[-1];
        list2.at(4);
        cout << "Doesn't catch Erroneous code";
    }
    catch (const std::out_of_range &e)
    {
    }

    try
    {
        list.back();
        cout << "Doesn't catch Erroneous code";
    }
    catch (const std::out_of_range &e)
    {
    }

    list.push_back(23);
    assert(list.size() == 1);
    assert(list.front() == 23);
    assert(list.back() == 23);
    assert(list[0] == 23);
    assert(list.at(0) == 23);

    list[0] = 32;
    assert(list[0] == 32);
    list.at(0) = 23;
    assert(list.at(0) == 23);
    list.front() = 32;
    assert(list.front() == 32);
    list.back() = 1;
    assert(list.back() == 1);

    list.push_back(2);
    list.pop_back();
    assert(list.size() == 1);
    assert(list.back() == 1);

    list.insert(2, 1);
    list.insert(4, 2);
    list.insert(5, 3);
    list.insert(3, 2);
    list.insert(0, 0);
    for (int i = 0; i <= 5; ++i)
    {
        assert(list[i] == i);
    }

    list.erase(3);
    assert(list.size() == 5);
    assert(list == ArrayList<int>({0, 1, 2, 4, 5}));
    list.erase(0);
    assert(list == ArrayList<int>({1, 2, 4, 5}));
    list.erase(3);
    assert(list == ArrayList<int>({1, 2, 4}));

    list.clear();
    assert(list.size() == 0);

    try
    {
        list[0];
        std::cout << "Doesn't handle exceptions\n";
    }
    catch (const std::out_of_range &e)
    {
    }
}
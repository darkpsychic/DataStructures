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
    assert(list2.size() == 7);

    list2.resize(4);
    assert(list2.size() == 4);

    assert(list2.capacity() == list2.size() * sizeof(int));

    assert(list2[0] == 1);

    try
    {
        //list2[-1];
        list2.at(4);
    }
    catch (const std::out_of_range &e)
    {
        assert(e.what() == std::string("invalid index"));
    }

    try
    {
        list.back();
    }
    catch (const std::out_of_range &e)
    {
        assert(e.what() == std::string("invalid index"));
    }
}
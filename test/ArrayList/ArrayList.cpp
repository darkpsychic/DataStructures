#include "ArrayList.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    ArrayList<int> list;
    ArrayList<int> list2({1, 2, 3, 4, 5});

    assert(list.size() == 32);
    assert(list2.size() == 5);

    list2.resize(7);
    assert(list2.size() == 7);

    list2.resize(4);
    assert(list2.size() == 4);
}
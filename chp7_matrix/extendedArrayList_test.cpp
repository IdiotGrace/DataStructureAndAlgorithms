#include <iostream>
#include <vector> 
#include "extendedArrayList.h"

template <typename T>
class elem
{
public:
    T value; 
};

template <typename T>
class array
{
public: 
    std::vector<T> list; 
};

int main()
{
    /*
    arrayList<int> a;
    a.insert(0, 1);
    a.insert(1, 2);
    a.insert(2, 3);

    for (arrayList<int>::iterator i=a.begin(); i!=a.end(); i++)
    {
        std::cout << *i << std::endl; 
    }
    */

    //arrayList< elem<int> > b;
    array< elem<int> > ar; 
    elem<int> e1;
    e1.value = 1;
    ar.list.push_back(e1);
    std::cout << ar.list[0].value << std::endl; 

    /*
    b.insert(0, e1);
    elem<int> e2;
    e2.value = 2;
    b.insert(0, e2);

    for (arrayList<elem<int>>::iterator i=b.begin(); i!=b.end(); i++)
    {
        std::cout << (*i).value << std::endl; 
    }
    */

    std::cout << "Done! " << std::endl; 
    return 0;
}

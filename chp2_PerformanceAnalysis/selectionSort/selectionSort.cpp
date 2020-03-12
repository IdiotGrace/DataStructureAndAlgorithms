
#include <iostream>
#include <algorithm>
#include <iterator>
#include "indexOfMax.h"

using namespace std;

template<typename T>
void selectionSort(T a[], int n)
{
    for(int size = n; size > 1; size--)
    {
        int j = indexOfMax(a, size);
        swap(a[j], a[size-1]);
    }
}

int main()
{
    int a[10] = {3, 2, 4, 1, 6, 9, 8, 7, 5, 0};

    // output the elements
    cout << "a[0:9] = ";
    copy(a, a+10, ostream_iterator<int>(cout, " "));
    cout << endl;

    // sort
    selectionSort(a,10);

    // output the sorted sequence
    cout << "After the sort, a[0:9] = ";
    copy(a, a+10, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
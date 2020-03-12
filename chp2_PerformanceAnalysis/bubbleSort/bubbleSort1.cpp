#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T>
bool bubble(T a[], int n)
{
    bool swapped = false;
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] > a[i+1])
            swap(a[i], a[i+1]);
            swapped = true;
    }
    return swapped;
}

template<typename T>
void bubbleSort(T a[], int n)
{
    for(int i = n; i > 1 && bubble(a, i); i--);
}

int main()
{
    int a[10] = {10,7,8,9,4, 2, 3, 6, 5,1};

    // output the elements
    cout << "a[0:9] = ";
    copy(a, a+10, ostream_iterator<int>(cout, " "));
    cout << endl;

    // sort
    bubbleSort(a,10);

    // output the sorted sequence
    cout << "After the sort, a[0:9] = ";
    copy(a, a+10, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
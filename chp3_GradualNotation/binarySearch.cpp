// binary search
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename T>
int binarySearch(T a[], int n, const T& x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int middle = (left + right) / 2;
        if(x == a[middle])
            return middle;
        if(x > a[middle])
        {
            left = middle + 1;
        }
        else 
        {
            right = middle - 1; 
        }
    }

    return -1;
}

int main()
{
    int a[7] = {0, 2, 3, 4, 6, 7, 9};
    cout << binarySearch(a, 7, 4) << endl;
}
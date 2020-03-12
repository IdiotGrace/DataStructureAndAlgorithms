//rank or count sort
//rearrange elements using an additional array

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T>
void rearrange(T a[], int n, int r[])
{
    T *u = new T[n];

    for(int i = 0; i < n; i++)
    {
        u[r[i]] = a[i];
    }

    for(int i = 0; i < n; i++)
    {
        a[i] = u[i];
    }

    delete [] u;
}

template<class T>
void ranking(T a[], int n, int r[])
{
    for(int i = 0; i < n; i++)
    {
        r[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
                r[i]++;
            else
                r[j]++;
            
        }
    }
}

int main()
{
    int a[6] = {2, 6, 4, 3, 1, 5};
    int r[6];

    // output the elements
    cout << "a[0:5] = ";
    copy(a, a+6, ostream_iterator<int>(cout, " "));
    cout << endl;

    // determine the ranks
    ranking(a, 6, r);
    rearrange(a, 6, r);

    // output the sorted
    cout << "After the sort, a[0:5] = ";
    copy(a, a+6, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;

}

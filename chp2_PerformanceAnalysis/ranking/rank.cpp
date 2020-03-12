//compute element ranks

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

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
    ranking(a,6,r);

    // output the ranks
    cout << "r[0:5] = ";
    copy(r, r+6, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;

}


#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T>
void insert(T a[], int& n, const T& x)
{
    int i;
    for(i = n - 1; i >= 0 & a[i] > x; i--)
    {
        a[i+1] = a[i];
    }
    a[i+1] = x;
    n++;
}

int main()
{
   int a[10] = {1, 2, 4, 6, 8, 10, 12, 0, 0, 0};
   int x; // element to be inserted
   int n = 7;

   // output the elements
   cout << "a[0:6] = ";
   copy(a, a+n, ostream_iterator<int>(cout, " "));
   cout << endl;

   // do a few inserts
   x = 14;
   insert(a,n,x);
   cout << "After inserting 14, a[0:7] = ";
   copy(a, a+n, ostream_iterator<int>(cout, " "));
   cout << endl;

   x = 5;
   insert(a,n,x);
   cout << "After inserting 5, a[0:8] = ";
   copy(a, a+n, ostream_iterator<int>(cout, " "));
   cout << endl;

   x = 0;
   insert(a,n,x);
   cout << "After inserting 0, a[0:9] = ";
   copy(a, a+n, ostream_iterator<int>(cout, " "));
   cout << endl;

   return 0;
}

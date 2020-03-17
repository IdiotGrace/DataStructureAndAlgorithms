#ifndef studentRecord_
#define studentRecord_

#include <string>
#include<iostream>

using namespace std;
struct studentRecord 
{
    int score;
    string* name;

    operator int()  const { return score; }
    int operator !=(const studentRecord& x) const
    {
        return x.score != score;
    }

};

ostream& operator<<(ostream& out, const studentRecord& x)
   {out << x.score << ' ' << *x.name << endl; return out;}

#endif
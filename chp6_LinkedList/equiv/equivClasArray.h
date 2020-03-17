#ifndef equivClassArray_
#define equivClassArray_

int *equivClass, n;
void initialize(int numberOfElements)
{
    n = numberOfElements;
    equivClass = new int[n + 1];
    for(int e = 1; e <= n; e++)
    {
        equivClass[e] = e;
    }

    void unite(int classA, int classB)
    {
        for(int k = 1; k <= n; k++)
        {
            if(equivClass[k] == classB)
            {
                equivClass[k] = classA;
            }
        }
    }

    int find(int theElement)
    {
        return equivClass[theElement];
    }
}

#endif
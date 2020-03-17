// linked implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented

#ifndef chain_
#define chain_

#include <iostream>
#include <sstream>
#include <string>
#include "linearList.h"
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;

class linkedDigraph;
template <class T>
class linkedWDigraph;

template <typename T>
class chain : public linearList<T>
{
    friend linkedDigraph;
    friend linkedWDigraph<int>;
    friend linkedWDigraph<float>;
    friend linkedWDigraph<double>;

    public:
        chain(int initialCapacity = 10);
        chain(const chain<T> &);
        ~chain();

        bool empty() const { return listSize == 0; }
        int size() const { return listSize; }
        T &get(int theIndex) const;
        int indexOf(const T &theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T &theElement);
        void output(ostream &out) const;
        
        class iterator;
        iterator begin() { return iterator(firstNode); }
        iterator end() { return iterator(NULL); }
        
        class iterator
        {
            public:
                typedef forward_iterator_tag iterator_category;
                typedef T value_type;
                typedef ptrdiff_t difference_type;
                typedef T* pointer;
                typedef T& reference;;

                iterator(chainNode<T>* theNode = NULL) { node = theNode; }

                T& operator*() const { return node->element; }
                T* operator->() const { return &node->element; }

                // increment
                iterator& operator++()   // preincrement
                      {node = node->next; return *this;}
                iterator operator++(int) // postincrement
            	      {iterator old = *this;
            	       node = node->next;
            	       return old;
            	      }

                // equality testing
                bool operator!=(const iterator right) const
                  {return node != right.node;}
                bool operator==(const iterator right) const
                  {return node == right.node;}
            protected:
                chainNode<T>* node;
        };
    protected:
        void checkIndex(int theIndex) const;
        chainNode<T> *firstNode; //指向链表第一个节点的指针
        int listSize;            //线性表元素个数
};

template <typename T>
chain<T>::chain(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

template <typename T>
chain<T>::chain(const chain<T> &theList)
{
    listSize = theList.listSize;
    if (listSize == 0)
    {
        firstNode = NULL;
        return;
    }

    //Non-empty list
    chainNode<T> *sourceNode = theList.firstNode;      // node in theList to copy from
    firstNode = new chainNode<T>(sourceNode->element); // copy first node element of theList

    sourceNode = sourceNode->next;
    chainNode<T> *targetNode = firstNode; //currnt last node in *this
    while (sourceNode != NULL)
    {
        //copy remaining elements
        targetNode->next = new chainNode<T>(sourceNode->element);
        sourceNode = sourceNode->next;
        targetNode = targetNode->next;
    }
    targetNode->next = NULL; //end the chain
}

template <typename T>
chain<T>::~chain()
{
    while (firstNode != NULL)
    {
        chainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <typename T>
void chain<T>::checkIndex(int theIndex) const
{
    // Verify that theIndex is between 0 and listSize - 1.
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template <typename T>
T &chain<T>::get(int theIndex) const
{
    // Return element whose index is theIndex.
    // Throw illegalIndex exception if no such element.
    checkIndex(theIndex);

    // move to desired node
    chainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;

    return currentNode->element;
}

template <typename T>
int chain<T>::indexOf(const T &theElement) const
{
    chainNode<T> *currentNode = firstNode;
    int index = 0;

    while (currentNode != NULL && currentNode->element != theElement)
    {
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template <typename T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T> *deleteNode;
    if (theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
        {
            p = p->next;
        }
        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}

template <typename T>
void chain<T>::insert(int theIndex, const T &theElement)
{
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if (theIndex == 0)
    {
        firstNode = new chainNode<T>(theElement, firstNode);
    }
    else
    {
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
        {
            p = p->next;
        }
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

template <typename T>
void chain<T>::output(ostream &out) const
{ // Put the list into the stream out.
    for (chainNode<T> *currentNode = firstNode;
         currentNode != NULL;
         currentNode = currentNode->next)
        out << currentNode->element << "  ";
}

// overload <<
template <typename T>
ostream &operator<<(ostream &out, const chain<T> &x)
{
    x.output(out);
    return out;
}

#endif

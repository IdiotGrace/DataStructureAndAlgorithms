#ifndef chainNode_
#define chainNode_

template<typename T>
struct chainNode
{
    //数据成员
    T element;
    chainNode<T> *next;

    //方法
    chainNode();
    chainNode(const T& element) { this->element = element; }
    chainNode(const T& element, chainNode<T>* next)
    {
        this->element = element;
        this->next = next;
    }
};

#endif
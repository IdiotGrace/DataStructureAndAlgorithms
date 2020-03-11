#include <iostream> 

class Test
{
public:
    int add(int a, int b);

};

int Test::add(int a, int b)
{
    return a + b; 
}

int main()
{
    std::cout << "Hello, World!" << std::endl; 

    Test t = Test();
    std::cout << t.add(1, 2) << std::endl; 
    return 0;
}
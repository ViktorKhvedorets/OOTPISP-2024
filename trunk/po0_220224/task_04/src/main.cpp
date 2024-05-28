#include <iostream>
#include "Money.h"
#include "Set.h"

int main()
{
    Set<int> tmp;
    tmp.Add(1);
    tmp.Add(2);
    tmp.Add(2);  
    tmp.Add(3);

    Set<int> tmp1;
    tmp1.Add(5);
    tmp1.Add(52);
    tmp1.Add(22);
    tmp1.Add(312);

    
    for (int i = 0; i < tmp1.Size(); ++i)
    {
        tmp.Add(tmp1[i]);
    }
    std::cout << tmp;

    
    std::cout << "Element at index 2 is " << tmp[2] << std::endl;

    
    if (tmp != tmp1)
    {
        std::cout << "Sets are not equal" << std::endl;
    }
    else
    {
        std::cout << "Sets are equal" << std::endl;
    }

    
    if (int element = 5; tmp(element))
    {
        std::cout << "Element " << element << " is in the set" << std::endl;
    }
    else
    {
        std::cout << "Element " << element << " is not in the set" << std::endl;
    }

    return 0;
}

#include "problem.h"
#include <iostream>

int main()
{
    products x;
    x.setstock(1,1,25);
    x.setstock(1,2,25);
    x.setstock(1,3,25);
    std::cout<<x.prod_col(1,1)<<"\n";
}
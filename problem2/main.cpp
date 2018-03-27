#include "problem.h"
#include <iostream>

using namespace std;

int main()
{
    products x;
    x.setstock(1,1,25);
    x.setstock(1,2,25);
    x.setstock(1,3,25);
    cout<<unsigned(x.getstock(1,1))<<endl;;

}
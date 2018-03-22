#include "problem1.h"
#include <iostream>
using namespace std;
int main(void)
{
    general school;
    school.reserve(8,15);
    cout<<school.check_available(8)<<endl;
    if (school.check_occupied(15,7) == 1) cout<<"seat occupied"<<endl;
    else cout<<"Not occupied"<<endl;
}
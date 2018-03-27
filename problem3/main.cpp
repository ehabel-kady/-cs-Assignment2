/*
->this file contains the main function that tries out the code functionality
*/
#include "problem.h"
int main(void)
{
    Heap *heap1 = new Heap(20);
    Heap *heap2 = new Heap(10);
    heap1->insert(10);
    heap1->insert(20);
    heap1->insert(30);
    heap1->insert(40);
    heap1->insert(50);
    heap2->insert(60);
    heap2->insert(70);
    heap2->insert(80);
    heap2->insert(90);
    heap2->insert(100);
    heap1-> buildmax();
    cout<<*heap1<<endl;
    cout<<(*heap1)[3]<<endl;
}
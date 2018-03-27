#include "problem.h"
#include <stdint.h>
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

    Heap heap3 = *heap1+60;
    //for(int i = 0; i < heap3.Nel; i++) cout<<heap3.array[i]<<endl;
    int x[5] = {10,20,30,40,50};
    heap1->adjust(x,1,5);
    //for(int i = 0; i < 5; i++) cout<<x[i]<<" ";
    heap1->buildmax(x,5);
    for(int i = 0; i < 5; i++) cout<<x[i]<<" ";
    uint8_t aa=5;
    cout<<"\na7a"<<(*heap1)[1]<<endl;
    cout << "value is " << unsigned(aa) << endl;
    *heap1 += *heap2;
    *heap1+=5;
    for(int i = 1; i <= heap1->top; i++) cout<<heap1->array[i]<<" ";
    cout<<"\n";

    //cout<< "the heap" <<(heap3)<<endl;
    *heap1 <<cout;
}
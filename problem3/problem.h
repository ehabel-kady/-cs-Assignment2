#include <iostream>
#include <cstdlib>
#include <ostream>
#define HEAP_H

using namespace std;

class Heap
{
private:
public:
    int * array;
    int MaxSize, Nel, top;
    void adjust (int a[], int i, int n);
    Heap(int MSize);
    bool insert (int item);
    bool delMax(int & item);
    void buildmax(int a[],int n);
    Heap operator+(Heap);
    Heap operator+(int x);
    int operator[](int i);
    Heap operator=(Heap);
    Heap operator+=(Heap);
    void operator+=(int x);
    std::ostream& operator<< (std::ostream& os);
    //~Heap();
};
void Heap::adjust (int a[], int i, int n)
{
    int j = 2*i, item = a[i];
    while ( j <= n )
    {
    if (j<n && (a[j] < a[j+1])) j++;
    // Compare left and right child
    // and let j be the larger child
    if ( item >= a[j] ) break;
    a[j/2] = a[j]; j*=2;
    }
    a[j/2] = item;
}
Heap::Heap(int MSize):MaxSize(MSize)
{
    array = (int *) calloc(MSize+1,sizeof(int));
    Nel = 0;
}
bool Heap::insert (int item)
{
    int i = ++Nel;
    if ( i == MaxSize)
    {
    cout << "heap size exceeded" << endl;
    return false;
    }
    top++;
    while ( (i > 1 ) && ( array[i/2] < item )) {
    array[i] = array[i/2];
    i/=2;
    }
    array[i] = item;
}
bool Heap::delMax(int & item)
{
    if ( !Nel) { cout << "heap is empty" << endl ; return false; }
    top--;
    item = array[1];
    array [1] = array[Nel--];
    adjust (array,1,Nel);
    return true;
}

void Heap::buildmax(int a[], int n)
{
    int i;
    for(i = n/2; i>=0; i--) adjust(a,i,n);
}

Heap Heap::operator+(Heap h1)
{
    Heap h3(h1.MaxSize+MaxSize);
    for(int i = 0; i < top;i++)
    {
        h3.insert(array[i]);
    }
    for(int i = 0; i < h1.top;i++)
    {
        h3.insert(h1.array[i]);
    }
    adjust(h3.array, 1, h3.Nel);
    return h3;
}


Heap Heap::operator+(int x)
{
    Heap h(MaxSize+1);
    for(int i = 0; i<top; i++) h.insert(array[i]);
    h.insert(x);
    return h;
}

int Heap::operator[](int i)
{
    return array[i];
}

Heap Heap::operator=(Heap h)
{
    return h;
}

Heap Heap::operator+=(Heap h)
{
    array = (int *) realloc(array,MaxSize*sizeof(int));
    for(int i = 1; i <= h.top;i++) insert(h.array[i]);
}

void Heap::operator+=(int x)
{
    insert(x);
}

std::ostream& Heap::operator<< (std::ostream& os) {
    for(int i = 1; i <= top; i++) os<<array[i]<<' ';
    return os;
}
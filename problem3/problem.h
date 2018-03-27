/*
->this file contains the implementation of the third problem of operator overloading
->this file contains a maximum heap implementation with the constructors and destructors needed
->the class contains the prototype function of the class methods and their implementation is right below them
*/
#include <iostream>
#include <cstdlib>
#include <ostream>
#define HEAP_H

using namespace std;
//class definition
class Heap
{
private:
public:
    //class data members
    int * array;
    int MaxSize, Nel, top;
    //class methods prototypes
    void adjust (int a[], int i, int n);
    Heap(int MSize);
    Heap(const Heap& a){}
    bool insert (int item);
    bool delMax(int & item);
    void buildmax();
    Heap operator+(Heap);
    Heap operator+(int x);
    int operator[](int i);
    Heap operator=(Heap);
    Heap operator+=(Heap);
    void operator+=(int x);
    friend std::ostream& operator<< (std::ostream& os, const Heap& h);
    ~Heap(){free(array);};
};

//method that adjusts the heap order
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
//constructor
Heap::Heap(int MSize):MaxSize(MSize)
{
    //allocating array with the max size and initializing it with zero
    array = (int *) calloc(MSize+1,sizeof(int));
    Nel = 0;
}
//method that inserts a new element to the head
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
//method that deletes the maximum element from the heap
bool Heap::delMax(int & item)
{
    if ( !Nel) { cout << "heap is empty" << endl ; return false; }
    top--;
    item = array[1];
    array [1] = array[Nel--];
    adjust (array,1,Nel);
    return true;
}
//method thatbuilds the heap array to be in the form of maximum heap structure
void Heap::buildmax()
{
    int i;
    for(i = top/2; i>=0; i--) adjust(array,i,top+1);
}
//addition operator that adds two heaps together
Heap Heap::operator+(Heap h1)
{
    //creating a new heap
    Heap h3(h1.MaxSize+MaxSize);
    //adding the elements of the first heap to the new heap
    for(int i = 0; i < top;i++)
    {
        h3.insert(array[i]);
    }
    //adding the elements of the second heap to the new heap
    for(int i = 0; i < h1.top;i++)
    {
        h3.insert(h1.array[i]);
    }
    //adjusting the new heap
    adjust(h3.array, 1, h3.Nel);
    //returning the new heap
    return h3;
}

//addition operator that adds a number to the heap
Heap Heap::operator+(int x)
{
    //making an object of the heap that will hold both of the two heaps
    Heap h(MaxSize+1);
    for(int i = 0; i<top; i++) h.insert(array[i]);
    h.insert(x);
    return h;
}
//square bracket operator that accesses a specific element in the heap
int Heap::operator[](int i)
{
    adjust(array,0,top+1);
    buildmax();
    return array[i-1];
}
//assigning opertor
Heap Heap::operator=(Heap h)
{
    return h;
}
//adding a heap to the current heap
Heap Heap::operator+=(Heap h)
{
    //making a bigger array that fits the two heaps
    array = (int *) realloc(array,MaxSize*sizeof(int));
    //inserting the other heap to the heap
    for(int i = 1; i <= h.top;i++) insert(h.array[i]);
}
//adding an element to the current heap
void Heap::operator+=(int x)
{
    //realloc is used to increase the size of the heap and avoid size restrictions
    array = (int *) realloc(array,MaxSize+1);
    //adding the element to the heap
    insert(x);
}
//operator that prnts the heap elements through cout built-in function
std::ostream& operator<< (std::ostream& os, const Heap& h) {
    for(int i = 0; i <= h.top-1; i++) os<<h.array[i]<<' ';
    return os;
}
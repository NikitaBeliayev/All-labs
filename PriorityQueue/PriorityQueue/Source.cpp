#include <iostream>
#include"Element.h"
#include"Queue.h"
using namespace std;
Queue Generate()
{
    Queue mas;
    return mas;
}

int main()
{
    Queue mas;
    mas.Push(1, 1);//inserting a new element
    mas.Push(3, 3);
    mas.Push(2, 2);
    Queue mas1(mas);//demonstration of the copy constructor
    while (!mas1.IsEmpty())//check for emptiness
    {
        mas1.TopInfo();//information about first element
        mas1.Pop();//delete first element
    }
    cout << "Number of elements with priority 2: " << mas.CountOfPriority(2) << endl;//number of elements with a certain priority
    Queue mas3 = Generate();//demonstration of the move constructor
    Queue mas4;
    mas4 = Generate();//demonstration of the move constructor and move operator = 
    cout << "Size: " << mas.Size() << endl;// size of Queue
    mas.Push(4, 2);
    while (!mas.IsEmpty())//check for emptiness
    {
        mas.TopInfo();//information about first element
        mas.Pop();//delete first element
    }
    cout << endl;
    mas.Push(1, 1);
    mas.Push(2, 2);
    mas.Push(3, 3);
    mas.Push(5, 3);
    mas.Erase(3, 3);// remove first element with specific priority and value
    while (!mas.IsEmpty())//check for emptiness
    {
        mas.TopInfo();//information about first element
        mas.Pop();//delete first element
    }
    mas4 = move(mas3);
    return 0;
}
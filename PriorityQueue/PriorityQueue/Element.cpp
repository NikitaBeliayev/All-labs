#include<iostream>
#include "Element.h"
Queue::Element::Element(int data, int priority, Element* next) :priority(priority)
{
    try
    {
        if (priority != 1 && priority != 2 && priority != 3)
        {
            throw std::runtime_error("Wrong value of priority");
        }
    }
    catch (std::runtime_error& err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
    }
    this->data = data;
    this->next = next;
}
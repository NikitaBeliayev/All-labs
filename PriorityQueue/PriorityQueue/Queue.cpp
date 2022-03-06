#include <iostream>
#include <exception>
#include "Queue.h"
#include "Element.h"
class Element;
Queue::Queue()
{
    size = 0;
    head = nullptr;
}


Queue::~Queue()
{
    Clear();
}

Queue::Queue(const Queue& Q)
{
    Clone(Q);
}
Queue::Queue(Queue&& Q) noexcept :head(Q.head), size(Q.size)
{
    Q.head = nullptr;
    Q.size = 0;
}



Queue& Queue::operator=(const Queue& Q)
{
    if (this == &Q)
    {
        return *this;
    }
    else
    {
        Clone(Q);
    }
    return *this;
}


Queue& Queue::operator=(Queue&& Q) noexcept
{
    if (this == &Q)
    {
        return *this;
    }
    this->head = Q.head;
    this->size = Q.size;
    Q.head = nullptr;
    Q.size = 0;
    return *this;
}


void Queue::Push(int data, int priorety)
{
    if (this->head == nullptr)
    {
        this->head = new Element(data, priorety);
    }
    else if (priorety < head->priority)
    {
        this->head = new Element(data, priorety, head);
    }
    else
    {
        Element* current = this->head;
        while (current->next != nullptr && priorety >= current->next->priority)
        {
            current = current->next;
        }
        current->next = new Element(data, priorety, current->next);
    }
    this->size++;
}


bool Queue::IsEmpty() const
{
    return this->size == 0;
}


int Queue::Size() const
{
    return this->size;
}

int Queue::CountOfPriority(int priority) const
{
    Element* current = this->head;
    int counter = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (current->priority == priority)
        {
            counter++;
        }
        current = current->next;
    }
    return counter;
}


void Queue::Pop()
{
    try
    {
        if (this->head == nullptr)
        {
            throw std::runtime_error("Queue is emplty");
        }
        else
        {
            Element* current = this->head;
            this->head = this->head->next;
            delete current;
            this->size--;
        }
    }
    catch (std::runtime_error& err)
    {
        std::cerr << "Error:" << err.what();
    }
}


void Queue::TopInfo() const
{
    if (this->head != nullptr)
    {
        std::cout << "Priority:" << this->head->priority << " Data:" << this->head->data << std::endl;
    }
    else
    {
        std::cout << "Head Element does not exist" << std::endl;
    }
}

void Queue::Erase(int priority, int data)
{
    try
    {
        if (head != nullptr)
        {
            Element* current = this->head;
            if (head->data == data && head->priority == priority)
            {
                Pop();
            }
            else
            {
                while (current->next->data != data && current->next->priority != priority)
                {
                    current = current->next;
                }
                if (current->next->next != nullptr)
                {
                    Element* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                }
                else
                {
                    current->next = nullptr;
                }
                this->size--;
            }
        }
        else
        {
            throw std::runtime_error("Queue is empty");
        }
    }
    catch (std::runtime_error& err)
    {
        std::cerr << "Error:" << err.what();
    }
}


void Queue::Clone(const Queue& Q)
{
    Element* temp = Q.head;
    for (int i = 0; i < Q.size; i++)
    {
        this->Push(temp->data, temp->priority);
        temp = temp->next;
    }
}
void Queue::Clear()
{
    while (this->size != 0)
    {
        Pop();
    }
}
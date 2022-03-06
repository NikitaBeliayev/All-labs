#pragma once
#include"Queue.h"
class Queue::Element
{
public:
	int data;
	Element* next;
	const int priority;
	Queue::Element(int data, int priority = 3, Element* next = nullptr);
};
#pragma once
class Queue
{
private:
	class Element;
	Element* head;
	int size;
	void Clone(const Queue& Q);//Queue cloning
	void Clear();// clearing the Queue
public:
	Queue();// constructor without parameters
	~Queue();// destructor
	Queue(const Queue& Q);// copy constructor
	Queue(Queue&& Q) noexcept;// move constructor
	Queue& operator=(const Queue& Q);// copy assignment operator
	Queue& operator=(Queue&& Q) noexcept;//move assignment operator
	void Push(int data, int priorety = 3);// adding a new element
	bool IsEmpty() const;//check for emptiness
	int Size() const;// Queue size
	int CountOfPriority(int priority) const;// number of elements with a certain priority
	void Pop();//removing the first element
	void TopInfo() const;// information about the first element of the Queue
	void Erase(int priority, int data);
};
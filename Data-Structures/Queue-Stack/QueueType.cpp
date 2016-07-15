#include "QueueType.h"

QueType::QueType()
{
	maxQue = 501;
	front = maxQue - 1;
	rear = maxQue -1;
	items = new ItemType[maxQue];
}

QueType::QueType(int max)
{
	maxQue = max + 1;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new ItemType[maxQue];
}

QueType::~QueType()
{
//	delete [] items;
}

void QueType::MakeEmpty()
{
	front = maxQue - 1;
	rear = maxQue - 1;
}

bool QueType::IsEmpty() const
{
	return (rear == front);
}

bool QueType::IsFull() const
{
	return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
{
	if (this->IsFull())
		throw FullQueue();
	else
	{
		rear = (rear + 1) % maxQue;
		items[rear] = newItem;
	}
}

void QueType::Dequeue(ItemType& item)
{
	if (this->IsEmpty())
		throw EmptyQueue();
	else
	{
		front = (front + 1) % maxQue;
		item = items[front];
	}
}

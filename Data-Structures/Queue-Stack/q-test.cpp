#include "QueueType.h"
#include <iostream>
#include "ItemType.h"

using namespace std;

int GetLength(QueType q)
{
	ItemType item;
	int length = 0;

	while(!q.IsEmpty())
	{
		q.Dequeue(item);
		length++;		
	}	
	return length;
}

int main()
{
	cout << "Starting Progam:\n";
	ItemType item;
	item.Initialize(5);
	QueType q;
	q.Enqueue(item);
	q.Enqueue(item);
	q.Enqueue(item);
	q.Enqueue(item);
	q.Enqueue(item);
	cout << "Items in Q is " << GetLength(q) << ".\n";

	q.Enqueue(item);
	q.Enqueue(item);
	q.Enqueue(item);
	q.Enqueue(item);
	cout << "Items in Q is " << GetLength(q) << ".\n";
	return 0;
}

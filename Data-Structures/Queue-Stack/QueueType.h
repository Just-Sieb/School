#include "ItemType.h"

class FullQueue
{};
class EmptyQueue
{};

class QueType
{
	public:
		QueType(int max);
		QueType();
		~QueType();
		void MakeEmpty();
		bool IsEmpty() const;
		bool IsFull() const;
		void Enqueue(ItemType item);
		void Dequeue(ItemType& item);
	private:
		ItemType* items;
		int maxQue;
		int front;
		int rear;
};

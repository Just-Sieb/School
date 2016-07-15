#include "Stack.h"

StackType::StackType()
{
	top = -1;
}

bool StackType::IsEmpty() const
{
	return (top == -1);
}

bool StackType::IsFull() const
{
	return (top == 499);
}

void StackType::Push(symbol newItem)
{
	if(IsFull())
		throw FullStack();
	top++;
	items[top] = newItem;
}

void StackType::Pop()
{
	if(IsEmpty())
		throw EmptyStack();
	top--;
}

symbol StackType::Top() const
{
	if(IsEmpty())
		throw EmptyStack();
	return items[top];
}

#pragma once
#include "ItemType.h"

enum symbol {square, comment, curly, parenthesis, quote, doublequote};

class FullStack
{};

class EmptyStack
{};

class StackType
{
	public:
		StackType();
		bool IsEmpty() const;
		bool IsFull() const;
		void Push(symbol item);
		void Pop();
		symbol Top() const;
	private:
		int top;
		symbol items[500];
};

#include "balancing-symbols.h"

using namespace std;

void BalancingSymbols::checkIfBalanced(symbol sym)
{
	if(symStack.Top() == sym)
		symStack.Pop();
	else if(symStack.Top() == quote || symStack.Top() == doublequote)
		{}
	else
		displayError(sym);
}

int BalancingSymbols::getLineOfError()
{
	charPos = file.tellg();
	file.seekg(0);
	bool found = false;
	int currLineNum = 0;
	int prevLineNum = 0;	

	while(!found)
	{
		file.getline(line, 256);
		lineNumber++;
		prevLineNum = currLineNum;
		currLineNum = file.tellg();


		if( currLineNum >= charPos)
		{
			found = true;
			return (lineNumber - 1);
		}	
	}
	return -1; 
}

void BalancingSymbols::displayError(symbol sym)
{
	int lineOfError = getLineOfError();
	cout << "The error occurs around line " << lineOfError << ".\n";
	cout << "You are missing either a " << PrintSym(sym) << " or a " << PrintSym(symStack.Top()) << " bracket.\n";
}

BalancingSymbols::BalancingSymbols(string filename)
{
	file.open(filename);	

	if(!file.is_open())
	{
		cout << "Could Not Open File.\n";
	}
	else
	{
		while(file.get(c))
		{
			switch(c)
			{
				case '/':
					file.get(c);
					if(c == '*')
						symStack.Push(comment);	
					break;
				case '[':
					symStack.Push(square);
					break;
				case '{':
					symStack.Push(curly);
					break;
				case '(':
					symStack.Push(parenthesis);
					break;
				case '*':
					file.get(c);
					if(c == '/')
						checkIfBalanced(comment);			
					break;
				case ']':
					checkIfBalanced(square);
					break;
				case '}':
					checkIfBalanced(curly);
					break;
				case ')':
					checkIfBalanced(parenthesis);
					break;	
				case '\'':
					if(!symStack.IsEmpty())
						if(symStack.Top() == quote)
							symStack.Pop();
					else
						symStack.Push(quote);
					break;
				case '"':
					if(!symStack.IsEmpty())
						if(symStack.Top() == doublequote)
							symStack.Pop();
					else
						symStack.Push(doublequote);
					break;
			}
		}
	}

	file.close();
}

string BalancingSymbols::PrintSym(symbol sym)
{
	switch(sym)
	{
		case comment:
			return "multiline comment symbol";
		case square:
			return "square bracket";
		case curly:
			return "curly bracket";
		case parenthesis:
			return "parenthesis";
	}
}

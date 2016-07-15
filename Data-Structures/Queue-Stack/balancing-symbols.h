#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Stack.h"
#include <iostream>

class BalancingSymbols
{
	public:
		BalancingSymbols(std::string filename);
	private:
		StackType symStack;
		std::ifstream file;	
		int lineNumber = 0;
		int charPos;
		char c;	
		char line[256];
		int getLineOfError();
		void displayError(symbol sym);
		void checkIfBalanced(symbol sym);
		std::string PrintSym(symbol sym);
};

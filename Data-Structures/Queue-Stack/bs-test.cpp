#include "balancing-symbols.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string fileName;
	cout << "Enter name of the file: ";
	cin >> fileName;

	cout << "Starting the scanning of the file.\n";

	BalancingSymbols file(fileName);

	cout << "Finished the scanning.\n";	

	return 0;
}

#include<iostream>
#include "Serials.h"
using namespace std;

int main() {
	init();
	int action = 0;

	do
	{
		cout << "1. Add new serial" << endl;
		cout << "2. Show all serials" << endl;
		cout << "3. Search serials" << endl;
		cout << "4. Exit" << endl;
		cout << endl;
		cout << "Select action from list ->_";
		cin >> action;

		switch (action)
		{
			case 1: {
				add();
			}break;

			case 2: {
				show();
			}break;
				
			case 3: {
				search();
			}break;

			case 4: {
				cout << "Goodbye" << endl;
			}break;
			
			default: {
				cout << "Error: Please, select action only from list" << endl;
			}break;
		}
	} while (action!=4);

	return 0;
}
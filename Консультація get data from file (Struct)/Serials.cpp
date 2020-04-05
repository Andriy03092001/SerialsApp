#include "Serials.h"
#include<iostream>
#include<fstream>
#include<string>

Serial* list;
const string fileName = "data.txt";
int countSerials = 0;

//C - create
//R - read
//U - update
//D - delete

void insert(Serial data)
{
	Serial* temp = new Serial[countSerials + 1];
	for (int i = 0; i < countSerials; i++)
	{
		temp[i] = list[i];
	}
	temp[countSerials] = data;
	countSerials++;
	list = new Serial[countSerials];
	for (int i = 0; i < countSerials; i++)
	{
		list[i] = temp[i];
	}
	delete[]temp;
}

void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			Serial temp;
			fin.ignore();
			getline(fin,temp.Name);
			if (temp.Name != "") {
				fin >> temp.Genre;
				fin >> temp.Country;
				fin >> temp.startPresent.day;
				fin >> temp.startPresent.month;
				fin >> temp.startPresent.year;
				insert(temp);
			}
			else{
				break;
			}

		}
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}

void add()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {

		Serial newSerial;
		cout << "Enter title serial->_";
		cin >> newSerial.Name;
		cout << "Enter genre serial->_";
		cin >> newSerial.Genre;
		cout << "Enter country serial->_";
		cin >> newSerial.Country;
		cout << "Start serial:" << endl;
		cout << "Enter day->_";
		cin >> newSerial.startPresent.day;
		cout << "Enter month->_";
		cin >> newSerial.startPresent.month;
		cout << "Enter year->_";
		cin >> newSerial.startPresent.year;

		insert(newSerial);
		fout << newSerial.Name << endl;
		fout << newSerial.Genre << endl;
		fout << newSerial.Country << endl;
		fout << newSerial.startPresent.day << endl;
		fout << newSerial.startPresent.month << endl;
		fout << newSerial.startPresent.year << endl;
		fout.close();
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}

void show()
{
	for (int i = 0; i < countSerials; i++)
	{
		cout << "Title: " << list[i].Name << endl;
	}
}

void search()
{
	string text;
	cout << "Enter text from search ->_";
	cin >> text; //Arrow
	for (int i = 0; i < countSerials; i++)
	{
		if (list[i].Name.find(text) != string::npos) {
			cout << "Title: " << list[i].Name << endl;
		}
	}

}
 
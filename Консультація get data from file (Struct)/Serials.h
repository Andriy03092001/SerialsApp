#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Date {
	int day;
	string month;
	int year;
};

struct Serial{
	string Name;
	string Genre;
	Date startPresent;
	string Country;
};

void init();
void add();
void show();
void insert(Serial data);
void search();
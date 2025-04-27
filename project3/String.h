#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class String
{
public:
	string str;
	String();
	String(const string&);
	String(const String& other);
	void loadfile(const string&);
	void writeResultsToFile(const string&, vector<string>);
	friend ostream& operator<<(ostream&, const String&);
	string getStr();
	vector<string> Chisla();
};


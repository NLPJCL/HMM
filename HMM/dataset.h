#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"sentence.h"
using namespace std;
class dataset
{
public:
	vector<sentence> sentences;
	string name;
	void read_data(const string &file_name);
	dataset();
	~dataset();
};


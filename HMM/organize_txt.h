#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void organize_txt(string file)
{
	ifstream file1(file+".conll.txt");
	if (!file1)
	{
		cout << "don't open dev file" << endl;
	}
	ofstream file_word(file+".word.txt");
	if(!file_word)
	{
		cout << "don't open dev.word file" << endl;
	}	
	ofstream file_class(file+".class.txt");
	if (!file_word)
	{
		cout << "don't open dev.class file" << endl;
	}
	string line, line_word, line_class;
	while (getline(file1, line))
	{
		if (line.size() == 0)
		{
			file_word << line_word << endl;
			file_class << line_class << endl;
			line_word.clear();
			line_class.clear(); continue;
		}
		int t0 = line.find("\t")+1;
		int t1 = line.find("\t", t0);
		line_word += line.substr(t0, t1 - t0)+"_";
		int t2 = line.find("\t", t1 + 1)+1;
		int t3 = line.find("\t", t2);
		line_class += line.substr(t2, t3 - t2)+"_";
	}


}


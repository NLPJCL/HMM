#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void appraise(string file)
{
	ifstream file1(file + ".class.txt");
	if (!file1)
	{
		cout << "don't open dev file" << endl;
	}
	ifstream file2("labe_" + file + "_class.txt");
	if (!file1)
	{
		cout << "don't open labe_dev_class file" << endl;
	}
	long long all = 0;
	long long correct=0;
	string line, line1, word_class, word1_class;
	while (getline(file1, line) && getline(file2, line1))
	{
		while (line.size() != 0)
		{
			int i = line.find("_");
			word_class = line.substr(0, i);//取单个字符串。
			line.erase(0, i + 1);//删除字符串。
			int i1 = line1.find("_");
			word1_class = line1.substr(0, i);//取单个字符串。
			line1.erase(0, i + 1);//删除字符串。
			if (word_class == word1_class)
			{
				correct++;
			}
			all++;
		}
	}
	cout << "标注词性的准确率为" <<correct<<"/"<<all<<"="<< correct / double(all);
}
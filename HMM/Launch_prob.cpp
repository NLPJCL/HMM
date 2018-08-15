#include "Launch_prob.h"
#include"iostream"
#include<fstream>
using namespace std;
void Launch_prob::count_launch()
{
	ifstream data("train.conll.txt");
	if (!data)
	{
		cout << "don't open transfer files" << endl;
		return;
	}
	string line;
	//平滑数据 
	map<string, int> allword;
	while (getline(data, line))
	{	
		if (line.size() == 0 )continue;
		int t0 = line.find('\t');
		int t1 = line.find('\t', t0 + 1);
		string w = line.substr(t0 + 1, t1 - t0 - 1);
		int t2=line.find('\t', t1 + 1);
		int t3 = line.find('\t', t2 + 1);
		string t = line.substr(t2 + 1, t3-t2 - 1);
		launch[w + " " + t]++;
		all_wordclass[t]++;
		allword[w]++;
	}
	for (auto z = allword.begin(); z != allword.end(); z++)
	{
		all++;
	}
}
void Launch_prob::count_launch_prob()
{
	string word, word_class, former;
	map<string, double> other;
	map<string, int> z;//检测是否储存过？
	for (auto w0 = launch.begin(); w0 != launch.end(); w0++)
	{
		int t0 = w0->first.find(" ");
		word = w0->first.substr(0, t0);
		word_class = w0->first.substr(t0+1);
		if (z.find(word) == z.end())//没存储过
		{
			z[word]++;
			for (auto z = all_wordclass.begin(); z != all_wordclass.end(); z++)
			{
				if (other.find(z->first) == other.end())
				{
					other[z->first] = 1/ double(z->second + all);
				}
			}
			launch_prob[former] = other;
			other.clear();
		}
		if (z.find(word) != z.end())
		{
			other[word_class] = (w0->second)/( double(all_wordclass[word_class])+all);
		}
		former = word;
	}
	launch_prob[former] = other;
	//处理未登录词。
	other.clear();
	for (auto z = all_wordclass.begin(); z != all_wordclass.end(); z++)
	{
		other[z->first] = 1/ double(z->second + all);
	}
	launch_prob["**"] = other;
}

#pragma once
#ifndef MY_HEADER_H
#define MY_HEADER_H
#include<iostream>
#include<string>
#include<map>
#include<fstream>
using namespace std;
class first_transfer
{
public:
	first_transfer()
	{
		first();
		other();
		count_transfer();
	}
	map<string, map<string, double>> transfer;//key为当前词性，键值的key为前一个词性，键值的键值为转移概率。
private:
	//第一个词性的概率求解东西。
	map<string, int> first_word;
	double first_all = 0.0;
	void first();//统计每一句第一个词性的频数。
	//其他词性的转移概率的求解东西。
	map<string, double> all_word;
	map<string, int> sequent_word;//第一个是当前词性，第二个是前一个词性和当前词性的总个数。
	void other();//统计除了每一句第一个词性的频数。
	//总的转移概率的存储结构
	//map<string, map<string,double>> transfer;//key为当前词性，键值的key为前一个词性，键值的键值为转移概率。
	void count_transfer();
	map<string, double> transfer_prob;//string分为两部分第一个是当前词性，第二个是前一个词性。最后一个是double概率。
	void  count_transfer1();
};
#endif


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
	map<string, map<string, double>> transfer;//keyΪ��ǰ���ԣ���ֵ��keyΪǰһ�����ԣ���ֵ�ļ�ֵΪת�Ƹ��ʡ�
private:
	//��һ�����Եĸ�����ⶫ����
	map<string, int> first_word;
	double first_all = 0.0;
	void first();//ͳ��ÿһ���һ�����Ե�Ƶ����
	//�������Ե�ת�Ƹ��ʵ���ⶫ����
	map<string, double> all_word;
	map<string, int> sequent_word;//��һ���ǵ�ǰ���ԣ��ڶ�����ǰһ�����Ժ͵�ǰ���Ե��ܸ�����
	void other();//ͳ�Ƴ���ÿһ���һ�����Ե�Ƶ����
	//�ܵ�ת�Ƹ��ʵĴ洢�ṹ
	//map<string, map<string,double>> transfer;//keyΪ��ǰ���ԣ���ֵ��keyΪǰһ�����ԣ���ֵ�ļ�ֵΪת�Ƹ��ʡ�
	void count_transfer();
	map<string, double> transfer_prob;//string��Ϊ�����ֵ�һ���ǵ�ǰ���ԣ��ڶ�����ǰһ�����ԡ����һ����double���ʡ�
	void  count_transfer1();
};
#endif


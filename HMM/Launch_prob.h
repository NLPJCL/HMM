#pragma once
#include<map>
#include<string>
using namespace std;
class Launch_prob
{
public:
	Launch_prob()
	{
		count_launch();
		count_launch_prob();
	}
	map<string, map<string, double>> launch_prob;
private:
	void count_launch();
	void count_launch_prob();
	std::map<std::string, int> all_wordclass;//�ܵĴ��Եĸ�����
	std::map<std::string, int> launch;//���������
	int all=0;//ƽ���ķ�ĸ  //ȥ�غ�Ĵ��Ը�����
};


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
	std::map<std::string, int> all_wordclass;//总的词性的个数。
	std::map<std::string, int> launch;//发射个数。
	int all=0;//平滑的分母  //去重后的词性个数。
};


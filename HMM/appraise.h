#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"dataset.h"
#include<vector>
using namespace std;
void appraise(vector<vector<string>> tag_class ,dataset sens)
{
	int i = 0, j = 0, c = 0, all = 0;
	for (auto z = sens.sentences.begin(); z != sens.sentences.end(); z++)
	{
		for (auto z0 = z->tag.begin(); z0 != z->tag.end(); z0++)
		{
			if (tag_class[i][j]== *z0)
			{
				c++;
			}
			all++;
			j++;
		}
		j = 0;
		i++;
	}

	cout << "��ע���Ե�׼ȷ��Ϊ" << c << "/" << all << "=" << c / double(all) << endl;
}
#pragma once
#include"first_transfer.h"
#include"Launch_prob.h"
#include"organize_txt.h"
class list_prob
{
public:
	string list;
	double prob;
};
void viterbi(string file)
{
			   first_transfer a;//转移概率
			   Launch_prob b;//发射概率
			   organize_txt(file);//整理文本
			   ifstream file_word(file+".word.txt");
			   if(!file_word)
			   {
				 cout << "don't open dev_word file" << endl;
			   }
			   string line, word;
			   
			   ofstream file_wordclass("labe_"+file+"_class.txt");
			   if (!file_wordclass)
			   {
				cout << "don't open dev_word file" << endl;
			   }
			   while (getline(file_word, line))
			   {
					int t = 0;
				    map<string, list_prob> list;
					map<string, list_prob> t3;
				   while (line.size() != 0)
				   {
						   int i = line.find("_");
						   word = line.substr(0, i);//取单个字符串。
						   line.erase(0, i + 1);//删除字符串。
						   if (t == 0)
						   {
								auto w = b.launch_prob.find(word);
								if (w == b.launch_prob.end())
								{
									w = b.launch_prob.find("**");
								}
							   //遍历发射概率。
							   for (auto w0 = w->second.begin(); w0 != w->second.end(); w0++)//w0是发射概率second（状态量）。
							   {
								   //找对应的转移概率的初始状态。
								   auto w1 = a.transfer.find(w0->first);
								   auto w2 = w1->second.find("start");//w2是转移概率的second;
								   if (w2 != w1->second.end())//如果对应状态在初试概率中，w1是转移概率的first。
								   {
									   list_prob t4;
									   t4.list = w0->first;
									   t4.prob = w0->second*w2->second;//发射概率*初始转移概率。
									   t3[w0->first] = t4;
								   }
							   }
								 t++;
							}
						   else
						   {
							   auto w = b.launch_prob.find(word);
							   if (w == b.launch_prob.end())
							   {
							   w = b.launch_prob.find("**");
							   }
							   //遍历发射概率。
							   for (auto w0 = w->second.begin(); w0 != w->second.end(); w0++)//w0是发射概率second（状态量）。
							   {
								   auto w1 = a.transfer.find(w0->first);//w1是转移概率的first;
								   //遍历之前的序列。
								   int q = 0;
								   for (auto w2 = t3.begin(); w2 != t3.end(); w2++)
								   {
									   auto w3 = w1->second.find(w2->first);//w3是转移概率里面对应前一个词性。
									   if (w3 != w1->second.end())//如果前一个状态在转移概率里面存在.
									   {
										   if (q == 0)
										   {
										   list_prob t4;
										   t4.list = w2->second.list + "_" + w0->first;
										   t4.prob = w0->second*w2->second.prob*w3->second;//发射概率*前一串序列的概率*从前一个序列到当前序列的转移概率。
										   list[w0->first] = t4;
										   q++;
										   }
										   else
										   {
											   list_prob t4;
											   t4.prob = w0->second*w2->second.prob*w3->second;//发射概率*前一串序列的概率*从前一个序列到当前序列的转移概率。
											   if (t4.prob > list[w0->first].prob)
											   {
												   t4.list = w2->second.list + "_" + w0->first;
												   list[w0->first] = t4;
											   }

										   }
									   }
								   }
							   }
							   t3 = list;
							   list.clear();
						   }
					   }
				   string q;
				   double p=0.0;
				   for (auto z = t3.begin(); z != t3.end(); z++)
				   {
						if (z->second.prob > p)
						{
						   q = z->second.list;
						   p = z->second.prob;
						}
				   }
				  file_wordclass << q+"_" << endl;
			   }
				return ;
}

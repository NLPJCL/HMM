#pragma once
#include"first_transfer.h"
#include"Launch_prob.h"
#include"dataset.h"
#include"appraise.h"
class list_prob
{
public:
	vector<string> tags;
	long double prob;
};
void viterbi(string file)
{
			   first_transfer a;//转移概率
			   Launch_prob b;//发射概率
			   dataset c;
			   c.read_data(file);
			   vector<vector<string>> tag_class;
			   double correct= 0;
			   double all = 0;
			   for (auto z = c.sentences.begin(); z != c.sentences.end(); z++)
			   {
				   int t = 0;
				   map<string, list_prob> list;
				   map<string, list_prob> t3;
				   for (auto word = z->word.begin(); word != z->word.end(); word++)
				   {

					   if (t == 0)
					   {
						   auto w = b.launch_prob.find(*word);
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
								   t4.tags.push_back(w0->first);
								   t4.prob = w0->second*w2->second;//发射概率*初始转移概率。
								   t3[w0->first] = t4;
							   }
						   }
						   t++;
					   }
					   else
					   {
						   auto w = b.launch_prob.find(*word);
						   if (w == b.launch_prob.end())
						   {
							   w = b.launch_prob.find("**");
						   }
						   //遍历发射概率。
						   for (auto w0 = w->second.begin(); w0 != w->second.end(); w0++)//w0是发射概率second（状态量）。
						   {
							   auto w1 = a.transfer.find(w0->first);//w1是转移概率的first;
							   //遍历之前的序列。
							   long double max_prob = 0.0;
							   list_prob t4;
							   for (auto w2 = t3.begin(); w2 != t3.end(); w2++)
							   {
								   auto w3 = w1->second.find(w2->first);//w3是转移概率里面对应前一个词性。
								   if (w3 != w1->second.end())//如果前一个状态在转移概率里面存在.
								   {
									   t4.prob = w0->second*w2->second.prob*w3->second;//发射概率*前一串序列的概率*从前一个序列到当前序列的转移概率。
									   if (t4.prob >= max_prob)
									   {
										   max_prob = t4.prob;
										   t4.tags = w2->second.tags;
										   t4.tags.push_back(w0->first);
										   list[w0->first] = t4;
									   }

								   }
							   }
						   }
						   t3 = list;
						   list.clear();
					   }
				   }
				   vector<string> tags;
				   long double max_prob=0.0;
				   for (auto z = t3.begin(); z != t3.end(); z++)
				   {
						if (z->second.prob >= max_prob)
						{
						   tags = z->second.tags;
						   max_prob= z->second.prob;
						}
				   }
				   tag_class.push_back(tags);
				   /*
				   if (z->tag.size() != tags.size())
				   {
					   for (int i = 0; i < z->word.size(); i++)
					   {
						   cout << z->word[i];
					   }
					   cout << endl;
					   for (int i = 0; i < tags.size(); i++)
					   {
						   cout << tags[i];
					   }
					   cout << endl;
					   cout << tags.size() << endl;
					   auto z = t3.begin();
					   cout<<z->second.prob << endl;
				   }
				  */
				   for (int i = 0; i< z->tag.size(); i++)
				   {
					   if (z->tag[i] == tags[i])
					   {
						   correct++;
					   }
					   all++;;
				   }
			   }
			   cout << "标注词性的准确率为" << correct<< "/" << all << "=" << correct / double(all);


			   //appraise(tag_class, c);
}

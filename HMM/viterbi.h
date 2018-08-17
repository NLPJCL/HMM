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
			   first_transfer a;//ת�Ƹ���
			   Launch_prob b;//�������
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
						   //����������ʡ�
						   for (auto w0 = w->second.begin(); w0 != w->second.end(); w0++)//w0�Ƿ������second��״̬������
						   {
							   //�Ҷ�Ӧ��ת�Ƹ��ʵĳ�ʼ״̬��
							   auto w1 = a.transfer.find(w0->first);
							   auto w2 = w1->second.find("start");//w2��ת�Ƹ��ʵ�second;
							   if (w2 != w1->second.end())//�����Ӧ״̬�ڳ��Ը����У�w1��ת�Ƹ��ʵ�first��
							   {
								   list_prob t4;
								   t4.tags.push_back(w0->first);
								   t4.prob = w0->second*w2->second;//�������*��ʼת�Ƹ��ʡ�
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
						   //����������ʡ�
						   for (auto w0 = w->second.begin(); w0 != w->second.end(); w0++)//w0�Ƿ������second��״̬������
						   {
							   auto w1 = a.transfer.find(w0->first);//w1��ת�Ƹ��ʵ�first;
							   //����֮ǰ�����С�
							   long double max_prob = 0.0;
							   list_prob t4;
							   for (auto w2 = t3.begin(); w2 != t3.end(); w2++)
							   {
								   auto w3 = w1->second.find(w2->first);//w3��ת�Ƹ��������Ӧǰһ�����ԡ�
								   if (w3 != w1->second.end())//���ǰһ��״̬��ת�Ƹ����������.
								   {
									   t4.prob = w0->second*w2->second.prob*w3->second;//�������*ǰһ�����еĸ���*��ǰһ�����е���ǰ���е�ת�Ƹ��ʡ�
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
			   cout << "��ע���Ե�׼ȷ��Ϊ" << correct<< "/" << all << "=" << correct / double(all);


			   //appraise(tag_class, c);
}

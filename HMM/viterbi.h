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
			   first_transfer a;//ת�Ƹ���
			   Launch_prob b;//�������
			   organize_txt(file);//�����ı�
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
						   word = line.substr(0, i);//ȡ�����ַ�����
						   line.erase(0, i + 1);//ɾ���ַ�����
						   if (t == 0)
						   {
								auto w = b.launch_prob.find(word);
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
									   t4.list = w0->first;
									   t4.prob = w0->second*w2->second;//�������*��ʼת�Ƹ��ʡ�
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
							   //����������ʡ�
							   for (auto w0 = w->second.begin(); w0 != w->second.end(); w0++)//w0�Ƿ������second��״̬������
							   {
								   auto w1 = a.transfer.find(w0->first);//w1��ת�Ƹ��ʵ�first;
								   //����֮ǰ�����С�
								   int q = 0;
								   for (auto w2 = t3.begin(); w2 != t3.end(); w2++)
								   {
									   auto w3 = w1->second.find(w2->first);//w3��ת�Ƹ��������Ӧǰһ�����ԡ�
									   if (w3 != w1->second.end())//���ǰһ��״̬��ת�Ƹ����������.
									   {
										   if (q == 0)
										   {
										   list_prob t4;
										   t4.list = w2->second.list + "_" + w0->first;
										   t4.prob = w0->second*w2->second.prob*w3->second;//�������*ǰһ�����еĸ���*��ǰһ�����е���ǰ���е�ת�Ƹ��ʡ�
										   list[w0->first] = t4;
										   q++;
										   }
										   else
										   {
											   list_prob t4;
											   t4.prob = w0->second*w2->second.prob*w3->second;//�������*ǰһ�����еĸ���*��ǰһ�����е���ǰ���е�ת�Ƹ��ʡ�
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

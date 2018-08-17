#include "first_transfer.h"
//ͳ��ÿһ���һ�����Ե�Ƶ����
void first_transfer::first()
{
	ifstream transfer("train.conll.txt");
	if (!transfer)
	{
		cout << "don't open transfer files" << endl;
		return;
	}
	string line, word_class;
	int t1 = 0, t2 = 0, t3 = 0;
	while (getline(transfer, line, '\n'))
	{
		if (line[0] == '1'&&line[1] == '\t')
		{
			t1 = line.find("_");
			t2 = line.find("\t", t1) + 1;
			t3 = line.find("\t", t2);
			word_class = line.substr(t2, t3 - t2);
			first_word[word_class]++;
			first_all++;
		}
	}
	/*
	//���Դ��롣������еĵ�һ�����Ժ���Ƶ����
	for (auto a = first_word.begin(); a != first_word.end(); a++)
	{
	cout << a->first << "\t" << a->second << endl;
	}
	*/
}
//ͳ�Ƴ���ÿһ���һ�����Ե�Ƶ����
void first_transfer::other()
{
	ifstream transfer("train.conll.txt");
	if (!transfer)
	{
		cout << "don't open transfer files" << endl;
		return;
	}
	string line,former_class, word_class;
	while (getline(transfer, line))
	{
		//������е����
		if (line.size() == 0)
		{
			all_word[former_class]--;//��ȥһ�仰�����һ���ʵĴ��ԡ�
			former_class="";
			continue;
		}
		int t = 0, q0, q1, q2;
		q0= line.find("_");
		q1 = line.find("\t", q0)+1;
		q2 = line.find("\t", q1);
		word_class = line.substr(q1, q2 - q1);
		if (former_class.size() != 0)
		{
			sequent_word[word_class + "/" + former_class]++;
		}
		former_class = word_class;
		all_word[word_class]++;
	}
	/*
	//���Դ���  ��������Ĵ������м���Ƶ����
	for (auto q = sequent_word.begin(); q != sequent_word.end(); q++)
	{
		cout << q->first << ":" << q->second << endl;
	}
	*/
}
//����ת�Ƹ��ʡ�
void first_transfer::count_transfer()
{
	//�����������Ե�ת�Ƹ��ʡ�
	string word_class, former_class, former;
	map<string, double> other, z;
	//map��key������ģ����Ը��������map���洢��
	for (auto t1 = sequent_word.begin(); t1 != sequent_word.end(); t1++)
	{

		int t2 = t1->first.find('/');
		word_class = t1->first.substr(0, t2);
		former_class = t1->first.substr(t2 + 1);
		if (z.find(word_class) == z.end())//û�洢��
		{
			z[word_class]++;
			if (first_word.find(former) != first_word.end())//�ѵ�һ����������ϣ�
			{
				auto w = first_word.find(former);
				other["start"] = w->second / first_all;
			}
			transfer[former] = other;
			other.clear();
		}
		if (z.find(word_class) != z.end())
		{
			other[former_class] = t1->second / all_word[former_class];
		}
		former = word_class;
	}
	//�����һ����������ϡ�
	if (first_word.find(former) != first_word.end())
	{
		auto w = first_word.find(former);
		other["start"] = w->second / first_all;
	}
	transfer[former] = other;
	//�ѵ�һ�����Լӽ�ȥ��
	for (auto z = first_word.begin(); z != first_word.end(); z++)
	{
		if (transfer.find(z->first) == transfer.end())
		{
			map<string, double> other;
			other["start"] = z->second / first_all;
			transfer[z->first] = other;
		}
	}
	/*
	//���Դ��룬  ����һ��s2���ԣ�������ĺ�һ�����Լ�������Լ����ĺ�һ�����Ե��ܸ���Ϊ1
	for (auto z = all_word.begin(); z != all_word.end(); z++)
	{
		string s2 = z->first;
		double all2 = 0.0;
		auto c = transfer.begin();
		auto w = transfer.begin();
		while (c != transfer.end())
		{
			auto a = c->second.begin();
			while (a != c->second.end())
			{
				if (a->first == s2)
				{
					cout << s2 << "->" << c->first << ":\t" << a->second << endl;
					all2 += a->second;
				}
				//cout << c->first << "->" << a->first << endl;
				a++;
			}
			c++;
		}
		cout << all2 << endl;
	}
	*/
}
	//��һ��д�ķ�������ת�Ƹ��ʡ�
	/*
		//�����һ�����Ե�ת�Ƹ���
	map<string, double> strat_p;
	double all = 0;
	for (auto t0 = first_word.begin(); t0 != first_word.end(); t0++)
	{
		strat_p["start"] = t0->second / first_all;
		transfer[t0->first] = strat_p;
		//cout << t0->first << "->" << t0->second / first_all << endl;
		//all = all + t0->second / first_all;
	}
	//cout << all << endl;
	//�����������ֵ�ת�Ƹ���
	string word_class, former_class, s1;
	map<string, double> other_p;
	double lo = 0;
	for (auto t1 = sequent_word.begin(); t1 != sequent_word.end(); t1++)
	{
		//���������
		int t3 = t1->first.find('/');
		word_class = t1->first.substr(0, t3);
		former_class = t1->first.substr(t3 + 1);
		//��ת�Ƹ���
		if (s1 != word_class && s1.size() != 0)
		{
			auto t = transfer.find(s1);
			if (transfer.find(s1) != transfer.end())
			{
				auto q = (t->second).find("start");
				if (q != (t->second).end())
				{
					other_p["start"] = q->second;
				}
			}
			transfer[s1] = other_p;
			s1 = "";
			other_p.erase(other_p.begin(), other_p.end());
			map<string, double> other_p;
		}
		other_p[former_class] = t1->second / all_word[former_class];
		s1 = word_class;
		// cout << former_class << "->" << word_class<<":"<< t1->second / all_word[former_class] << endl;
	}
	 double all2 = 0.0;
	auto c = transfer.begin();
	auto w = transfer.begin();
	string s2 = "PU";
	while (c != transfer.end())
	{
		auto a = c->second.begin();
		while (a != c->second.end())
		{
			if (a->first == s2)
			{
				cout << s2 << "->" << c->first << ":\t" << a->second << endl;
				all2 += a->second;
			}
			//cout << c->first << "->" << a->first << endl;
			a++;
		}
		c++;
	}
	cout << all2 << endl;
}
*/

//�ڶ������ݽṹ��ת�Ƹ����󷨡�
void  first_transfer::count_transfer1()
{
	//�����һ�����Ե�ת�Ƹ��ʡ�
	for (auto t0 = first_word.begin(); t0 != first_word.end(); t0++)
	{
		string s = t0->first + "/" + "start";
		transfer_prob[s] = t0->second / first_all;
	}
	//����
	double all = 0.0;
	auto q = transfer_prob.begin();
	while (q != transfer_prob.end())
	{
		cout << q->first << q->second << endl;
		all += q->second;
		q++;
	}
	cout << all << endl;

	//�����������Ե�ת�Ƹ��ʡ�
	string word_class, former_class;
	for (auto t1 = sequent_word.begin(); t1 != sequent_word.end(); t1++)
	{
		int t2 = t1->first.find('/');
		word_class = t1->first.substr(0, t2);
		former_class = t1->first.substr(t2 + 1);
		transfer_prob[t1->first] = t1->second / all_word[former_class];
	}
	//����
	map<string, double> c;
	for (auto t3 = transfer_prob.begin(); t3 != transfer_prob.end(); t3++)
	{
		int t2 = t3->first.find('/');
		former_class = t3->first.substr(t2 + 1);
		c[former_class] += t3->second;
	}
	double all2 = 0.0;
	auto t4 = c.begin();
	while (t4 != c.end())
	{
		all2++;
		cout << t4->first << t4->second << endl;
		t4++;
	}
	cout << all2 << endl;
}



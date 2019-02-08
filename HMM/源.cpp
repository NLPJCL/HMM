//#include"viterbi.h"//viterbi算法。
#include"windows.h"
#include <locale>   
#include <codecvt>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
namespace test_wstring
{
	void test()
	{
		wcout.imbue(locale("chs"));

		wstring a = L"你好";
		wcout << a << endl;
		wcout << sizeof(a) << endl;
		wcout << a.size() << endl;


		wcout << a[0] << endl;
		wcout << a[1] << endl;
		wcout << a[2] << endl;
		string a0 = "你好";
		cout << sizeof(a0) << endl;
	}
	void convert()
	{
		std::wstring str = L"我是中国人1，,;；。";

		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;


		ifstream ofd("test.txt");

		string line;	
		getline(ofd,line);
		cout << line << endl;
//		wcout.imbue(locale("chs"));

		std::wstring wideStr = conv.from_bytes(line);

//		std::locale::global(std::locale("Chinese-simplified"));

		cout << wideStr.size() << endl;
		for (int i = 0; i < wideStr.size(); i++)
		{
			wcout << wideStr[i] << endl;
		}

		/*
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;

		std::string narrowStr = conv.to_bytes(str);
		{
			std::ofstream ofs("test.txt");
			ofs << narrowStr;
			cout << narrowStr << endl;
		}

		std::wstring wideStr = conv.from_bytes(narrowStr);
		{
			std::locale::global(std::locale("Chinese-simplified"));
			std::wofstream ofs(L"testW.txt");
			ofs << wideStr;
			wcout << wideStr[1] << endl;

		}
		*/
			/*

		wcout.imbue(locale("chs"));

		ifstream out("123.txt");
		if (out)
		{

			cout << "open" << endl;
		}
		string line;


		getline(out, line);
		std::wstring_convert<std::codecvt_utf8<wchar_t >> codec;
		wstring a( codec.from_bytes(line));
		
		/*
		wcout.imbue(locale(locale(), "", LC_CTYPE));
		cout << a.length();

		wcout << a << endl;

		/*
		for (int i = 0; i < a.size(); i++)
		{
			cout << "1";
			wcout << a[i] << " 1";
		}
		*/





	}



}

#include"HMMPosTag.h"
#include<map>
int main()
{

	std::vector<std::wstring> words;
	DWORD t1, t2;
	t1 = timeGetTime();
	double alpha = 0.0090;
	HMMPosTag hmm;
	hmm.fit("train.conll.txt",alpha);
	//hmm.appraise("test.conll.txt"); //对测试集的评价。
	hmm.pos_tag(words);
	t2 = timeGetTime();
	cout << "Use Time:" << (t2 - t1)*1.0 / 1000 << endl;







//	test_wstring::test();
//	test_wstring::convert();
	

	/*
	DWORD t1, t2;
	t1 = timeGetTime();
	viterbi("train");
	t2 = timeGetTime();
	cout << "Use Time:" << (t2 - t1)*1.0 / 1000 << endl;
	*/
	system("pause");
	
	return 0;
}


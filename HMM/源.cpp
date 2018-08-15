#include"organize_txt.h"//整理文本。
#include"appraise.h"//评价程序。
#include"viterbi.h"//viterbi算法。
int main()
{
	viterbi("dev");
	appraise("dev");//评价程序。
	system("pause");
	return 0;
}


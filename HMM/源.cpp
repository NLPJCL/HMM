#include"viterbi.h"//viterbiÀ„∑®°£
#include"windows.h"
int main()
{
	DWORD t1, t2;
	t1 = timeGetTime();
	viterbi("dev");
	t2 = timeGetTime();
	cout << "Use Time:" << (t2 - t1)*1.0 / 1000 << endl;
	system("pause");
	return 0;
}


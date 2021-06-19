#include "saq.h"
using namespace std;



//saq::saq()
//{
//	this->ans = nullptr;
//}
int saq::earnPoint()
{
	if (ans == question::getCorrect_ans())
		return question::getScore();
	else
		return 0;
		
}
string saq::getAns()
{
	return this->ans;
}
void saq::setAns(string ans)
{
	this->ans = ans;
}

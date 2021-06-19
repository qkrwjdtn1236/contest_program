#include "mcq.h"
#include <string>
using namespace std;

/*mcq::mcq()
{
	this.ans = null;
	for (int i = 0; i < sizeof(this->choice_list) / 8; i++)
	{
		this->choice_list[i] = nullptr;
	}
}*/
int mcq::earnPoint()
{
	if (ans == stoi(question::getCorrect_ans()))
		return question::getScore();
	else
		return 0;
}
int mcq::getAns()
{
	return this->ans;
}
void mcq::setAns(int num)
{
	this->ans = num;
}
void mcq::setChoice_list(string text, int index)
{
	this->choice_list[index] = text;
}
string mcq::getChoice_list(int index)
{
	return choice_list[index];
}

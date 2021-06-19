#pragma once
#ifndef MCQ_H
#define MCQ_H
#include <string>
#include "question.h"
using namespace std;
class mcq : public question
{
private:
	int ans = NULL;
	string choice_list[4];
public:
	/*mcq();*/
	int earnPoint();
	int getAns();
	void setAns(int num);
	void setChoice_list(string text, int index);
	string getChoice_list(int index);
};
#endif // !question_H
#pragma once
#ifndef SAQ_H
#define SAQ_H


#include "question.h"

#include <string>
using namespace std;
class saq : public question
{
private:
	string ans;
	
public:
	/*saq();*/
	int earnPoint();
	string getAns();
	void setAns(string ans);
};
#endif // !question_H
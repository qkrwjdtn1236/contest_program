#pragma once
#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
#include <string>
using namespace std;

class question
{
private:
	string problem;
	string correct_ans;
	int score;

public:
	/*question();*/
	string getProblem();
	string getCorrect_ans();
	int getScore();

	void setProblem(string problem);
	void setCorrect_ans(string correct_ans);
	void setScore(int score);
};
#endif // DEBUG
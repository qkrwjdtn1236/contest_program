#include "question.h"
#include <iostream>
using namespace std;



//question::question()
//{
//	this->problem = nullptr;
//	this->correct_ans = nullptr;
//	this->score = NULL;
//}
string question::getProblem()
{
	return this->problem;
}
string question::getCorrect_ans()
{
	return this->correct_ans;
}
int question::getScore()
{
	return this->score;
}


void question::setProblem(string problem)
{
	this->problem = problem;
}
void question::setCorrect_ans(string correct_ans)
{
	this->correct_ans = correct_ans;
}
void question::setScore(int score)
{
	this->score = score;
}

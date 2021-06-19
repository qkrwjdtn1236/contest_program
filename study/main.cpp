#include <iostream>
#include <string>
#include "mcq.h"
#include "saq.h"
using namespace std;

void start();
void noQuestion();
void noContest();
mcq question1[4] = { mcq(),mcq() ,mcq() ,mcq() };
saq question2[2] = { saq(),saq() };
bool haveQuestion = false;
bool contestOver = false;

int main()
{
	
	int inputNum;
	
	while (true)
	{
		start();
		cin >> inputNum;
		
		switch (inputNum)
		{
		case 1:
			cout << "==객관식 4문항에 대한 출제입니다==" << endl;
			for (int i = 1; i <= 4; i++)
			{
				string text;
				cout << i << "번 문제를 입력해주세요" << endl;
				cin >> text;
				question1[i-1].setProblem(text);
				for (int j = 0; j < 4; j++)
				{
					string answer;
					cout << (j+1)<<"번째 보기를 입력해주세요 : ";
					cin >> answer;
					question1[i-1].setChoice_list(answer, j);
				}
				string result;
				cout << "답을 입력해주세요 : ";
				cin >> result;
				question1[i-1].setCorrect_ans(result);
				cout << "배점을 입력해주세요 : ";
				int score;
				cin >> score;
				question1[i-1].setScore(score);
				cout << "----------" << endl;
			}
			cout << "==주관식 2문항에 대한 출제입니다==" << endl;
			for (int i = 1; i <= 2; i++)
			{
				cout << (i+4) << "번 문제를 입력해주세요" << endl;
				string text;
				cin >> text;
				question2[i-1].setProblem(text);
				cout << "답을 입력해주세요 : ";
				string result;
				cin >> result;
				question2[i-1].setCorrect_ans(result);
				cout << "배점을 입력해주세요 : ";
				int score;
				cin >> score;
				question2[i-1].setScore(score);
				cout << "----------" << endl;
			}
			haveQuestion = true;
			break;
		case 2:
			if (!haveQuestion)
			{
				noQuestion();
				continue;
			}
			cout << "시험을 시작합니다.====================" << endl;
			for (int i = 1; i <= 6; i++)
			{
				cout << i << "번 문제입니다." << endl;
				//cout << question1[i-1].getAns() << endl;
				
				if (i <= 4) 
				{
					cout <<  question1[i - 1].getProblem() << endl;
					for (int j = 0; j < 4; j++)
					{
						cout << j + 1 << ". " << question1[i - 1].getChoice_list(j) << endl;
					}
					cout << "답 : ";
					
					int result;
					cin >> result;
					question1[i-1].setAns(result);
					
				}
				else 
				{
					cout << question2[i - 5].getProblem() << endl;
					cout << "답 : ";
					
					string result;
					cin >> result;
					question2[i-5].setAns(result);
				}
				
				
				if (i <= 5)
					cout << "====================" << endl;
				else
					cout << "시험을 종료합니다." << endl;
			}
			contestOver = true;
			break;
		case 3:
		{
			if (!contestOver)
			{
				noContest();
				continue;
			}
			cout << "채점을 시작합니다" << endl;
			int score = 0;
			for (int i = 1; i <= 6; i++)
			{
				cout << i << "번 문제 : ";
				if (i <= 4)
				{
					if (question1[i - 1].getAns() == stoi(question1[i - 1].getCorrect_ans()))
					{
						cout << "O" << endl;

					}
					else
					{
						cout << "X" << endl;
					}
					score += question1[i-1].earnPoint();
				}
				else
				{
					if (question2[i -5].getAns() == question2[i-5].getCorrect_ans())
						cout << "O" << endl;
					else
						cout << "X" << endl;
					score += question2[i-5].earnPoint();
				}
			}
			cout << "총 점수 : " << score << endl;

			break;
		}
		case 4:
			return 0;
			break;
		default:
			cout << "입력 다시 해주세요." << endl;
			continue;
		}
	}

}

void start()
{
	cout << "1. 문제출제 ";
	cout << "2. 문제풀기 ";
	cout << "3. 문제채점 및 성적표 출력 ";
	cout << "4. 프로그램 종료"<<endl;
	cout << "메뉴를 선택해주세요 : ";
}
void noQuestion()
{
	cout << "출제된 문제가 없습니다. 문제를 출제해주세요." << endl;
}
void noContest()
{
	cout << "제출된답안지가 없습니다. 문제를 풀어주세요." << endl;
}

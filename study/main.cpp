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
			cout << "==������ 4���׿� ���� �����Դϴ�==" << endl;
			for (int i = 1; i <= 4; i++)
			{
				string text;
				cout << i << "�� ������ �Է����ּ���" << endl;
				cin >> text;
				question1[i-1].setProblem(text);
				for (int j = 0; j < 4; j++)
				{
					string answer;
					cout << (j+1)<<"��° ���⸦ �Է����ּ��� : ";
					cin >> answer;
					question1[i-1].setChoice_list(answer, j);
				}
				string result;
				cout << "���� �Է����ּ��� : ";
				cin >> result;
				question1[i-1].setCorrect_ans(result);
				cout << "������ �Է����ּ��� : ";
				int score;
				cin >> score;
				question1[i-1].setScore(score);
				cout << "----------" << endl;
			}
			cout << "==�ְ��� 2���׿� ���� �����Դϴ�==" << endl;
			for (int i = 1; i <= 2; i++)
			{
				cout << (i+4) << "�� ������ �Է����ּ���" << endl;
				string text;
				cin >> text;
				question2[i-1].setProblem(text);
				cout << "���� �Է����ּ��� : ";
				string result;
				cin >> result;
				question2[i-1].setCorrect_ans(result);
				cout << "������ �Է����ּ��� : ";
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
			cout << "������ �����մϴ�.====================" << endl;
			for (int i = 1; i <= 6; i++)
			{
				cout << i << "�� �����Դϴ�." << endl;
				//cout << question1[i-1].getAns() << endl;
				
				if (i <= 4) 
				{
					cout <<  question1[i - 1].getProblem() << endl;
					for (int j = 0; j < 4; j++)
					{
						cout << j + 1 << ". " << question1[i - 1].getChoice_list(j) << endl;
					}
					cout << "�� : ";
					
					int result;
					cin >> result;
					question1[i-1].setAns(result);
					
				}
				else 
				{
					cout << question2[i - 5].getProblem() << endl;
					cout << "�� : ";
					
					string result;
					cin >> result;
					question2[i-5].setAns(result);
				}
				
				
				if (i <= 5)
					cout << "====================" << endl;
				else
					cout << "������ �����մϴ�." << endl;
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
			cout << "ä���� �����մϴ�" << endl;
			int score = 0;
			for (int i = 1; i <= 6; i++)
			{
				cout << i << "�� ���� : ";
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
			cout << "�� ���� : " << score << endl;

			break;
		}
		case 4:
			return 0;
			break;
		default:
			cout << "�Է� �ٽ� ���ּ���." << endl;
			continue;
		}
	}

}

void start()
{
	cout << "1. �������� ";
	cout << "2. ����Ǯ�� ";
	cout << "3. ����ä�� �� ����ǥ ��� ";
	cout << "4. ���α׷� ����"<<endl;
	cout << "�޴��� �������ּ��� : ";
}
void noQuestion()
{
	cout << "������ ������ �����ϴ�. ������ �������ּ���." << endl;
}
void noContest()
{
	cout << "����ȴ������ �����ϴ�. ������ Ǯ���ּ���." << endl;
}

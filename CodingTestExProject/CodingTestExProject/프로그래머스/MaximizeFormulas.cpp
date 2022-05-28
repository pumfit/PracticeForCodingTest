/*
수식 최대화
2020 카카오 인턴십

문제
https://yabmoons.tistory.com/687

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

순열 정리
https://www.notion.so/BT-Permutation-a8fc859b11714a0686c7ee6b6f2f1414

해설
https://tech.kakao.com/2017/11/14/kakao-blind-recruitment-round-3/
*순열...이거 맞나 엄청 헤매어서 엄청 오래 걸리고 수식을 어떻게 계산할 것인가에 대한 아이디어가 딱 떠오르 지않고 구현하다가 어쩌지 싶었다.
도움 받은 글은 아래
https://yabmoons.tistory.com/687
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long Calculate(long long N1, long long N2, char Op)
{
	if (Op == '*')
		return N1 * N2;
	if (Op == '+')
		return N1 + N2;
	if (Op == '-')
		return N1 - N2;
	else
		return 0;
}

long long solution(string expression) {
	long long answer = 0;
	vector<char> charOperation = { '+','-','*' };
	vector<char> oper;
	vector<long long> number;
	int sIdx = 0;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
		{
			oper.push_back(expression[i]);
			string num = expression.substr(sIdx, i - sIdx);
			number.push_back(stoi(num));
			sIdx = i + 1;
		}
	}
	string num = expression.substr(sIdx, expression.size() - sIdx);
	number.push_back(stoi(num));
	vector<int> v = { 0,1,2 };
	do {
		long long calNum = 0;
		vector<char> tempOper = oper;
		vector<long long> tempNum = number;
		for (int i = 0; i < 3; i++)
		{
			char curChar = charOperation[v[i]];
			for (int j = 0; j < tempOper.size(); j++)
			{
				if (tempOper[j] != curChar)
					continue;
				calNum = Calculate(tempNum[j], tempNum[j + 1], curChar);
				tempNum[j] = calNum;
				tempNum.erase(tempNum.begin() + j + 1);
				tempOper.erase(tempOper.begin() + j);
				j--;

			}
		}
		answer = max(answer, abs(tempNum[0]));
	} while (next_permutation(v.begin(), v.end()));
	return answer;
}
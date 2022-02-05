/*
다트 게임
2018 KAKAO BLIND RECRUITMENT

문제
https://programmers.co.kr/learn/courses/30/lessons/17682

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

해설
https://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/
*/
#include <string>
#include <stack>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	stack<int> s;
	for (int i = 0; i < dartResult.size(); i += 2)
	{
		int score = dartResult[i] - '0';
		if (score == 1 && dartResult[i + 1] == '0')
		{
			score = 10;
			i++;
		}
		char bonus = dartResult[i + 1];
		if (bonus == 'D')
		{
			score *= score;
		}
		else if (bonus == 'T')
		{
			score = (score*score*score);
		}
		s.push(score);
		if (i + 2 < dartResult.size())
		{
			if (dartResult[i + 2] == '*')
			{
				int x = 0, y = 0;
				if (!s.empty())
				{
					x = s.top();
					s.pop();
				}
				if (!s.empty())
				{
					y = s.top();
					s.pop();
				}
				if (y != 0)
					s.push(y * 2);
				if (x != 0)
					s.push(x * 2);
				i++;
			}
			else if (dartResult[i + 2] == '#')
			{
				int x = 0;
				if (!s.empty())
				{
					x = s.top();
					s.pop();
				}
				s.push(x*-1);
				i++;
			}
		}
	}
	while (!s.empty())
	{
		answer += s.top();
		s.pop();
	}
	return answer;
}
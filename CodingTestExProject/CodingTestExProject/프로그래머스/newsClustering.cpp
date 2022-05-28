/*
[1차] 뉴스 클러스터링
2018 KAKAO BLIND RECRUITMENT

문제
https://programmers.co.kr/learn/courses/30/lessons/1829

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

*묘하게 오래걸렸던 문제 double 형 floor 함수 범위 주의
*/
#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

bool isAlphabet(string s) {
	if ((('a' <= s[0] && s[0] <= 'z') || ('A' <= s[0] && s[0] <= 'Z')) &&
		(('a' <= s[1] && s[1] <= 'z') || ('A' <= s[1] && s[1] <= 'Z')))
		return true;
	else
		return false;
}

int solution(string str1, string str2) {
	int answer = 0;
	double cnt = 0;
	map<string, int> m;
	for (int i = 0; i < str1.size() - 1; i++)
	{
		string s = str1.substr(i, 2);
		if (!isAlphabet(s))
			continue;
		cnt++;
		string sub = "";
		sub.push_back(tolower(s[0]));
		sub.push_back(tolower(s[1]));
		if (m.find(sub) == m.end())
			m.insert({ sub,1 });
		else
			m[sub]++;
	}
	double sum = 0;
	for (int i = 0; i < str2.size() - 1; i++)
	{
		string s = str2.substr(i, 2);
		if (!isAlphabet(s))
			continue;
		string sub = "";
		sub.push_back(tolower(s[0]));
		sub.push_back(tolower(s[1]));
		if (m.find(sub) != m.end())
		{
			if (m[sub] > 0)
			{
				sum++;
				m[sub]--;
			}
			else
				cnt++;
		}
		else
		{
			cnt++;
		}
	}
	double d = cnt == 0 ? 1 : (sum / cnt);
	answer = floor(d * 65536);
	return answer;
}
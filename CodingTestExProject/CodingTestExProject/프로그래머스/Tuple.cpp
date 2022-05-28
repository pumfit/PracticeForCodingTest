/*
튜플
2019 카카오 개발자 겨울 인턴십

문제
https://programmers.co.kr/learn/courses/30/lessons/64065

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-2%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C
*/
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool comp(pair<int, int> A, pair<int, int> B) {
	return A.second > B.second;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<string> str;
	map<int, int> m;
	int sIdx = 0, eIdx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '{')
		{
			sIdx = i;
		}
		else if (s[i] == '}')
		{
			eIdx = i;
			str.push_back(s.substr(sIdx + 1, eIdx - sIdx - 1));
		}
	}
	str.pop_back();
	for (int i = 0; i < str.size(); i++)
	{
		istringstream ss(str[i]);
		string strBuffer;
		while (getline(ss, strBuffer, ','))
		{
			int num = stoi(strBuffer);
			if (m.find(num) != m.end())
				m[num]++;
			else
				m.insert({ num,1 });
		}
	}
	vector<pair<int, int>> v;
	for (auto i : m)
		v.push_back(i);
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++)
		answer.push_back(v[i].first);

	return answer;
}
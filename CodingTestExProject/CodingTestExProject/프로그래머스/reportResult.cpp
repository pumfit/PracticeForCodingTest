/*
신고 결과 받기
2022 KAKAO BLIND RECRUITMENT

문제
https://programmers.co.kr/learn/courses/30/lessons/92334

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C
*/
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size());
	map<string, int> idx;
	set<int> s[1001];

	for (int i = 0; i < id_list.size(); i++)
		idx[id_list[i]] = i;
	for (int i = 0; i < report.size(); i++)
	{
		int k = report[i].find(" ");
		string user = report[i].substr(0, k);
		string reportUser = report[i].substr(k + 1, report[i].size() - user.size());
		s[idx[reportUser]].insert(idx[user]);
	}
	for (int i = 0; i < id_list.size(); i++)
	{
		if (s[i].size() < k)
			continue;
		for (auto list : s[i])
			answer[list]++;
	}
	return answer;
}
/*
신고 결과 받기
2022 KAKAO BLIND RECRUITMENT

문제
https://programmers.co.kr/learn/courses/30/lessons/92334

풀이 및 공부

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
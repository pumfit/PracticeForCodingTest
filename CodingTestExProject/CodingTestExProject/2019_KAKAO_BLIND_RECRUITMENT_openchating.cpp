/*
문제만 제대로 읽고 파악했어도 빨리 끝낼 수 있었던 문제 
오늘 같이 푼 2998 문제랑 같이 map이랑 string으로 풀 수 있는 문제이다.

string처리 공백문자처리가 어려웠다. substr과 find로 풀이를 진행했다.
find를 쓸 수 있었던건 공백 두번이 필수적으로 나오기 때문에 두번 써서 해결했다.

+)
이때 명령어 Leave의 경우 닉네임이 따로 들어오지 않는 점등을 고려해야한다.
*/
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
//유저 아이디와 닉네임의 길이는 1 이상 10 이하이다.

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;

	for (int i = 0; i < record.size(); i++)
	{
		if (record[i][0] != 'L')
		{
			string id = "";
			string nickname = "";
			if (record[i].find(' '))
			{
				int idx = record[i].find(' ');
				string s = record[i].substr(idx + 1);
				int nidx = s.find(' ');
				id = record[i].substr(idx + 1, nidx);
				nickname = s.substr(nidx + 1);
			}
			m[id] = nickname;
		}
	}
	for (int i = 0; i < record.size(); i++)
	{
		string id = "";
		if (record[i].find(' '))
		{
			int idx = record[i].find(' ');
			string s = record[i].substr(idx + 1);
			int nidx = s.find(' ');
			id = record[i].substr(idx + 1, nidx);
		}
		if (record[i][0] == 'L')
		{
			answer.push_back(m.find(id)->second + "님이 나갔습니다.");
		}
		else if (record[i][0] == 'E')
		{
			answer.push_back(m.find(id)->second + "님이 들어왔습니다.");
		}
	}
	return answer;
}
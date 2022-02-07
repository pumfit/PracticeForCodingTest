/*
신규 아이디 추천
2021 KAKAO BLIND RECRUITMENT

문제
https://programmers.co.kr/learn/courses/30/lessons/72410

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

*/
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";
	for (int i = 0; i < new_id.size(); i++) // step. 1
	{
		if ('A' <= new_id[i] && new_id[i] <= 'Z')
			new_id[i] = tolower(new_id[i]);
	}

	for (int i = 0; i < new_id.size(); i++) // step. 2
	{
		if (('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
			answer.push_back(new_id[i]);
	}

	string temp = "";// step. 3
	for (int i = 0; i < answer.size(); i++)
	{
		temp.push_back(answer[i]);
		if (answer[i] == '.')
		{
			while (true)
			{
				if (answer[i + 1] == '.')
				{
					i++;
				}
				else
				{
					break;
				}
			}
		}
	}
	answer = temp;

	if (answer[0] == '.') // step. 4
		answer = answer.erase(0, 1);
	if (answer[answer.size() - 1] == '.')
		answer = answer.erase(answer.size() - 1, 1);

	if (answer.size() == 0) // step. 5
		answer.push_back('a');

	if (answer.size() > 15) // step. 6
		answer = answer.substr(0, 15);
	if (answer[answer.size() - 1] == '.')
		answer = answer.erase(answer.size() - 1, 1);

	if (answer.size() < 3) // step. 7
	{
		char c = answer[answer.size() - 1];
		while (answer.size() < 3)
		{
			answer.push_back(c);
		}
	}
	return answer;
}
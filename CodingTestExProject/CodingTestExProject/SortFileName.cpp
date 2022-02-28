/*
[3차] 파일명 정렬
2018 KAKAO BLIND RECRUITMENT

문제
https://programmers.co.kr/learn/courses/30/lessons/17686

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

해설
https://tech.kakao.com/2017/11/14/kakao-blind-recruitment-round-3/
*처음엔 쉽다 생각했는데 생각보다 오래걸린 문제 stable_sort가 기본 상식...
중간에 구조체에서 number를 int로 받았다가 이후에 반환할때 0 빠져서 애먹었다.
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct file {
	string head;
	string number;
	string tail;
};

string toLower(string s) {
	string low = "";
	for (int i = 0; i < s.size(); i++)
		low.push_back(tolower(s[i]));
	return low;
}

bool compare(file A, file B)
{
	string a = toLower(A.head);
	string b = toLower(B.head);
	if (a < b)
		return true;
	else if (a > b)
	{
		return false;
	}
	else {
		return stoi(A.number) < stoi(B.number);
	}
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<file> v;
	for (int i = 0; i < files.size(); i++)
	{
		bool isFirst = true;
		int idx = 0, cnt = 0;
		for (int j = 0; j < files[i].size(); j++)
		{
			if ('0' <= files[i][j] && files[i][j] <= '9')
			{
				if (isFirst)
				{
					isFirst = false;
					idx = j;
				}
				cnt++;
			}
		}
		int size = files[i].size();
		file f;
		f.head = files[i].substr(0, idx);
		f.number = files[i].substr(idx, cnt);
		f.tail = files[i].substr(idx + cnt, size - idx - cnt);
		v.push_back(f);
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
	{
		string s = v[i].head + v[i].number + v[i].tail;
		answer.push_back(s);
	}
	return answer;
}
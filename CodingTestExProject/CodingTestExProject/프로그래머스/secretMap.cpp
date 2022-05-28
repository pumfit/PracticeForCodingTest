/*
비밀지도
2018 KAKAO BLIND RECRUITMENT

문제
https://programmers.co.kr/learn/courses/30/lessons/17681

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

해설
https://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/
*/
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++)
	{
		string s1 = "";
		string s2 = "";
		int temp1 = arr1[i], temp2 = arr2[i];
		for (int j = 0; j < n; j++)
		{
			if (temp1 / 2 > 0)
			{
				s1 += temp1 % 2 + '0';
				temp1 /= 2;
			}
			else
			{
				s1 += temp1 + '0';
				temp1 /= 2;
			}

		}
		for (int j = 0; j < n; j++)
		{
			if (temp2 / 2 > 0)
			{
				s2 += temp2 % 2 + '0';
				temp2 /= 2;
			}
			else
			{
				s2 += temp2 + '0';
				temp2 /= 2;
			}
		}
		string ans = "";
		for (int i = n - 1; i >= 0; i--)
		{
			if (s1[i] == '0'&&s2[i] == '0')
				ans += " ";
			else
				ans += "#";
		}
		answer.push_back(ans);
	}
	return answer;
}
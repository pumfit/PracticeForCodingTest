/*
1141 접두사

접두사X 집합이란 집합의 어떤 한 단어가, 다른 단어의 접두어가 되지 않는 집합이다. 예를 들어, {hello}, {hello, goodbye, giant, hi}, 비어있는 집합은 모두 접두사X 집합이다. 하지만, {hello, hell}, {giant, gig, g}는 접두사X 집합이 아니다.

단어 N개로 이루어진 집합이 주어질 때, 접두사X 집합인 부분집합의 최대 크기를 출력하시오.
https://www.acmicpc.net/problem/1141

풀긴했지만 찝찝한 문제 뭔가 더 좋은 풀이 방향이 있을 것 같다.
내가 접두사가 되면 제외하면 되는 로직이다.
문자열을 vector로 받아와 정렬을 한 뒤 i번째는 i+1부터 접두사가 되는 지 확인해본다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	int ans = v.size();
	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 0;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i][0] != v[j][0])//첫 문자가 다른 경우 break
				break;
			else
			{
				bool isPre = true;//접두사 인지 판단
				for (int k = 0; k < v[i].size(); k++)
				{
					if (v[i][k] != v[j][k])
					{
						isPre = false;
						break;
					}
				}
				if (isPre)
					cnt++;//접두사 개수
			}
		}
		if (cnt > 0)
			ans--;//접두사가 존재하는 경우 제외
	}
	cout << ans;
	return 0;
}
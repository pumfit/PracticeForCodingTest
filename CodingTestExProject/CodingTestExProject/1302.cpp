/*
1302 베스트 셀러

김형택은 탑문고의 직원이다. 김형택은 계산대에서 계산을 하는 직원이다. 김형택은 그날 근무가 끝난 후에, 오늘 판매한 책의 제목을 보면서 가장 많이 팔린 책의 제목을 칠판에 써놓는 일도 같이 하고 있다.

오늘 하루 동안 팔린 책의 제목이 입력으로 들어왔을 때, 가장 많이 팔린 책의 제목을 출력하는 프로그램을 작성하시오.
https://www.acmicpc.net/problem/1302

맵 활용 문제

맵 써본적이 별로 없지만 이와 같은 문제에서는 유용하게 쓸 수 있다.
(문자열 관련 문제에서 잘 나오는 기법)
맵의 key값은 오름차순으로 정렬되며 value를 정렬하기 위해선 sort함수의 세번째 인자값을 활용하면 된다.
https://0xd00d00.github.io/2021/08/22/map_value_reverse.html

map 이용시
https://kimcoder.tistory.com/122
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<string, int> m;
	int arr[1001] = { 0, };
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (m.find(s) == m.end())
			m.insert({ s,1 });
		else
			m[s]++;
	}
	int max = 0;
	string ans = "";
	for (auto i : m)
	{
		if (max < i.second)
		{
			max = i.second;
			ans = i.first;
		}
	}
	cout << ans;
	return 0;
}
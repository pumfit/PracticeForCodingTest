/*
1159 농구 경기

국가대표팀의 감독이 된 이후에 상근이는 매우 게을러졌다. 
그는 선수의 이름을 기억하지 못하고, 각 선수의 능력도 알지 못한다. 
따라서, 누가 선발인지 기억하기 쉽게 하기 위해 성의 첫 글자가 같은 선수 5명을 선발하려고 한다.
만약, 성의 첫 글자가 같은 선수가 5명보다 적다면, 상근이는 내일 있을 친선 경기를 기권하려고 한다.

상근이는 내일 경기를 위해 뽑을 수 있는 성의 첫 글자를 모두 구해보려고 한다.

첫째 줄에 선수의 수 N (1 ≤ N ≤ 150)이 주어진다. 다음 N개 줄에는 각 선수의 성이 주어진다. (성은 알파벳 소문자로만 이루어져 있고, 최대 30글자이다)

printf로 아스키코드값을 사용해 문자 출력할 수 있는것을 이번 문제로 알았다.
+)printf_s가 백준 내에선 컴파일에러가 발생하니 주의
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	bool isBool = false;
	cin >> N;

	int arr[26] = { 0, };

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		arr[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] >= 5)
		{
			printf_s("%c", i+'a');
			isBool = true;
		}
	}
	if (!isBool)
		cout << "PREDAJA";
}
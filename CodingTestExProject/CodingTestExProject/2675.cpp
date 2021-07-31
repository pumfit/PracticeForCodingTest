/*
2675 문자열 반복

문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오.

문자열을 받아오고 반복횟수만큼 반복문을 사용해주면 풀 수 있는 문제이다.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		string s;
		string ans = "";
		cin >> N >> s;
		for (int j = 0; j < s.length(); j++)
		{
			for (int k = 0; k < N; k++)
			{
				ans += s[j];
			}
		}
		cout << ans << endl;
	}
}
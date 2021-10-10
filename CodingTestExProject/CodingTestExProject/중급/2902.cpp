/*
2902 KMP는 왜 KMP일까?

문자열을 받아와 하이픈의 위치를 파악하고 대문자만 출력하는 문제
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "", a = "";
	cin >> s;
	a.push_back(s[0]);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - '-' == 0)
		{
			a.push_back(s[i + 1]);
		}
	}
	cout << a;
	return 0;
}
/*
5397 키로거

창영이는 강산이의 비밀번호를 훔치기 위해서 강산이가 사용하는 컴퓨터에 키로거를 설치했다. 
며칠을 기다린 끝에 창영이는 강산이가 비밀번호 창에 입력하는 글자를 얻어냈다.

키로거는 사용자가 키보드를 누른 명령을 모두 기록한다. 
따라서, 강산이가 비밀번호를 입력할 때, 화살표나 백스페이스를 입력해도 정확한 비밀번호를 알아낼 수 있다.

강산이가 비밀번호 창에서 입력한 키가 주어졌을 때, 강산이의 비밀번호를 알아내는 프로그램을 작성하시오. 
강산이는 키보드로 입력한 키는 알파벳 대문자, 소문자, 숫자, 백스페이스, 화살표이다.

https://www.acmicpc.net/problem/5397

iterator 예외처리를 제대로 하지않은 경우 런타임 에러가 뜨는데 BOJ에 이유가 뜨지 않아서 해맸다.
예제의 경우  쉽게 통과되기 때문에 %--를 해본 경우 런타임에러가 떴고 erase시 str.begin()인지 확인을 해주어 예외처리를 해주어 통과했다.
*/
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		vector<char> l;
		list<char> str;
		for (int j = 0; j < s.size(); j++)
		{
			l.push_back(s[j]);
		}
		list<char>::iterator iter = str.end();
		for (int j = 0; j < l.size(); j++)
		{
			if (l[j] == '<')
			{
				if (iter != str.begin())
					iter--;
			}
			else if (l[j] == '>')
			{
				if (iter != str.end())
					iter++;
			}
			else if (l[j] == '-')
			{
				if (iter != str.begin())
					iter = str.erase(--iter);
			}
			else
			{
				str.insert(iter, s[j]);
			}
		}
		for (auto i : str)
			cout << i;
		cout << endl;
	}
	return 0;
}
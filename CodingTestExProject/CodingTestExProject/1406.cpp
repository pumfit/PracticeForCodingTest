/*
1406 에디터

한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.

이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.

이 편집기가 지원하는 명령어는 다음과 같다.
...

https://www.acmicpc.net/problem/1406

이중 연결 리스트로 이루어진 stl list에대해 공부해보았다.
또한 iterator의 사용 방식에 대해 좀 더 익힐 수 있었다. 문제에 제시된 조건들을 iter에 대한 조건으로 적절히 걸어 구현해주면 쉽게 동작되었다.
가장 막혔던 부분은 erase()함수 였는데 해당 함수는 리턴값으로 iterator를 가져와 수행 이후 iter값을 지정해줘야한다.
https://hugssy.tistory.com/217

*/
#include <iostream>
#include <list>
using namespace std;

int main() {
	list<char> l;
	string s; int n;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		l.push_back(s[i]);
	cin >> n;
	list<char>::iterator iter = l.end();
	for (int i = 0; i < n; i++)
	{
		char command;
		cin >> command;
		if (command == 'L')
		{
			if (iter != l.begin())
				iter--;
		}
		else if (command == 'D')
		{
			if (iter != l.end())
				iter++;
		}
		else if (command == 'B')
		{
			if (iter != l.begin())
			{
				iter = l.erase(--iter);
			}

		}
		else if (command == 'P')
		{
			char c;
			cin >> c;
			l.insert(iter, c);
		}
	}
	for (auto c : l)
		cout << c;

	return 0;
}
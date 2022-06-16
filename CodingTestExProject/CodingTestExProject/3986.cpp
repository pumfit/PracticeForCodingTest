/*
3986 좋은 단어
https://www.acmicpc.net/problem/3986

평석이는 단어 위로 아치형 곡선을 그어 같은 글자끼리(A는 A끼리, B는 B끼리) 쌍을 짓기로 하였다. 
만약 선끼리 교차하지 않으면서 각 글자를 정확히 한 개의 다른 위치에 있는 같은 글자와 짝 지을수 있다면, 그 단어는 '좋은 단어'이다. 평석이가 '좋은 단어' 개수를 세는 것을 도와주자.


간단한 스택문제 괄호 유형처럼 맞는 짝을 찾아주는 수고가 없어도 된다.
top이 같은 경우에 뽑아주기만 하면 되는 문제라 더 쉽다.
만약 스택이 비어있다면 좋은 단어가 된다.

좀더 간결한 풀이
			if (stk.size() && stk.top() == index) 
				stk.pop();
			else 
				stk.push(index);
스택이 비어있지 않다는 것을 stk.size()로 판단해서 조건을 달아주니 조건문이 이중으로 되지않는다.
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int answer = 0;
	while (T--)
	{
		string str;
		cin >> str;
		stack<int> s;
		for (int i = 0; i < str.size(); i++)
		{
			if (s.empty())
				s.push(str[i]);
			else
			{
				if (s.top() == str[i])
				{
					s.pop();
				}
				else
				{
					s.push(str[i]);
				}
			}
		}
		if (s.empty())
			answer++;
	}
	cout << answer;
	return 0;
}
/*
4949 균형잡힌 세상

스택의 활용 영상보고 올바른 괄호가 되는 경우의 개념만 알고 문제풀이를 진행했다.
가장먼저 스택을 만들고 여는 괄호가 들어오는 경우에는 스택에 넣었다.
그리고 닫는 괄호일때
1) 해당 스택이 비었는가
2) 닫는 괄호가 잘못되었는가 를 판단했고
이 둘이 아닌 경우 pop()을 진행했다.

그리고 마지막에 모든 문자열을 순회한 후 스택이 비었다면 균형잡힌 문자열로 판단해주었다.

+) 한줄 씩 입력받는 getline(cin,str);은 항상 까먹는 것 같다..잊지말자
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (true)
	{
		string str;
		string ans = "";
		getline(cin, str);
		if (str[0] == '.' && str.size() == 1)
			return 0;
		stack<char> s;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (s.empty() || s.top() == '[')
				{
					ans = "no";
					break;
				}
				else if (s.top() == '(')
					s.pop();
			}
			else if (str[i] == ']')
			{
				if (s.empty() || s.top() == '(')
				{
					ans = "no";
					break;
				}
				else if (s.top() == '[')
					s.pop();
			}
		}
		if (ans != "no")
		{
			if (s.empty())
				ans = "yes";
			else
				ans = "no";
		}

		cout << ans << endl;
	}
	return 0;
}
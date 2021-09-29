/*
9012 괄호

괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.

의외로 맞고 나서 보니 짧은 코드였다.
예제 입력 2번의 예외처리로 조금 걸렸던 문제인데 ())(()의 경우 a-- a++ 의 경우 괄호가 역 표시 된 경우를
예외처리하지 못했다. 이를 해결하기 위해 27번 라인의 a값 범위를 설정하여 문제를 해결하였다.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a = 0;
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (a >= 0)
			{
				if (s[j] == '(')
				{
					a++;
				}
				else if (s[j] == ')')
				{
					a--;
				}
			}
		}
		if (a == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
	return 0;
}
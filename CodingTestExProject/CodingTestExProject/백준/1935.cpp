/*
1935 후위 표기식

첫째 줄에 피연산자의 개수(1 ≤ N ≤ 26) 가 주어진다. 그리고 둘째 줄에는 후위 표기식이 주어진다. (여기서 피연산자는 A~Z의 영대문자이며, A부터 순서대로 N개의 영대문자만이 사용되며, 길이는 100을 넘지 않는다) 그리고 셋째 줄부터 N+2번째 줄까지는 각 피연산자에 대응하는 값이 주어진다. 3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B에 해당하는값 , 5번째 줄에는 C ...이 주어진다, 
그리고 피연산자에 대응 하는 값은 100보다 작거나 같은 자연수이다.
후위 표기식을 앞에서부터 계산했을 때, 식의 결과와 중간 결과가 -20억보다 크거나 같고, 20억보다 작거나 같은 입력만 주어진다.
https://www.acmicpc.net/problem/1935

이전에 실패했던 이유는 else 문에서 cin으로 숫자를 받아주었는데 이렇게 진행하면 테케 이외의 AAB 같은 수를 못 받아온다
오랫만에 표기법 하니까 다 까먹어서 표기법 관련 정리할 포스트
https://www.notion.so/9407165018eb49a99ba6c7d859cc16d8

*C++ cout출력 소숫점 자리수 정하는 방식
cout<<fixed;
cout.precision(자리수);
*/
#include <iostream>
#include <stack>
using namespace std;


int main() {
	int N;
	string s;
	cin >> N >> s;
	int number[26] = { 0, };
	stack<double> num;

	for (int i = 0; i < N; i++)
		cin >> number[i];

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+')
		{
			double A = num.top();
			num.pop();
			double B = num.top();
			num.pop();
			num.push(B + A);
		}
		else if (s[i] == '-')
		{
			double A = num.top();
			num.pop();
			double B = num.top();
			num.pop();
			num.push(B - A);
		}
		else if (s[i] == '*')
		{
			double A = num.top();
			num.pop();
			double B = num.top();
			num.pop();
			num.push(B*A);
		}
		else if (s[i] == '/')
		{
			double A = num.top();
			num.pop();
			double B = num.top();
			num.pop();
			num.push(B / A);
		}
		else {
			num.push(number[s[i] - 'A']);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << num.top();
	return 0;
}
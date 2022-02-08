/*
1541 잃어버린 괄호

https://www.acmicpc.net/problem/1541

세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

문자열+스택(괄호)
스택 순서대로 -가 나올때까지의 합을 가지고있다가 빼주면 된다.
이것보다 문자열 처리하는데 더 걸린 것 같다.
연산자가 나오는 경우 substr을 사용해 잘라내 주었고 마지막 수의 경우 따로 넣어줬다.

생각보다 substr써서 보다 isidigit로 num = num * 10 + (str[i] - '0'); 식으로 계산하는게 많이 보였다. (이 방식은pass)

연산자아닌 경우 string으로 더해서 처리하는 간단한 풀이 굳이 stack안쓰고 로직 순서만 잘 쓰면 이렇게도 풀 수 있구나
https://scarlettb.tistory.com/64
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<string> arr;
	int sIdx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-' || s[i] == '+')
		{
			string c = "";
			c += s[i];
			arr.push(s.substr(sIdx, i - sIdx));
			arr.push(c);
			sIdx = i + 1;
		}
	}
	arr.push(s.substr(sIdx, s.size() - sIdx));
	int ans = 0;
	int tempSum = 0;
	while (!arr.empty())
	{
		string c = arr.top();
		arr.pop();
		if (c == "-")
		{
			ans -= tempSum;
			tempSum = 0;
		}
		else if (c != "+")
		{
			tempSum += stoi(c);
		}
	}
	ans += tempSum;
	cout << ans;
	return 0;
}
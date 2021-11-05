/*
10826 피보나치 수 4

10000까지라서 큰 수의 합을 계산하여
string연산이 필요하다.

char -> int 방법하고 올림 처리 방식 처리를
string 연산으로 사용하여야 한다.

*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string num[10001];

string sum(string s1, string s2)
{

	string answer = "";
	int num = 0, carry = 0;

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	for (int i = 0; i < s1.size(); i++)
		s2 += "0";

	for (int i = 0; i < s1.size(); i++)
	{
		num = (s1[i] - '0' + s2[i] - '0' + carry) % 10;
		answer += to_string(num);
		carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
	}
	if (carry != 0)
		answer += to_string(carry);
	reverse(answer.begin(), answer.end());
	return answer;
}

int main() {
	int N;
	cin >> N;
	num[0] = '0'; num[1] = '1';
	for (int i = 2; i <= N; i++)
		num[i] = sum(num[i - 1], num[i - 2]);
	cout << num[N];
	return 0;
}
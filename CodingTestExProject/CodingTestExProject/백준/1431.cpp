/*
1431 시리얼 번호

다솜이는 기타를 많이 가지고 있다. 그리고 각각의 기타는 모두 다른 시리얼 번호를 가지고 있다. 다솜이는 기타를 빨리 찾아서 빨리 사람들에게 연주해주기 위해서 기타를 시리얼 번호 순서대로 정렬하고자 한다.

모든 시리얼 번호는 알파벳 대문자 (A-Z)와 숫자 (0-9)로 이루어져 있다.

시리얼번호 A가 시리얼번호 B의 앞에 오는 경우는 다음과 같다.

A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
시리얼이 주어졌을 때, 정렬해서 출력하는 프로그램을 작성하시오.

https://www.acmicpc.net/problem/1431

sort compare 함수 이용해서 빠르게 풀 수 있는 문제 수의 합을 구하는 방식은 isdigit를 사용하여 숫자합을 반환하는 함수로 구현했다.

그리고 초반에 if else if로 반환했는데 그럴 필요없이 조건을 "두 문자의 길이가 같지 않다면"
if(lena != lenb) 
	return lena < lenb;
이런 식으로 조건을 달아 수정하는게 더욱 깔끔하다
*/
#include <iostream>
#include <algorithm>
using namespace std;

string str[51];

int SumNumber(string& str)
{
	int n = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			n += (str[i] - '0');
	}
	return n;
}

bool compare(string& A, string& B)
{
	if (A.size() < B.size())
	{
		return true; // A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
	}
	else if (A.size() > B.size())
	{
		return false;
	}
	else {
		int a = SumNumber(A); int b = SumNumber(B);
		if (a < b)//A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. 
			return true;
		else if (a > b)
			return false;
		else
			return A < B;
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];
	sort(str, str + N, compare);
	for (int i = 0; i < N; i++)
		cout << str[i] << '\n';
	return 0;
}
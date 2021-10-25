/*
20757 큰 수 A +B

두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)

A,B 남는 자리에 0처리가 어려웠던 문제
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;


int numA[10001] = { 0, }, numB[10001] = { 0, };
string A, B, temp;
vector<int> v;
int sum = 0;

int main()
{
	cin >> A >> B;
	if (A.size() < B.size())
	{
		temp = A;
		A = B;
		B = temp;
	}
	for (int i = 0; i < A.size(); i++)
		numA[i + 1] = A[i] - '0';

	for (int i = 0; i < B.size(); i++)
		numB[i + 1 + (A.size() - B.size())] = B[i] - '0';

	for (int i = A.size(); i > 0; i--)
	{
		sum = numA[i]+numB[i];
		if (sum >= 10)
		{
			numA[i - 1]++;
			sum -= 10;
		}
		v.push_back(sum);
	}
	if (numA[0] != 0) 
		cout << 1;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i];
	}

}
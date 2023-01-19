/*
1747 소수&팰린드롬
https://www.acmicpc.net/problem/1747

소수 판별시 n = 1 인경우 예외 처리 안해서 한번 틀리고 또 틀리길래 뭐지 했는데 범위를 잘못 설정했다. 
while문 조건을 n 최대로 해둬서 틀림 1000000 일때 1003001 이 답으로 나온다.

*/
#include <iostream>
using namespace std;

bool IsPrime(int n)
{
	if(n==1)
		return false;
		
	for(int i = 2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

bool IsPalindrome(int N)
{
	string s = to_string(N);
	int size = s.size();
	for(int i = 0;i<size/2;i++) 
	{
		if(s[i]!=s[size-i-1])
			return false;
	}
	return true;
}

int main() {
	int N;
	cin>>N;
	while(true)
	{
		if(IsPrime(N)&&IsPalindrome(N))
		{
			cout<<N;
			return 0;
		}
		N++;
	}
	return 0;
}
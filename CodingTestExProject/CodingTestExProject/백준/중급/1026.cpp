/*
1026 보물

sort()함수 사용해서 응용하기
내림차순 오름차순 둘다 할 수 있어야함
greater<int>()사용하는 방법이 제일 쉬운 것 같음
sort(v.begin(),v.end(),greater<int>());
*/

#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

int main()
{
	int n,sum = 0;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> b(n);
	
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		a[i] = k;
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		b[i] = k;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for (int i = 0; i < n; i++)
	{
		sum +=  a[i] * b[i];
	}
	printf("%d", sum);
}
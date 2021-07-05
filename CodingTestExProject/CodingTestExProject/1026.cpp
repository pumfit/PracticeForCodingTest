/*
1026 ����

sort()�Լ� ����ؼ� �����ϱ�
�������� �������� �Ѵ� �� �� �־����
greater<int>()����ϴ� ����� ���� ���� �� ����
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
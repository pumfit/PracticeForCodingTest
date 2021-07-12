/*
1292번 쉽게 푸는 문제
 
 방법1.
 1000까지  배열만들고 받아온 범위만큼 더한다.

vector subscript out of range ->1000
idx 범위 설정문제 for문 배열에 사용되는 변수간의 변화 생각하기

*/

#include<iostream>
using namespace std;

int main()
{
	int arr[1000];
	int sum = 0, idx = 0, num = 1;
	int a, b;

	cin >> a;
	cin >> b;

	for (int i = 0; idx < 1000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[idx++] = num;
			if (idx == 1000)
				break;
		}
		num++;
	}

	for (int k = a-1; k < b; k++) 
	{
		sum += arr[k];
	}
	cout << sum;
}
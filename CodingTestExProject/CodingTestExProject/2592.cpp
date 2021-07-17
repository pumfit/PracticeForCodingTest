/*
2592번 대표값

대표값으로 최빈값과 평균구하기
*/

#include<iostream>

using namespace std;

int main()
{
	int sum=0,max=0,idx=0;
	int num[101] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		int n = 0;
		cin >> n;
		sum += n;
		num[n / 10]++;
	}
	for (int i = 1; i < 101; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			idx = i;
		}

	}
	cout << sum / 10 << endl;
	cout << idx*10;
}
/*
1475 방번호
방번호를 받으면 0~9까지 수가 들어있는 세트가 몇개가 필요한지
배열을 만들고 안에서 예외처리
+
cin,cout 사용보다 #include<stdio.h>를 추가하여 입출력에 scanf()나 printf()사용을
익숙하게 하자

#define  _CRT_SECURE_NO_WARNINGS
scanf unsafe 무시 방법 (출처 : https://hijuworld.tistory.com/47 )

			for (int i = 0; i < 10; i++)
			{
				num[i] = 0;
			}

*/

#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a;
	int ans,max = 0;
	int num[10] = { 0, };

	scanf("%d \n", &a);

	while (a!=0)
	{
		num[a % 10]++;

		a = a / 10;
	}

	if (num[6] > 1 && num[6] / 2 > num[9])
	{
		while (num[6] / 2 >= num[9])
		{
			num[6]--;
			num[9]++;
		}
	}
	if (num[9] > 1 && num[9] / 2 > num[6])
	{
		while (num[9] / 2 >= num[6])
		{
			num[9]--;
			num[6]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
		
	}
	ans = max;
	printf("%d \n", ans);
}
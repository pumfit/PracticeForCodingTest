/*
1316 그룹 단어 체커

이번 카카오 인턴 코딩테스트에 있던 문제랑 비슷한 하위ver 문제같다.

해맸던 부분
1. 배열 초기화 안해서 결과 값 이상하게 나온 점
2. char에서 -'a'로 0부터 값 찾을 때 약간 해맸다. 아스키 코드 A,a값 외우기 A = 65, a = 97

잘못한 부분
1. 어떻게 풀지 생각하면서 int word[]로 개수 체크하면서 해야지 해놓고는 변수를 두개를 만들었다.
제출할 때 사용안한 부분 있는지 확인하자

+ vector< >로 푸는 방법 생각해보고 문제풀이 방식 더 찾아보자
*/

#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	int num = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char s[100];
		int word[26] = {0,};
		int temp = 0;
		scanf("%s", &s);

		for (int j = 0; j < 100; j++)
		{
			int curNum = s[j] - 'a';
			if (curNum >= 0)
			{
				word[curNum]++;
				if (temp != curNum && word[curNum]>1)
				{
					num--;
					break;
				}
			}
			else
			{
				break;
			}
			temp = curNum;
		}
		num++;
	}

	printf("%d", num);
}
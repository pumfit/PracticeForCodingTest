/*
2920 음계

풀이는 먼저 생각한대로 첫 자리로 1,8 분기를 나눠 검사하는 식으로 문제를 풀었고
아닌 경우 flag 역할을 하는 isMixed로 mixed가 출력되게 했다.

짧게 푸는 방법이 더 있을 것 같았는데 이후 다른 풀이를 확인해보니
count 라는 변수를 이용해 +8이면 ascending -8이면 descending 둘다 아니라면 isMixed인 방식이 존재했다.
*/
#include<iostream>
using namespace std;

int main()
{
	int arr[8];
	bool isMixed = true;
	for (int i = 0; i < 8; i++)
	{
		int n;
		cin >> n;
		arr[i] = n;
	}

	if (arr[0] == 1)
	{
		for (int i = 1; i < 8; i++)
		{
			if (arr[i] != i + 1)
			{
				break;
			}else if (i == 7)
			{
				isMixed = false;
				cout << "ascending";
			}
		}
	}
	else if (arr[0] == 8)
	{
		for (int i = 1; i < 8; i++)
		{
			if (arr[i] != 8 - i)
			{
				break;
			}
			else if (i == 7)
			{
				isMixed = false;
				cout << "descending";
			}
		}

	}
	if(isMixed)
		cout << "mixed";
}
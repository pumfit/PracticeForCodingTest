/*
1453번 피시방알바

첫번째 제출 실패 이유 :배열크기
들어오는 배열의 인덱스는 1~100까지임을 유의하여
101로 설정하던 받아온 b를 -1을 해주는 과정이 필요하다.
*/

#include<iostream>

using namespace std;

int main()
{
	int n = 0, ans = 0;
	int arr[101] = {0,};
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		if (arr[b] > 0)
		{
			ans++;
		}
		arr[b]++;

	}
	cout << ans;
}
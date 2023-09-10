/*
1037번 약수

1.문제 이해하기
2.문제 제약조건 파악하기
문제 조건
N은 항상 32비트 부호있는 정수로 표현할 수 있다. -> long int
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	long int ans = 1;
	vector<int> arr;

	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		int b;
		cin >> b;
		arr.push_back(b);
	}

	sort(arr.begin(), arr.end());

	ans = arr[0] * arr[a - 1];
	cout << ans;
}
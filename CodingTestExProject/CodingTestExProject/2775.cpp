/*
2775 부녀회장이 될테야

이 아파트에 거주를 하려면 조건이 있는데,
"a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 
사람들의 수의 합만큼 사람들을 데려와 살아야 한다" 는 계약 조항을 꼭 지키고 들어와야 한다.

아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을 때, 
주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하라. 

단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.

단,으로 주어진 제한점에 포인트를 주어 재귀함수로 구현하였다.
재귀함수는 현재층 i-1호와 아래층의 합을 리턴하면 된다.

*/

#include<iostream>
using namespace std;

int sum(int k, int n)// k층 n호
{
	if (n == 1)
		return 1;
	if (k == 0)
		return n;
	return sum(k - 1, n) + sum(k, n - 1);
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int k, n;
		cin >> k >> n;
		cout<< sum(k, n)<<endl;
	}
}
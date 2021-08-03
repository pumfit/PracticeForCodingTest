/*
2845 파티가 끝나고 난 뒤

첫째 줄에 1m2당 사람의 수 L (1 ≤ L ≤ 10)과 파티가 열렸던 곳의 넓이 P (1 ≤ P ≤ 1000)가 주어진다.
둘째 줄에는 각 기사에 실려있는 참가자의 수가 주어진다. 106보다 작은 양의 정수 5개가 주어진다.

간단한 문제라 풀이없이 지나간다.
*/

#include<iostream>
using namespace std;

int main()
{
	int L, P;
	cin >> L >> P;
	int K = L * P;
	for(int i = 0; i < 5; i++)
	{
		int N;
		cin >> N;
		cout << N - K << " ";
	}
}
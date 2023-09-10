/*
1233 주사위

내가 생각한 풀이
배열로 지정해서 모든 경우의 수를 구해 전체 합 배열에서 최대값을 구한다.
배열의 최대가 정해져있어 시간 제한은 넘지 않을 것 같다고 생각했다.

풀면서 다른 풀이가 있지 않을까? 생각도 들었지만 이후 찾아보니 완전 탐색이 맞는 결과였다.
생각한 풀이대로 해보고 되지 않으면 다른 풀이를 생각하자 

+) 이상한 곳에서 많이 틀렸던문제
max값이 인덱스값이 되어야해서 arr[max]와  arr[i]를 비교해야하는데
max와 arr[i]를 비교했고 이 경우 테스트 케이스 답이 나와서 그냥 제출해버렸었다.
비교대상을 명확히 할 것!!
*/
#include <iostream>
using namespace std;

int main()
{
	int s1[21] = {0,}, s2[21] = { 0, }, s3[41] = { 0, };
	int arr[81] = {0,};
	int max = 0;
	int N, M, L;

	cin >> N >> M >> L;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 1; k <= L; k++)
			{
				arr[i + j + k]++;
			}
		}
	}

	for (int i = 3; i < 81; i++)
	{
		if(arr[max]<arr[i])
			max = i;
	}

	cout << max;
}
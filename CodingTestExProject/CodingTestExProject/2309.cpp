/*
2309 일곱 난쟁이

생각보다 많이 어려웠던 문제 어떻게 이렇게 문제 풀이를 생각하는 건지 너무 신기하다.
BF지만 생각하기 어려웠다.
BF로 풀어야겠다 -> 100이되는 전체를 구하기엔 반복문이 너무 많이 필요
->  전체 합을 구한 후 나머지 둘을 선택해서 빼면 되겠다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[9] = { 0, };
int visited[9] = { 0, };
int sum = 0;

int main() {
	for (int i = 0; i < 9; i++)
	{
		int N;
		cin >> N;
		arr[i] = N;
		sum += N;
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j)
						continue;
					cout << arr[k] << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}
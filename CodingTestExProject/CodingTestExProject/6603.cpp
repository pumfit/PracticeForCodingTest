/*
6603 로또

독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.
로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.
예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.

n개 중 6개의 인덱스를 구하면 되는 문제이고
visited만 체크하고 풀면
답이 되지않는 값들은 다음 값들이 이전 값보다 큰 것을 확인 할 수 있는데 이는 인덱스로 비교할 수 없으므로
출력시에 배열을 확인하면서 그 다음 값이 더 큰지 확인한다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[15] = { 0, };
int ans[15] = { 0, };
int visited[15] = { 0, };

void bf(int idx) {
	if (idx == 6)
	{
		bool flag = true;
		int tmp = -1;
		//이전 수가 더 큰 경우는 제외한다.
		for (int i = 0; i < 6; i++)
		{
			if (tmp > arr[ans[i]])
				flag = false;
			tmp = arr[ans[i]];
		}
		if (flag) {
			for (int i = 0; i < 6; i++)
			{
				cout << arr[ans[i]] << " ";
			}
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			ans[idx] = i;
			bf(idx + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	while (true)
	{
		cin >> n;
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		memset(visited, 0, sizeof(visited));
		bf(0);
		cout << '\n';
	}
	return 0;
}
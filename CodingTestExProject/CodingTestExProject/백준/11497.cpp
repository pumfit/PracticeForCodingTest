/*
11497 통나무 건너뛰기

처음에 예제를 보고 i와 i-2가 관계가 있다는 것은 알고
정렬 후 가장 큰값과 세번째로 큰 값을 뺀 값을 정답으로 출력하였다.
예제의 경우 맞았지만 채점결과는 틀렸다.

i,i-2에 해당되는 간격중 가장 큰 간격을 찾아내는 그리디 문제이다.
따라서 정렬후 반복문을 통해 전체 탐색을 진행하면서 최적해를 찾으면 된다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N;
int arr[10001];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int answer = 0;
		for (int j = 0; j < N; j++)
			cin >> arr[j];
		sort(arr, arr + N);
		for (int j = 0; j < N - 2; j++)
		{
			answer = max(answer, arr[j + 2] - arr[j]);
		}
		cout << answer << endl;
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}
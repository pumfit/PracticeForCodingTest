/*
14569 시간표 짜기
https://www.acmicpc.net/problem/14569

50까지 넘어가서 int로는 불가능할 것이라고 생각이 들어 long long으로 문제풀이를 진행했다.
시간표와 남은 시간을 &연산한 값이 시간표값과 같은 지 비교하면 되는데
이상하게도 마지막 예제가 2가 계속나왔다.

값 출력 시 오버플로우가 발생하는 것을 확인했는데 어디서 발생하는건지 알지 못해 결국 검색을 진행했다.
문제는 비트 합 연산을 진행할때 1<<n 이부분에서 int형이라 41과 같은 값이 들어가면 오버플로가 발생하는 것이였고
이부분을 수정해 통과할 수 있었다.
*/
#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;
	vector<unsigned long long> v;

	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		int n; unsigned long long num = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> n;
			num |= (1ull << n);
		}
		v.push_back(num);
	}
	cin >> M;
	while (M--)
	{
		int K;
		cin >> K;
		int n; unsigned long long left = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> n;
			left |= (1ull << n);
		}
		bool isPossible;
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (v[i] == (v[i] & left))
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
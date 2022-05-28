/*
11652 카드

준규는 숫자 카드 N장을 가지고 있다. 숫자 카드에는 정수가 하나 적혀있는데, 적혀있는 수는 -262보다 크거나 같고, 262보다 작거나 같다.

준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수를 구하는 프로그램을 작성하시오. 만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.

https://www.acmicpc.net/problem/11652

로직은 바로 생각난대로 맞았는데 40번 마지막 수에 대한 처리가 없었던 거랑 num의 범위를 long long으로 지정하지 않았던 것 때문에
거의 10번은 제출 후 틀린 문제
해당 문제는 map으로도 풀 수 있을 것 같아서 이후 풀이 추가를 해보면 좋을 것 같다.


*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
long long arr[100005] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int cnt = 0, maxCnt = 0;
	long long num = -(111 << 62) - 1;
	for (int i = 0; i < N; i++)
	{
		if (i == 0 || arr[i - 1] == arr[i])
			cnt++;
		else
		{
			if (cnt > maxCnt)
			{
				maxCnt = cnt;
				num = arr[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > maxCnt)
		num = arr[N - 1];
	cout << num;
	return 0;
}
/*
* 1806 부분합
* 
처음에 되게 쉬울거라고 예상했다가 되게 시간 오래 걸린문제

초반 조건을 어떻게 잡는지 + 포인터 범위가 넘어가는 경우 어떻게 처리할 지가 중요한 문제이다.
처음엔 직접 써가면서 어떻게  S값보다 큰 범위를 설정하는지 보면 더 쉽게 이해할 수 있다. st 는 순차적으로 증가하고
ed은 S보다 클때까지 계속 증가시킨다. 이때 S보다는 크고 가장 작은 경우 ed는 현재 st +1 에서 이어진다는게 투 포인터 문제의 포인트이다.
계속 이어나가다 ed가 N에 다다르는 순간 종료하면된다. 

뭔가 더 깔끔한 조건이 있을 것 같아서 고민하려다가 강의 보고 정리해보고자 한다.

+) 5퍼대 초반에 틀렸는데 답이 나오지않는 경우에는 0을 출력해야하는 조건을 빼먹어서 였다.
*/
#include <iostream>
using namespace std;

int main() {
	int N, S;
	int arr[100001] = { 0, };
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int sum = arr[0]; int ed = 0;
	int answer = 2e9;
	for (int st = 0; st < N; st++)
	{
		while (true)
		{
			if (sum >= S)
				break;
			ed++;
			sum += arr[ed];
			if (ed == N)
				break;
		}
		if (ed == N)
			break;

		answer = min(answer, ed - st + 1);
		sum -= arr[st];
	}
	if (answer == 2e9)
		cout << 0;
	else
		cout << answer;
	return 0;
}
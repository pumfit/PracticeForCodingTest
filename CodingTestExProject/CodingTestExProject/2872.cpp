/*

2872 우리집엔 도서관이 있어

정렬하는 문제지만 시간내 모두 정렬하지않고 푸는 방법이 있다.
그리디로 푸는 방법으로 해당 문제에 대한 아이디어를 생각해 내기 어려웠다.

해당되는 자리에 있는 경우에는 움직이지 않아도 된다. 다만 순서대로 진행되어야하므로
순서에 맞는 경우에만 체크할 수를 감소하고 맞지않는 경우 답을 증가시킨다.
*/
#include <iostream>
using namespace std;

int N;
int arr[300001];

int main() {
	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int checkN = N;
	for (int i = N - 1; i >= 0; i--)
	{
		if (checkN == arr[i])
		{
			checkN -= 1;
		}
		else
		{
			answer++;
		}
	}
	cout << answer;
	return 0;
}
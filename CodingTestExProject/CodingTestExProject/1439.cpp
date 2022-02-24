/*
1439 뒤집기

다솜이는 0과 1로만 이루어진 문자열 S를 가지고 있다. 다솜이는 이 문자열 S에 있는 모든 숫자를 전부 같게 만들려고 한다. 다솜이가 할 수 있는 행동은 S에서 연속된 하나 이상의 숫자를 잡고 모두 뒤집는 것이다. 뒤집는 것은 1을 0으로, 0을 1로 바꾸는 것을 의미한다.

예를 들어 S=0001100 일 때,

전체를 뒤집으면 1110011이 된다.
4번째 문자부터 5번째 문자까지 뒤집으면 1111111이 되어서 2번 만에 모두 같은 숫자로 만들 수 있다.
하지만, 처음부터 4번째 문자부터 5번째 문자까지 문자를 뒤집으면 한 번에 0000000이 되어서 1번 만에 모두 같은 숫자로 만들 수 있다.

문자열 S가 주어졌을 때, 다솜이가 해야하는 행동의 최소 횟수를 출력하시오.
https://www.acmicpc.net/problem/1439

다른 답 보고 특이했던 점
- 각 값의 차이가 1이므로 두 값을 구한뒤 더 작은 값을 직접 계산하지 않고 28번 라인에서 모든 경우를 더해 나누기 2를 해도 정답이다.
(조금 더 문제의 규칙을 찾아냈다면 생각해봤을 만한 방식이였던 것 같다.)
*/
#include <iostream>
using namespace std;

int main() {

	string s;
	cin >> s;
	int num[2] = { 0, };
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s[i + 1])
		{
			int idx = s[i] - '0';
			num[idx]++;
		}
	}
	int cnt = num[0] > num[1] ? num[1] : num[0];
	cout << cnt;
	return 0;
}
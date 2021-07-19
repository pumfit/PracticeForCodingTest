/*
2959 거북이

"가장 큰 직사각형 만들기"를 4가지 양의 정수로 만드는 거북이 문제
해당 문제의 풀이는 정렬뒤 가장 작은 수와 두번째로 큰 수를 곱하면된다.
(-> 가장 큰 수 ↑가장 작은 수 <- 두번째로 큰수 ↓두번째로 작은 수)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> num(4);

	for (int i = 0; i < 4; i++)
	{
		int N;
		cin >> N;
		num[i] = N;
	}
	sort(num.begin(), num.end());

	cout << num[0] * num[2];
	return 0;
}
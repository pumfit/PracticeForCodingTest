/*
1598 꼬리를 무는 숫자 나열

받아온 숫자 A B를 규칙에 맞게 좌표로 변환한 다음 좌표간 차이를 계산하여 풀이하였다.
(풀이하면서 x랑y값이 바뀌긴 했는데 풀이 자체에 문제는 없어서 이대로 올림 다음부터는 조심)
*/

#include <iostream>
using namespace std;


int main() {
	int A = 0, B = 0;
	cin >> A >> B;
	int ax = 0, ay = 0, bx = 0, by = 0;

	ax = A % 4 == 0 ? A / 4 - 1 : A / 4;
	ay = A % 4 == 0 ? 3 : A % 4 - 1;

	bx = B % 4 == 0 ? B / 4 - 1 : B / 4;
	by = B % 4 == 0 ? 3 : B % 4 - 1;

	int a = ax > bx ? ax - bx : bx - ax;
	int b = ay > by ? ay - by : by - ay;

	cout << a + b;
}
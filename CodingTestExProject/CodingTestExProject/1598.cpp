/*
1598 ������ ���� ���� ����

�޾ƿ� ���� A B�� ��Ģ�� �°� ��ǥ�� ��ȯ�� ���� ��ǥ�� ���̸� ����Ͽ� Ǯ���Ͽ���.
(Ǯ���ϸ鼭 x��y���� �ٲ�� �ߴµ� Ǯ�� ��ü�� ������ ��� �̴�� �ø� �������ʹ� ����)
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
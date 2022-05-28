/*
11005 ���� ��ȯ 2

10���� �� N�� �־�����. �� ���� B�������� �ٲ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
10������ �Ѿ�� ������ ���ڷ� ǥ���� �� ���� �ڸ��� �ִ�. �̷� ��쿡�� ������ ���� ���ĺ� �빮�ڸ� ����Ѵ�.
A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

���� ����� ���ؼ� �ѹ� Ʋ�ȴ�
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B;
	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string answer = "";
	cin >> A >> B;

	while (A > 0)
	{
		answer += A % B < 10 ? A % B + '0' : s[A%B - 10];
		A /= B;
	}
	for (int i = answer.size() - 1; i >= 0; i--)
	{
		cout << answer[i];
	}
	return 0;
}
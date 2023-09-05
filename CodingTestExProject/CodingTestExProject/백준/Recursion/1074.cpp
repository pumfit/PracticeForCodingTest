/*
1074 Z

�Ѽ��� ũ�Ⱑ 2N �� 2N�� 2���� �迭�� Z������� Ž���Ϸ��� �Ѵ�. ���� ���, 2��2�迭�� ���� ��ĭ, ������ ��ĭ, ���� �Ʒ�ĭ, ������ �Ʒ�ĭ ������� �湮�ϸ� Z����̴�.

N > 1�� ���, �迭�� ũ�Ⱑ 2N-1 �� 2N-1�� 4��� �� �Ŀ� ��������� ������� �湮�Ѵ�.

N�� �־����� ��, r�� c���� �� ��°�� �湮�ϴ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

https://www.acmicpc.net/problem/1074

*/
#include <iostream>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1);
	if (r < half && c < half)//1������
		return func(n - 1, r, c);
	if (r < half && c >= half)//2������
		return half * half + func(n - 1, r, c - half);
	if (r >= half && c < half)//3������
		return 2 * half*half + func(n - 1, r - half, c);
	return 3 * half*half + func(n - 1, r - half, c - half);//4������
}

int main(void) {
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}
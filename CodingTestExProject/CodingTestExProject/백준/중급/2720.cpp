/*
2720 ��Ź�� ���� ����

�Ž������� ������ �Ž��� �ִ� ���α׷����� �ϴ� �����̴�.

+) ���� ������ �Ʒ� �������� ���� Don't Look Back In Anger �����鼭 
�뷡 ���������� ������� ���ƴ�. �׷��� �϶�� �־�� ���󰰴�.
*/
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << N / 25 << " ";
		N %= 25;
		cout << N / 10 << " ";
		N %= 10;
		cout << N / 5 << " ";
		cout << N % 5 << endl;
	}
}
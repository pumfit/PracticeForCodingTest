/*

2872 �츮���� �������� �־�

�����ϴ� �������� �ð��� ��� ���������ʰ� Ǫ�� ����� �ִ�.
�׸���� Ǫ�� ������� �ش� ������ ���� ���̵� ������ ���� �������.

�ش�Ǵ� �ڸ��� �ִ� ��쿡�� �������� �ʾƵ� �ȴ�. �ٸ� ������� ����Ǿ���ϹǷ�
������ �´� ��쿡�� üũ�� ���� �����ϰ� �����ʴ� ��� ���� ������Ų��.
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
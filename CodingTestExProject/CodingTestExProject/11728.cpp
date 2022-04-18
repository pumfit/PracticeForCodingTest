/*
11728 �迭 ��ġ��

���ĵǾ��ִ� �� �迭 A�� B�� �־�����. �� �迭�� ��ģ ���� �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� �迭 A�� ũ�� N, �迭 B�� ũ�� M�� �־�����. (1 �� N, M �� 1,000,000)

��° �ٿ��� �迭 A�� ������, ��° �ٿ��� �迭 B�� ������ �־�����. �迭�� ����ִ� ���� ������ 109���� �۰ų� ���� �����̴�.

https://www.acmicpc.net/problem/11728

�ð��ʰ����� �ʰ� �����ϰ� �� �迭�� �ε����� �������ε����� ��� �ٸ� �迭�� ������ ������ �����ϸ� �ȴ�.

����1 ���� ����
https://www.youtube.com/watch?v=59fZkZO0Bo4&ab_channel=BaaarkingDog

*/
#include <iostream>
using namespace std;

int n, m;
int a[1000005], b[1000005], c[2000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int idxA = 0; int idxB = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (idxB == m)//�迭 B�� ��� C�� ���� ��� 
			c[i] = a[idxA++];
		else if (idxA == n)//�迭 A�� ��� C�� ���� ��� 
			c[i] = b[idxB++];
		else if (a[idxA] <= b[idxB])//�迭 A,B�� ���� �� ���� ���� ����
			c[i] = a[idxA++];
		else
			c[i] = b[idxB++];
	}
	for (int i = 0; i < n + m; i++)
		cout << c[i] << " ";
	return 0;
}
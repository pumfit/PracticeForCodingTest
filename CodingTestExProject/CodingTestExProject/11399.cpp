/*
11399 ATM

�������࿡�� ATM�� 1��ۿ� ����. ���� �� ATM�տ� N���� ������� ���� ���ִ�.
����� 1������ N������ ��ȣ�� �Ű��� ������, i�� ����� ���� �����ϴµ� �ɸ��� �ð��� Pi���̴�.
���� �� �ִ� ����� �� N�� �� ����� ���� �����ϴµ� �ɸ��� �ð� Pi�� �־����� ��,
 �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


 �ٸ� Ǯ�̹�
	for (int i = 0; i < N; i++)
		res += P[i] * (N - i);
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int N;
	int sum = 0, answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		answer += sum;
	}
	cout << answer;
	return 0;
}
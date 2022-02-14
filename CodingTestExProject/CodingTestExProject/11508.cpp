/*
11508 2+1����

KSG ������������ ���Ͽ���, �帵ŷ�䱸��Ʈ ���� ����ǰ�� '2+1 ����'�ϴ� ��縦 �ϰ� �ֽ��ϴ�. KSG ���������� ����ǰ 3���� �� ���� ��ٸ� ���߿��� ���� �� ���� ����� �����ϰ� ������ �� ���� ��ǰ ���ݸ� �����ϸ� �˴ϴ�. 
�� ���� 3���� ����ǰ�� ���� �ʴ´ٸ� ���� ���� ������ �����ؾ� �մϴ�.
���� ���, 7���� ����ǰ�� �־ �� ��ǰ�� ������ 10, 9, 4, 2, 6, 4, 3�̰� �����̰� (10, 3, 2), (4, 6, 4), (9)�� �� 3���� ���ļ� ������ ��ٸ� ù ��° �ٷ��̿����� 13����, �� ��° �ٷ��̿����� 10����, �� ��° �ٷ��̿����� 9���� �����ؾ� �մϴ�.
�����̴� KSG ���������� ģ����� ���� ���� �� N���� ����ǰ�� �����Ϸ��� �մϴ�. �����̸� ���� �ּҺ������ ����ǰ�� ������ �� �ֵ��� �����ּ���!

���� ��� �ͺ��� �����ѵ� ���������� �����ϰ� 3���� ���´�. ���� ���� ���� 3��°��
�����Ͽ� ���� ������ָ� �Ǵ� �����̴�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long sum = 0;
	int arr[100001];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<int>());
	for (int i = 0; i < N; i++)
	{
		if ((i + 1) % 3 == 0)
			continue;
		sum += arr[i];
	}

	cout << sum;
	return 0;
}
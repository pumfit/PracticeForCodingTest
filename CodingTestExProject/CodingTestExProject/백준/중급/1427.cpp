/*
1427�� ��Ʈ�λ��̵�

�迭�� ��� ������ �� �ΰ�?
������ ��� : �޾ƿ��� %10���� ������ -> ���� �� �ǵ�����
���� �����ٲٱ�� ����� ������� Ǯ��

�ٸ����: char[]�������� �޾Ƽ� strlen()����ϱ�
+) �Է��̳� ��� Ÿ���� ������ ���� �ʱ� ������ ���ڿ��� �޾Ƶ� �����ϴ�.
�ش� Ǯ�� ��ó : https://aorica.tistory.com/97
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	long int n;
	vector<int> arr;
	int idx = 0;
	
	cin >> n;

	while (n!=0)
	{
		arr.push_back(n % 10);
		n = n / 10;
		idx++;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < idx; i++)
	{
		n *= 10;
		n += arr[idx - i - 1];
	}
	cout << n;
}
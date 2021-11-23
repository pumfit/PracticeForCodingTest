/*
1373 2���� 8����

ó���� 2����->10����->8������ �ٲ���� �����߰�
2������ 3������ ������ 8������ �ٷ� ��ȯ�ߴ��� �����ߴ�.
�� ����� �˰��־��µ� �ٷ� �������� ���ؼ� �ƽ����� ����
�ڸ����� Ŀ�� string,vector�� Ȱ���ؾ��Ѵٴ� ����
reverse�Լ� ������ Ȱ���ؼ� ����� ���ϰ� �ϴ°� ����Ʈ�� ����
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	string s;
	vector<int> v;
	cin >> s;
	reverse(s.begin(), s.end());
	int i = 0;
	while (i < s.size())
	{
		int n = 1;
		int sum = 0;
		while (i < s.size() && n < 8)
		{
			sum += ((s[i] - '0') *n);
			n *= 2;
			i++;
		}
		v.push_back(sum);
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i];

	return 0;
}
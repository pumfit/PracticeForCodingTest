/*
1789 ������ ��

���� �ٸ� N���� �ڿ����� ���� S��� �Ѵ�. S�� �� ��, �ڿ��� N�� �ִ��� ���ϱ�?

���� �ٸ� N���� �ڿ����� �ִ밪���� �������Ƿ� 1���� �����ؾ��ϸ� �ش�Ǵ� S���� 
��� ���ϴٰ� sum�� �ѱ� ��� cnt ������ �ѹ� ���� Ƚ���� �ڿ��� N�� �ִ��� �ȴ�.

for�� �ۿ� i�� ������ i���� cnt�� ���°� �� ȿ������ �� ����.
*/
#include <iostream>
using namespace std;

int main() {
	long long N;
	long long sum = 0;
	int cnt = 0;
	cin >> N;
	for (int i = 1; i < 2e9; i++)
	{
		if (sum > N)
			break;
		sum += i;
		cnt++;
	}
	cout << cnt - 1;
	return 0;
}
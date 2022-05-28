/*
1748 �� �̾� ���� 1

N = 10000000�϶�
Success #stdin #stdout 0s 5636KB
68888897

�±��ߴµ� �̰� bf �³�...?? ��ü Ž���ؼ� Ǭ Ǯ�̴� �¾Ƽ� ���� �� ������ ���� �ϳ��ϳ� Ž���Ѱ� �ƴ� �����̶�
����Ǯ�̰� �´��� �ǹ��� �����.

�׸��� ã�ƺ� �ٸ� Ǯ��

	for(int i=1;i<=n;i*=10){
		result += n - i + 1;
	}
	cout<<result;

�̰� ��¥ bf��...��� ������ ��� Ǯ�̿���.
���� �� ����� Ʋ�� �͵� �ƴϰ� ���� ���� Ȯ���� ������ ���� Ǯ�̸� �����غ��� ���� �߿��� �� ����.
*/
#include <iostream>
using namespace std;

int arr[9] = { 0,9,99,999,9999,99999,999999,9999999,99999999 };

int main() {
	int N = 0;
	cin >> N;
	int tempN = N;
	int sum = 0;
	int i = 0;
	while (tempN / 10 > 0)
	{
		i++;
		tempN /= 10;
	}
	for (int k = i; k >= 0; k--)
	{
		sum += (N - arr[k])*(k + 1);
		N = arr[k];
	}
	if (i == 0)
		sum += N;
	cout << sum;
	return 0;
}
/*
N = 10000000�϶�
Success #stdin #stdout 1.61s 5584KB
68888897

#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	int sum = 0;
	cin >> N;
	while(stoi(N)>0)
	{
		sum += N.size();
		N = to_string(stoi(N)-1);
	}
	cout<<sum;
	return 0;
}
*/
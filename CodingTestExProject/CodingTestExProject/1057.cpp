/*
1057 ��ʸ�Ʈ

�������� N���� �����ϴ� ��Ÿ ��ʸ�Ʈ�� �����ߴ�. ��ʸ�Ʈ�� ������ ���� ����ȴ�. �ϴ� N���� �����ڴ� ��ȣ�� 1������ N������ �����޴´�. �׷��� �� �Ŀ� ���� ������ ��ȣ���� ��Ÿ�� �Ѵ�. �̱� ����� ���� ���忡 �����ϰ�, �� ����� �� ���忡�� ��������. 
���� �� ������ �����ڰ� Ȧ�����̶��, ������ ��ȣ�� ���� �����ڴ� ���� ����� �ڵ� �����Ѵ�. ���� ���忡�� �ٽ� �������� ��ȣ�� 1������ �ű��. �̶�, ��ȣ�� �ű�� ������ ó�� ��ȣ�� ������ �����ϸ鼭 1������ �ű��.
�� ���� 1���� 2���� ��Ÿ�� �ؼ� 1���� �����ϰ�, 3���� 4���� ��Ÿ�� �ؼ� 4���� �����ߴٸ�, 4���� ���� ���忡�� ��ȣ 2���� �����޴´�. ��ȣ�� �ٽ� �������� �Ŀ� �� ���� ���� ������ ���带 ��� �Ѵ�.

��ħ �� ��Ÿ ��ȸ�� ���Ѽ��� �����ߴ�. �������� ���ڱ� ��Ÿ ��ȸ���� ����ϴ� ����� ��������, 
�� ���忡�� ���Ѽ��� ����ϴ��� �ñ�������. �ϴ� �����ΰ� ���Ѽ��� ���� ����ϱ� ������ �׻� �̱�ٰ� �����Ѵ�. 
1 ���忡�� �������� ��ȣ�� ���Ѽ��� ��ȣ�� �־��� ��, ���� �����ΰ� ���Ѽ��� �� ���忡�� ����ϴ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ó���� �迭�� Ǯ�̸� ���������� Ȧ���϶��� ó���� �߸�ó���� ���� ��� -1�� ������ ��찡 �����.
���� �ε��������� Ǯ���ִٴ� ���� �˾Ұ� �̸� �Ǵ��Ͽ� ������ Ǯ����.
*/
#include <iostream>
using namespace std;

int N, A, B;

int main() {
	int round = 0;
	cin >> N >> A >> B;
	if (N < A || N < B) {
		round = -1;
	}
	else
	{
		while (A != B)
		{
			round++;
			A = (A + 1) / 2;
			B = (B + 1) / 2;
		}
	}
	cout << round;
	return 0;
}
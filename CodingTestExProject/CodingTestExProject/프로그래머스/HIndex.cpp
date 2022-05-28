/*
���� H-Index

H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. 
��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.

� �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� 
������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H-Index�Դϴ�.

� �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��,
�� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

https://en.wikipedia.org/wiki/H-index "��Ű���"

�׽�Ʈ ���̽� �߰��غ��� �� Ʋ�ȴ��� �� �� �־��� ���� h�� �� ���õ� �ο� �����
�����ߴµ� �ƴϿ�����.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	for (int i = 0; i < citations.size(); i++)
	{
		for (int h = 0; h <= citations[i]; h++)
		{
			if (h <= citations.size() - i && i <= h)
			{
				int Hidx = h;
				if (answer < Hidx)
					answer = Hidx;
			}
		}


	}
	return answer;
}
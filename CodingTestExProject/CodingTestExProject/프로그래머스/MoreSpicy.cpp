/*
�� �ʰ�

ó���� �ʹ� ������ Ǯ���µ� 
�� �׷��� Ǯ������ �ʿ� �ٸ� ����� ��� ����������??�� ���� �����ϸ� �ٽ� Ǯ�̸� �����ߴ�.

�켱���� ť�� Ȱ���� ����
�켱 ������ �������� �����ϰ� while���� ������ top�� �ִ� ���Ұ� K���� ���� ���
��� �ΰ��� �̾Ƽ� ���� ���� �ٽ� �־��ش�.

+)
priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());
�ʱ�ȭ�� �ݺ��� �����ʰ� �ϴ� ����� �ִٴ°� �ٸ� Ǯ�̷� �˰ԵǾ���.
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);
	while (pq.top() < K)
	{
		int mix = pq.top(); pq.pop();
		if (pq.size() == 0)
			return -1;
		mix += pq.top() * 2; pq.pop();
		pq.push(mix);
		answer++;
	}
	return answer;
}
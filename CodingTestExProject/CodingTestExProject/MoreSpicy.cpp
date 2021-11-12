/*
더 맵게

처음에 너무 더럽게 풀었는데 
왜 그렇게 풀었는지 필요 다른 사람은 어떻게 접근했을까??에 대해 생각하며 다시 풀이를 진행했다.

우선순위 큐를 활용한 문제
우선 순위를 역순으로 저장하고 while문의 조건은 top에 있는 원소가 K보다 작을 경우
계속 두개를 뽑아서 섞은 값을 다시 넣어준다.

+)
priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());
초기화를 반복문 쓰지않고 하는 방법이 있다는걸 다른 풀이로 알게되었다.
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
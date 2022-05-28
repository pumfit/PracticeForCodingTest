/*
타겟넘버

dfs 풀이

재귀를 이용한 풀이로
문제에 맞게 모든 수를 사용하며 합이 타겟이 되었는지 판단해서
개수를 세는 방식으로 문제풀이를 진행했다. 다른 풀이도 살펴보니 내 풀이와는 달라서
해당되는 문제 풀이를 여럿 찾아봐야할 것 같다.
*/

#include <string>
#include <vector>

using namespace std;

int t = 0, cnt = 0;

void dfs(vector<int> nums, int idx, int sum)
{
	int ps = sum + nums[idx];
	int ns = sum - nums[idx];
	if (idx + 1 < nums.size())
	{
		dfs(nums, idx + 1, ps);
		dfs(nums, idx + 1, ns);
	}
	if ((ps == t || ns == t) && idx == nums.size() - 1)
		cnt++;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	t = target;
	dfs(numbers, 0, 0);
	answer = cnt;
	return answer;
}
/*
Ÿ�ٳѹ�

dfs Ǯ��

��͸� �̿��� Ǯ�̷�
������ �°� ��� ���� ����ϸ� ���� Ÿ���� �Ǿ����� �Ǵ��ؼ�
������ ���� ������� ����Ǯ�̸� �����ߴ�. �ٸ� Ǯ�̵� ���캸�� �� Ǯ�̿ʹ� �޶�
�ش�Ǵ� ���� Ǯ�̸� ���� ã�ƺ����� �� ����.
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
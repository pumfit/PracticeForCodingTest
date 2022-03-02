#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	map<int, int> m;
	int get = 0, zero = 0;
	for (int i = 0; i < win_nums.size(); i++)
		m.insert({ win_nums[i],0 });
	for (int i = 0; i < lottos.size(); i++)
	{
		if (lottos[i] == 0)
		{
			zero++;
			continue;
		}
		if (m.find(lottos[i]) != m.end())
			get++;
	}
	int maxRank = win_nums.size() - (get + zero) + 1;
	if (maxRank == 7)
		maxRank--;
	answer.push_back(maxRank);
	int minRank = win_nums.size() - get + 1 > zero ? win_nums.size() - get + 1 : zero;
	if (minRank == 7)
		minRank--;
	answer.push_back(minRank);
	return answer;
}
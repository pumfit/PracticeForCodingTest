#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;
	for (int i = 0; i < sizes.size(); i++)
	{
		if (sizes[i][0] > sizes[i][1])//앞자리에 큰수로
		{
			int temp = sizes[i][0];
			sizes[i][0] = sizes[i][1];
			sizes[i][1] = temp;
		}
	}
	int maxX = 0, maxY = 0;
	for (int i = 0; i < sizes.size(); i++)
	{
		if (sizes[i][0] > maxX)
			maxX = sizes[i][0];
		if (sizes[i][1] > maxY)
			maxY = sizes[i][1];
	}
	answer = maxX * maxY;
	return answer;
}
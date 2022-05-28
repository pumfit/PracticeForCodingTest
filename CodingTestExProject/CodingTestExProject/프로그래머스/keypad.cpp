/*
키패드 누르기

구현 문제라서 벡터와 pair사용해 위치에 대하 좌표값을 왼손,오른손 모두 가지고 있게 한 다음
이를 계산하는 방식으로 진행했다.

먼저 1,4,7과 3,6,9의 경우 고정적으로 L과 R을 가져 먼저 처리하고 위치값을 넣어주었고 (생각해보니 이때는 왜 pop_back()안했지)
이 이후의 경우 각 좌표값의 거리를 구해 계산했다.

*/
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	vector<pair<int, int>> v[2];
	v[0].push_back({ 3,0 });
	v[1].push_back({ 3,2 });
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer += "L";
			v[0].push_back({ numbers[i] / 3,0 });
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer += "R";
			v[1].push_back({ numbers[i] / 3 - 1,0 });
		}
		else {
			int x = 1; int y = numbers[i] == 0 ? 3 : numbers[i] / 3;
			if (abs(x - v[0].back().second) + abs(y - v[0].back().first)
				< abs(x - v[1].back().second) + abs(y - v[1].back().first))
			{
				answer += "L";
				v[0].pop_back();
				v[0].push_back({ y,x });
			}
			else if (abs(x - v[0].back().second) + abs(y - v[0].back().first)
				> abs(x - v[1].back().second) + abs(y - v[1].back().first))
			{
				answer += "R";
				v[1].pop_back();
				v[1].push_back({ y,x });
			}
			else {
				if (hand == "left")
				{
					answer += "L";
					v[0].push_back({ y,x });
				}
				else {
					answer += "R";
					v[1].push_back({ y,x });
				}
			}
		}
	}
	return answer;
}
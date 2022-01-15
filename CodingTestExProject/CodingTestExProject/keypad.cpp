/*
Ű�е� ������

���� ������ ���Ϳ� pair����� ��ġ�� ���� ��ǥ���� �޼�,������ ��� ������ �ְ� �� ����
�̸� ����ϴ� ������� �����ߴ�.

���� 1,4,7�� 3,6,9�� ��� ���������� L�� R�� ���� ���� ó���ϰ� ��ġ���� �־��־��� (�����غ��� �̶��� �� pop_back()������)
�� ������ ��� �� ��ǥ���� �Ÿ��� ���� ����ߴ�.

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
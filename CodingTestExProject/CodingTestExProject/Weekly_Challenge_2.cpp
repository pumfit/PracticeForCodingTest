#include <string>
#include <vector>

using namespace std;


string solution(vector<vector<int>> scores) {
	string answer = "";
	for (int i = 0; i < scores.size(); i++)
	{
		int sum = 0, avg = 0;
		int min = scores[0][i], max = 0;
		bool isOverlap = false;
		for (int j = 0; j < scores[i].size(); j++)
		{
			sum += scores[j][i];
			if (min >= scores[j][i])
			{
				min = scores[j][i];
			}
			if (max <= scores[j][i])
			{
				max = scores[j][i];
			}
		}
		if (max == scores[i][i] || min == scores[i][i])//유일성 예외 처리
		{
			for (int k = 0; k < scores.size(); k++)
			{
				if (scores[i][i] == scores[k][i] && i != k)
					isOverlap = true;
			}
			if (!isOverlap)//중복이 아닌 경우
			{
				sum -= scores[i][i];
				avg = sum / (scores.size() - 1);
			}
			else
			{
				avg = sum / scores.size();
			}

		}
		else
		{
			avg = sum / scores.size();
		}
		if (avg >= 90)
		{
			answer += 'A';
		}
		else if (avg >= 80)
		{
			answer += 'B';
		}
		else if (avg >= 70)
		{
			answer += 'C';
		}
		else if (avg >= 50)
		{
			answer += 'D';
		}
		else
		{
			answer += 'F';
		}
	}
	return answer;
}
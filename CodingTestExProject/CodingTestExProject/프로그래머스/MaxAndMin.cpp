/*
�ִ񰪰� �ּڰ�

���ڿ� �ٷ�� ���� stoi�� to_string ������ Ȱ��
*/
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> v;
	int sidx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			v.push_back(stoi(s.substr(sidx, i - sidx)));
			sidx = i + 1;
		}
		else if (i == s.size() - 1)
		{
			v.push_back(stoi(s.substr(sidx)));
		}
	}
	sort(v.begin(), v.end());
	answer = to_string(v[0]) + " " + to_string(v[v.size() - 1]);
	return answer;
}
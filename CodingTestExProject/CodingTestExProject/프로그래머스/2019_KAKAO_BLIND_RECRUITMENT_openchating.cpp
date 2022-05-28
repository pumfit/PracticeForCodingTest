/*
������ ����� �а� �ľ��߾ ���� ���� �� �־��� ���� 
���� ���� Ǭ 2998 ������ ���� map�̶� string���� Ǯ �� �ִ� �����̴�.

stringó�� ���鹮��ó���� �������. substr�� find�� Ǯ�̸� �����ߴ�.
find�� �� �� �־����� ���� �ι��� �ʼ������� ������ ������ �ι� �Ἥ �ذ��ߴ�.

+)
�̶� ��ɾ� Leave�� ��� �г����� ���� ������ �ʴ� ������ ����ؾ��Ѵ�.
*/
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
//���� ���̵�� �г����� ���̴� 1 �̻� 10 �����̴�.

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;

	for (int i = 0; i < record.size(); i++)
	{
		if (record[i][0] != 'L')
		{
			string id = "";
			string nickname = "";
			if (record[i].find(' '))
			{
				int idx = record[i].find(' ');
				string s = record[i].substr(idx + 1);
				int nidx = s.find(' ');
				id = record[i].substr(idx + 1, nidx);
				nickname = s.substr(nidx + 1);
			}
			m[id] = nickname;
		}
	}
	for (int i = 0; i < record.size(); i++)
	{
		string id = "";
		if (record[i].find(' '))
		{
			int idx = record[i].find(' ');
			string s = record[i].substr(idx + 1);
			int nidx = s.find(' ');
			id = record[i].substr(idx + 1, nidx);
		}
		if (record[i][0] == 'L')
		{
			answer.push_back(m.find(id)->second + "���� �������ϴ�.");
		}
		else if (record[i][0] == 'E')
		{
			answer.push_back(m.find(id)->second + "���� ���Խ��ϴ�.");
		}
	}
	return answer;
}
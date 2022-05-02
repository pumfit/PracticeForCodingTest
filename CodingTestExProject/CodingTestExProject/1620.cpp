/*
1620 ���¾� ���ϸ� ������ �̴ټ�

https://www.acmicpc.net/submit/1620/42761045

�̸�->��ȣ, ��ȣ->�̸� ��ȯ�� ���� ���� �ΰ� ����Ͽ���
������ ��� isdigit�� ����� �������� �Ǻ��ߴµ�

���� �ΰ� ������� �ʰ� �Ʒ��� ���� Ǯ ���� �ִ�.(INT -> STRING)�̹Ƿ�
unordered_map<string, int> s2i;
string i2s[100005];
���� isdigit���� ù�ڸ��� �������� �Ǻ��ϸ� �ȴ�.

  for(int i = 1; i <= n; i++){
	cin >> i2s[i]; //i��°�� string�� ����
	s2i[i2s[i]] = i;// string key�� i value�� ����
  }
*/
#include <iostream>
#include <unordered_map>
using namespace std;

bool isNumber(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]) == false)
			return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	unordered_map<int, string> numMap;
	unordered_map<string, int> nameMap;
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		numMap[i + 1] = s;
		nameMap[s] = i + 1;
	}
	while (T--)
	{
		string s;
		cin >> s;
		if (isNumber(s))
		{
			cout << numMap[stoi(s)] << '\n';
		}
		else {
			cout << nameMap[s] << '\n';
		}

	}
	return 0;
}
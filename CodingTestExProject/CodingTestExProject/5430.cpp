/*
5430 AC

https://www.acmicpc.net/problem/5430

3Ʈ���� ����µ� Ʋ�� �������� �ϳ����� �̻��ؼ� ���̰� ���� ����
1. ������ ']' ó���� �߸��ؼ� �迭�� ���� '['�� ����
2. break�� continue�� ��
2���� ���ǹ� ���������� �Ⱥ����� �׷��ٰ� �ص� �ʹ��� �Ǽ�.. ��������
�迭�� �������� �� ����ó�� istringstream�� ��µ� while������ getline�Լ��� ���ٴ°� �ؾ���. ������ ���鼭 ������
(�� ������� �������鼭 ������ �־��� n�� ������� �ʾҴ�.)
������ ���Ƽ� �������µ� ���� ��ü�� ���̶�°� �˰� Ǫ�ϱ� �ٷ� Ǯ� ������ Ǯ �� �־��� �����̴�.
*/
#include <iostream>
#include <sstream>
#include <deque>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		string p;
		string x;
		deque<int> q;
		cin >> p >> n >> x;
		x = x.substr(1, x.size() - 2);
		istringstream ss(x);
		string s;
		while (getline(ss, s, ','))
		{
			q.push_back(stoi(s));
		}
		bool isFront = true;
		bool isError = false;
		for (int i = 0; i < p.size(); i++)
		{

			if (p[i] == 'R')
			{
				if (isFront)
				{
					isFront = false;
				}
				else {
					isFront = true;
				}
			}
			else {
				if (q.empty())
				{
					isError = true;
					cout << "error" << '\n';
					break;
				}
				else {
					if (isFront) {
						q.pop_front();
					}
					else {
						q.pop_back();
					}
				}
			}
		}
		if (!isError)
		{
			cout << '[';
			if (isFront)
			{
				for (int i = 0; i < q.size(); i++)
				{
					if (i == q.size() - 1)
						cout << q[i];
					else
						cout << q[i] << ',';
				}

			}
			else {
				for (int i = q.size() - 1; i >= 0; i--)
				{
					if (i == 0)
						cout << q[i];
					else
						cout << q[i] << ',';
				}

			}
			cout << ']' << '\n';
		}
	}

	return 0;
}
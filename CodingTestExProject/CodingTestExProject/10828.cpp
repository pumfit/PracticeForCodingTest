/*
10828 ����

���� ���� ����

���ñ��� ���� ó���� ��� ���� �ϴٰ� ���� ã�ƺ��� index�� �����ϴ� ���� ���ö� ���� �� �� �־���

topindex�� ������ ������ �����ϸ�ȴ�. 
���� �ڷᱸ�� �� ���� ������ �Լ��� ���� ������ �⺻  c++�Լ��� �� Ȯ���ص���

+)
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

����� �ӵ� ���� �ܿ�� Ȱ���ϱ�
*/
#include <iostream>
#include <string>
using namespace std;

int arr[10001];
int idx = -1;

void push(int n)
{
	idx++;
	arr[idx] = n;
}

void pop()
{
	if (idx >= 0)
	{
		cout << arr[idx] << endl;
		idx--;
	}
	else
	{
		cout << "-1" << endl;
	}
}

void size()
{
	cout << idx + 1 << endl;
}

void empty()
{
	if (idx >= 0)
	{
		cout << "0" << endl;
	}
	else
	{
		cout << "1" << endl;
	}
}

void top()
{
	if (idx < 0)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << arr[idx] << endl;
	}

}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int n;
			cin >> n;
			push(n);
		}
		else if (s == "pop")
		{
			pop();
		}
		else if (s == "size")
		{
			size();
		}
		else if (s == "empty")
		{
			empty();
		}
		else if (s == "top")
		{
			top();
		}
	}
	return 0;
}
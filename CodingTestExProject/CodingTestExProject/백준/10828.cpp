/*
10828 스택

스택 구현 문제

스택구현 가장 처음엔 어떻게 하지 하다가 글을 찾아보고 index로 접근하는 것이 떠올라서 구현 할 수 있었음

topindex를 변수로 가지고 진행하면된다. 
정말 자료구조 중 가장 쉬운편 함수도 별로 없으니 기본  c++함수들 다 확인해두자

+)
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

입출력 속도 관련 외우고 활용하기
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
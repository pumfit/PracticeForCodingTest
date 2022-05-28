/*
10866 ��
������ �����ϴ� ��(Deque)�� ������ ����, 
�Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

����->ť->�� ������ ���� ��
���� ���� �˾ƺ��Ҵ�. ���Ϳ� ���� 

��ó : https://velog.io/@daeho-park/C-%EB%B0%B0%EC%97%B4%EB%A1%9C-%EA%B5%AC%ED%98%84%ED%95%9C-%EB%8D%B1Deque
*/
#include <iostream>
#include <string>
using namespace std;

class Deque
{
private:
	int arr[10001];
	int cur_size = 0;
	int rear_idx = 1;
	int front_idx = 0;
public:
	void push_back(int n);
	void push_front(int n);
	void pop_front();
	void pop_back();
	int size();
	bool empty();
	void front();
	void back();
};

void Deque::push_back(int n)
{
	arr[rear_idx] = n;
	rear_idx = (rear_idx + 1) % 10001;
	cur_size++;
}
void Deque::push_front(int n)
{
	arr[front_idx] = n;
	front_idx = ((front_idx - 1) + 10001) % 10001;
	cur_size++;
}
void Deque::pop_front()
{
	if (empty())
		cout << "-1" << endl;
	else
	{
		front();
		front_idx = (front_idx + 1) % 10001;
		cur_size--;
	}
}
void Deque::pop_back()
{
	if (empty())
		cout << "-1" << endl;
	else
	{
		back();
		rear_idx = ((rear_idx - 1) + 10001) % 10001;
		cur_size--;
	}
}
int Deque::size()
{
	return cur_size;
}
bool Deque::empty()
{
	return cur_size == 0;
}
void Deque::front()
{
	if (empty())
		cout << "-1" << endl;
	else
	{
		int temp_idx = (front_idx + 1) % 10001;
		cout << arr[temp_idx] << endl;
	}
}
void Deque::back()
{
	if (empty())
		cout << "-1" << endl;
	else
	{
		int temp_idx = ((rear_idx - 1) + 10001) % 10001;
		cout << arr[temp_idx] << endl;
	}
}

int main() {
	int N;
	Deque d;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "push_back")
		{
			int n;
			cin >> n;
			d.push_back(n);
		}
		else if (s == "push_front")
		{
			int n;
			cin >> n;
			d.push_front(n);
		}
		else if (s == "pop_front")
		{
			d.pop_front();
		}
		else if (s == "pop_back")
		{
			d.pop_back();
		}
		else if (s == "size")
		{
			cout << d.size() << endl;
		}
		else if (s == "empty")
		{
			if (d.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (s == "front")
		{
			d.front();
		}
		else if (s == "back")
		{
			d.back();
		}
	}
	return 0;
}
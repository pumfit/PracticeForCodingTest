/*
10866 덱
정수를 저장하는 덱(Deque)를 구현한 다음, 
입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

스택->큐->덱 순서로 구현 중
덱에 대해 알아보았다. 벡터와 덱의 

출처 : https://velog.io/@daeho-park/C-%EB%B0%B0%EC%97%B4%EB%A1%9C-%EA%B5%AC%ED%98%84%ED%95%9C-%EB%8D%B1Deque
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
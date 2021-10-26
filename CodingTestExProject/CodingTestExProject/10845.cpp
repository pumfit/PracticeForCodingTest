/*
10845 큐

STL 큐를 쓰는 방법도 있지만 큐 자체를 이해하기 위해 구현으로 풀었다. 포인터 방식과 라운드 큐방식 중 라운드 큐를 선택하여 구현했고
해당 구현으로 메모리 2024kb 시간은 344ms 결과가 나왔다.

놀랍게도 구현 다해놓고 반복문안에 큐를 생성해서 계속 재생성되는 바람에
안되가지고 삽질을 엄청 오래했다...오랫만에 클래스도 써보고 구조 생각하며 예외처리하면서 
"모든 제어 경로에서 값을 반환하지는 않습니다." 경고문구에 대해서도 알게되었다.
*/
#include<iostream>
#include<string>
using namespace std;

const int MAX = 10001;

class Queue 
{
private:
	int top;
	int rear;
	int data[MAX];
public:
	Queue()
	{
		top = 0;
		rear = 0;
	}
	bool empty()
	{
		if (top == rear)
			return true;
		else
			return false;
	}
	void push(int x)
	{
		rear = (rear + 1) % MAX;
		data[rear] = x;
	}
	int pop()
	{
		if (!empty())
		{
			top = (top + 1) % MAX;
			return data[top];
		}
		else
			return -1;
	}
	int size()
	{
		return (rear - top + MAX) % MAX;
	}
	int front()
	{
		if (!empty())
			return data[(top + 1) % MAX];
		else
			return -1;
	}
	int back()
	{
		if (!empty())
			return data[rear];
		else
			return -1;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	Queue q;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		
		if (s == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (s == "pop")
		{
			cout << q.pop() << endl;
		}
		else if (s == "size")
		{
			cout << q.size() << endl;
		}
		else if (s == "empty")
		{
			cout << q.empty() << endl;
		}
		else if (s == "front")
		{
			cout<<q.front()<<endl;
		}
		else if (s == "back")
		{
			cout << q.back() << endl;
		}
	}
}
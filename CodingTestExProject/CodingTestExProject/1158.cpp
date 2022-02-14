/*
1158 �似Ǫ�� ����

1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����. ���� ������� K��° ����� �����Ѵ�. �� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������. �� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. ������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. ���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.

N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� �� �˾Ҵµ� ������� ����
ó���� ���ͷ� Ǯ���� �õ��ߴٰ� �����ߴ�. �ش� ����Ǯ�� ������ ������ �����ϰ� �ٽ� Ǯ������� �� ����.
ť�� �̿��� Ǯ�̰� �������̶� �ش� Ǯ�̸� �����ߴ�.

220214
STL list�� ���� ���Ḯ��Ʈ�� ����� Ǯ�̸� �Ʒ��� ���� Ǯ���Ͽ���.
�� ��� ����� �߸��ؼ� �ѹ� Ʋ�ȴ�.
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	queue<int> q;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		q.push(i);
	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < K - 1; i++)//K-1��ŭ ������ �ѱ��
		{
			q.push(q.front());
			q.pop();
		}
		if (q.size() == 1) {
			cout << q.front() << ">";
			q.pop();
		}
		else {
			cout << q.front() << ", ";
			q.pop();
		}

	}
	return 0;
}

/*
#include <iostream>
#include <list>
using namespace std;

int main() {
	int N,K;
	cin>>N>>K;
	list<int> l;
	for(int i=0;i<N;i++)
		l.push_back(i+1);
	list<int>::iterator iter = l.begin();
	cout<<"<";
	while(true)
	{
		if(l.size()==1)
			break;
		for(int i=0;i<K-1;i++)
		{
			iter++;
			if(iter==l.end())
				iter = l.begin();

		}
		cout<<*iter<<", ";
		iter = l.erase(iter);
		if(iter==l.end())
			iter = l.begin();

	}
	cout<<*l.begin();
	cout<<">";
	return 0;
}
*/
/*
2230 ������
https://www.acmicpc.net/problem/2230

�̺�Ž��, �� ������ ����

ó���� �̺�Ž������ Ǯ������ 15%���� Ʋ���� ���� �߸��Ȱ��� �;���
�� ������ Ǯ�̷� Ǯ��鼭 Out of Index ���� �� ���� ��ģ �Ŀ��� �Ȱ��� 15%���� Ʋ�Ⱦ���.

�� �� �信�� �ٸ� ���� ã�ƺ��� ó�� �ּҰ� �ʱ�ȭ ���� 0x7fffffff �� ���Ѱ� �ٸ��ٴ� ���� �˾Ƴ´�.
�������� max�� �ʱ�ȭ�Ҷ� 1e9�� ����µ� �̺��� ū �ּҰ��� ���ɿ� �� �̰� ������ Ʋ�� ���� �ֱ��� �;���.
�̺�Ž�� Ǯ�̵� �ٽ� ���� 1e9 -> 2e9�� ��ġ�� ����ߴ�.

���� ��ü�� �̺�Ž���̶� �� ������ ��� Ǯ��� ���� ������ �� ����.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int>v;
	int N, M;
	cin >> N >> M;
	int n = 0, answer = 0x7fffffff, en = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int st = 0; st < N; st++)
	{
		while (en < N && v[en] - v[st] < M)
			en++;
		if (en == N)//en ������ N���� Ŀ���� ��쿡�� ����
			break;

		answer = min(answer, v[en] - v[st]);

	}
	cout << answer;

	return 0;
}

/*
�̺�Ž�� lower_bound ���
- ���Ŀ� �̺�Ž�� ���� �������� �ٽ� Ǯ��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int>v;
	int N,M;
	cin>>N>>M;
	int n=0,answer=2e9;
	while(N--)
	{
		cin>>n;
		v.push_back(n);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<v.size();i++)
	{
		int index = lower_bound(v.begin(), v.end(), v[i] + M) - v.begin();
		int value = v[index] - v[i];
		if(value>=M)
			answer = min(answer,value);
	}
	cout<<answer;

	return 0;
}
*/
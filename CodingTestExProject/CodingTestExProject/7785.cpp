/*
7785 ȸ�翡 �ִ� ���

�� Ǯ�� set/rbegin(),rend()����
�ݴ�� ����ϴ� �κп��� �ָԾ��µ� ã�ƺ��� rbegin(),rend()�� ���� �˰� �Ǿ �ش� ������� Ǯ��Ҵ�.
for (auto it = s.end(); it != s.begin(); it--)

���ͷ� unorder_set�� �����ͼ� �����ϰ� ����ϴ� ����� �Ʒ� ���ǿ��� Ȯ���ߴ�.
https://www.youtube.com/watch?v=1-k-D2AYY0I&ab_channel=BaaarkingDog
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	set<string> s;
	cin >> N;
	while (N > 0)
	{
		N--;
		string name, state;
		cin >> name >> state;
		if (state == "enter")
			s.insert(name);
		else
			s.erase(name);
	}
	for (auto it = s.rbegin(); it != s.rend(); it++)
		cout << *it << '\n';
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	unordered_set<string> s;
	cin>>N;
	while(N>0)
	{
		N--;
		string name,state;
		cin>>name>>state;
		if(state=="enter")
			s.insert(name);
		else
			s.erase(name);
	}
	vector<string> v(s.begin(),s.end());
	sort(v.begin(),v.end(),greater<string>());
	for(auto s:v)
		cout<<s<<'\n';
	return 0;
}
*/
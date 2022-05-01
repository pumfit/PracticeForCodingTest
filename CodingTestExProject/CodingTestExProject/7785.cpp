/*
7785 회사에 있는 사람

내 풀이 set/rbegin(),rend()쓰기
반대로 출력하는 부분에서 애먹었는데 찾아보니 rbegin(),rend()에 대해 알게 되어서 해당 방식으로 풀어보았다.
for (auto it = s.end(); it != s.begin(); it--)

벡터로 unorder_set을 가져와서 정렬하고 출력하는 방식은 아래 강의에서 확인했다.
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
/*
1181단어정렬

중복 체크는 set을 이용했고
sort compare를 활용해 단어를 정렬했다.
set 의 경우 iterator를 사용하지않아서 해당 부분을 어려워 했는데 auto쓰니까 상당히 쉽게 접근이 가능했다.

*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(string A, string B)
{
	if (A.size() < B.size())
		return true;
	else
	{
		if (A.size() == B.size())
			return A < B;
		else
			return false;
	}

}

int main() {
	int N;
	set<string> s;
	vector<string> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	set<string>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
		v.push_back(*iter);
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(string A,string B)
{
	if(A.size()<B.size())
		return true;
	else
	{
		if(A.size()==B.size())
			return A < B;
		else
			return false;
	}

}

int main() {
	int N;
	set<string> s;
	vector<string> v;
	cin>>N;
	for(int i =0;i<N;i++)
	{
		string str;
		cin>>str;
		s.insert(str);
	}
	for(auto i:s)
		v.push_back(i);
	sort(v.begin(),v.end(),compare);
	for(int i =0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}
*/
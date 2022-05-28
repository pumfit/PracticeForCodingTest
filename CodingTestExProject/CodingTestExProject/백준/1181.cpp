/*
1181�ܾ�����

�ߺ� üũ�� set�� �̿��߰�
sort compare�� Ȱ���� �ܾ �����ߴ�.
set �� ��� iterator�� ��������ʾƼ� �ش� �κ��� ����� �ߴµ� auto���ϱ� ����� ���� ������ �����ߴ�.

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
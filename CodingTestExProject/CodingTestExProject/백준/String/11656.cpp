/*
11656 접미사 배열

https://www.acmicpc.net/problem/11656
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str;
	vector<string> v;
	cin>>str;
	for(int i = 0;i<str.size();i++)
	{
		v.push_back(str.substr(i,str.size()-i));
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<v.size();i++)
		cout<<v[i]<<'\n';
	return 0;
}
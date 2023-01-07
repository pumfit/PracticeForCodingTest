/*
11478 서로 다른 부분 문자열의 개수
https://www.acmicpc.net/source/53638841

중복 제거를 위해 set 
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin>>s;
	set<string> diffSet;
	for(int i = 0; i<s.size(); i++)
	{
		string subStr = "";
		for(int j = i; j<s.size(); j++)
		{
			subStr += s[j];
			diffSet.insert(subStr);
		}
	}
	cout<<diffSet.size();
	return 0;
}
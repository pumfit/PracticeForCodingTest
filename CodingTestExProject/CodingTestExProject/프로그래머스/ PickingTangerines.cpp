/*
귤 고르기
https://school.programmers.co.kr/learn/courses/30/lessons/138476

map value sort : map -> vector -> cmp
cmp 비교함수 사용 시에는 값이 같은 경우에 대해 처리해야함을 잊지말자
*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) 
        return a.first < b.first;
	return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 1;
    map<int,int> m;
    sort(tangerine.begin(),tangerine.end());
    for(int i =0;i<tangerine.size();i++)
        m[tangerine[i]]++;
    vector<pair<int,int>> vec( m.begin(), m.end() );
    sort(vec.begin(), vec.end(), cmp);
    for(int i = vec.size()-1 ;i>=0;i--)
    {
        if(k-vec[i].second<=0)
            break;
        k -= vec[i].second;
        answer++;
    }
    return answer;
}